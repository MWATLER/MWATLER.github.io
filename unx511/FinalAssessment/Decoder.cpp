//Decoder.cpp - Receives and decodes audio packets
//
// 29-Jul-21  M. Watler         Created.

#include <arpa/inet.h>
#include <fcntl.h>
#include <iostream>
#include <net/if.h>
#include <netinet/in.h>
#include <queue>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include "addresses.h"
#include "audio.h"

using namespace std;

const int RECV_LEN=8192;
bool is_running;
struct Address encoder = {
    "127.0.0.1", 1153
//  "192.168.239.132", 1153
};
struct Address decoder;
int decoderNo;
queue<double> audioDelay;

pthread_mutex_t lock_x;

void *recv_func(void *arg);

static void shutdownHandler(int sig)
{
    switch(sig) {
        case SIGINT:
            is_running=false;
            break;
    }
}

int main(int argc, char *argv[])
{
    int fd, ret, len;
    struct sockaddr_in myaddr;
    struct sockaddr_in encaddr;
    socklen_t addrlen = sizeof(encaddr);
    char buf[BUF_LEN];
    const int MYPORT_BASE=1153;

    if(argc!=2) {
        cout<<"usage: Decoder <decoderNo>"<<endl;
        return -1;
    }
    decoderNo=atoi(argv[1]);
    //Intercept ctrl-C
    struct sigaction action;

    action.sa_handler = shutdownHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);
    sprintf(decoder.ip_addr, "127.0.0.1");
//  sprintf(decoder.ip_addr, "192.168.239.128");
    decoder.ip_port=MYPORT_BASE+decoderNo;
    //Question: What is the IP address and port number for decoder 3?

    fd=socket(AF_INET, SOCK_DGRAM, 0);
    if(fd<0) {
        cout<<"Decoder "<<decoderNo<<": Cannot create the socket"<<endl;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    memset((char *)&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    ret = inet_pton(AF_INET, decoder.ip_addr, &myaddr.sin_addr);
    if(ret==0) {
        cout<<"Decoder "<<decoderNo<<": No such address"<<endl;
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }
    myaddr.sin_port = htons(decoder.ip_port);

    //Question: Why does the decoder have to bind itself to an address?
    ret = bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr));
    if(ret<0) {
        cout<<"Decoder "<<decoderNo<<": Cannot bind the socket to the local address"<<endl;
        cout<<strerror(errno)<<endl;
        return -1;
    } else {
#ifdef DEBUG
       cout<<"Decoder "<<decoderNo<<": socket fd:"<<fd<<" bound to address "<<inet_ntoa(myaddr.sin_addr)<<endl;
#endif
    }

    memset((char *)&encaddr, 0, sizeof(encaddr));
    encaddr.sin_family = AF_INET;
    ret = inet_pton(AF_INET, encoder.ip_addr, &encaddr.sin_addr);
    if(ret==0) {
        cout<<"Decoder "<<decoderNo<<": No such address"<<endl;
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }
    encaddr.sin_port = htons(encoder.ip_port);

    pthread_t tid;
    ret = pthread_create(&tid, NULL, recv_func, &fd);
    if(ret!=0) {
        cout<<"Decoder "<<decoderNo<<": Cannot create receive thread"<<endl;
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }

    //Question: What is the shared resource that this mutex protects?
    pthread_mutex_init(&lock_x, NULL);
    is_running = true;
    while(is_running) {
        const int SAMPLE_SIZE=1000;
        pthread_mutex_lock(&lock_x);
        if(audioDelay.size()>=SAMPLE_SIZE) {
            int num=0;
            double runningSum=0;
            while(audioDelay.size()>0) {
                runningSum+=audioDelay.front();
                audioDelay.pop();
                ++num;
            }
            AudioDelayInfo audioDelayInfo;
            audioDelayInfo.decoder_number = decoderNo;
            audioDelayInfo.decoder_delay = runningSum/num;
            //Question: Where is this decoder sending this message?
            //Question: What is the general content of this message?
            ret = sendto(fd, &audioDelayInfo, sizeof(audioDelayInfo), 0, (struct sockaddr *)&encaddr, sizeof(encaddr));
        }
        pthread_mutex_unlock(&lock_x);
    }

    pthread_join(tid, NULL);
    cout<<"Decoder "<<decoderNo<<" is quitting..."<<endl;
    close(fd);
}

void *recv_func(void *arg)
{
    int fd = *(int *)arg;
    char buf[RECV_LEN];
    timespec ts;
    const long nanosecsPerSecond=1000000000;
    struct sockaddr_in recvaddr;
    socklen_t addrlen = sizeof(recvaddr);

    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

#ifdef DEBUG3
    int openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    char fileName[BUF_LEN];
    char metaData[BUF_LEN];
    sprintf(fileName, "DecoderFile%d.txt", decoderNo);
    int fdTest=open(fileName, openFlags, filePerms);
#endif
    while(is_running) {
    //Question: Where is this message coming from?
    //Question: What is the general content of this message?
    //Question: If there are no incoming messages, how long will recvfrom block?
        int len = recvfrom(fd, buf, RECV_LEN, 0, (struct sockaddr *)&recvaddr, &addrlen);
	if(len>0) {
            struct Packet packet;
            memcpy(&packet, buf, len);
            DecryptPacketBuffer(packet.left, packet.len);
//          DecryptPacketBuffer(packet.right, packet.len);
//          DecryptPacketBuffer(packet.center, packet.len);
//          DecryptPacketBuffer(packet.leftSurround, packet.len);
//          DecryptPacketBuffer(packet.rightSurround, packet.len);
//          DecryptPacketBuffer(packet.lowFrequencyEffects, packet.len);
#ifdef DEBUG3
            int metaLen=sprintf(metaData, "status:%d\npacketNumber:%d\ntimeStamp:%lf\nlen:%d\n",
                packet.status, packet.packetNumber, packet.timeStamp, packet.len);
            write(fdTest, metaData, metaLen);
            write(fdTest, packet.left, packet.len);
#endif
            clock_gettime(CLOCK_REALTIME, &ts);
            double timeStamp=ts.tv_sec*nanosecsPerSecond + ts.tv_nsec;
            //Question: Why are we comparing the current timestamp with the timestamp embedded within the packet?
            double diff=(timeStamp-packet.timeStamp)/1000000.0;
            pthread_mutex_lock(&lock_x);
            audioDelay.push(diff);
            pthread_mutex_unlock(&lock_x);
        }
    }
    pthread_exit(NULL);
}

void DecryptPacketBuffer(char *buf, int len)
{
    for(int i=0; i<len; ++i) {
        --buf[i];;
    }
}
