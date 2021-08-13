// Encoder.cpp - encodes and dispatches the audio
//
// 29-Jul-21  M. Watler         Created.
//

#include <arpa/inet.h>
#include <errno.h>
#include <iostream>
#include <fcntl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/socket.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "addresses.h"
#include "sharedMem.h"

using namespace std;
bool isRunning;

//Question: What is the inter-process communication mechanism between the encoder and audio generator?
//Question: What information is passed between the encoder and audio generator?
//Question: What is the inter-process communication mechanism between the encoder and the decoder?
//Question: What information is passed between the encoder and the decoder?

queue<Packet> packets;
const int NUM_DECODERS=3;
//Question: If my encoder had an IP address of 192.168.239.132 and my decoders an IP address of 192.168.239.128, would this setup work?
struct Address encoder = {
    "127.0.0.1", 1153
//  "192.168.239.132", 1153
};
struct Address decoder[NUM_DECODERS] = {
    {"127.0.0.1", 1154},
    {"127.0.0.1", 1155},
    {"127.0.0.1", 1156},
//  {"192.168.239.128", 1154},
//  {"192.168.239.128", 1155},
//  {"192.168.239.128", 1156},
};

void *recv_func(void *arg);
void *send_func(void *arg);

pthread_mutex_t lock_x;

void shutdownHandler(int signal)
{
    switch(signal) {
        case SIGINT:
            isRunning = false;
            break;
    }
}

int main(void) {
    sem_t *sem_id;
    key_t ShmKey;
    int   ShmID;
    struct Memory *ShmPTR;
    char buf[BUF_LEN];
    int size, packetIndex;
    struct Packet packet;
    int ret;
    pthread_t tid_recv, tid_send; 
    timespec ts;
    int fd;
    struct sockaddr_in myaddr;
    socklen_t addrlen = sizeof(myaddr);

    //Intercept ctrl-C
    struct sigaction action;

    action.sa_handler = shutdownHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    //Question: Will this be a reliable socket connection?
    //Question: Will this process be able to communicate with a process on another machine?
    fd=socket(AF_INET, SOCK_DGRAM, 0);
    if(fd<0) {
        cout<<"Encoder: Cannot create the socket"<<endl;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    memset((char *)&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    ret = inet_pton(AF_INET, encoder.ip_addr, &myaddr.sin_addr);
    if(ret==0) {
        cout<<"Encoder: No such address"<<endl;
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }
    myaddr.sin_port = htons(encoder.ip_port);

    //Question: What address are we binding to here (give the ip and port)?
    ret = bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr));
    if(ret<0) {
        cout<<"Encoder: Cannot bind the socket to the local address"<<endl;
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    } else {
#ifdef DEBUG
       cout<<"Encoder: socket fd:"<<fd<<" bound to address "<<inet_ntoa(myaddr.sin_addr)<<endl;
#endif
    }

    //Question: What process uses this semaphore with the encoder?
    sem_id=sem_open(SEMNAME, O_CREAT, SEM_PERMS, 0);
    if(sem_id==SEM_FAILED) {
        cout<<"Encoder: sem_open() error"<<endl;
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }

    //Question: What process uses this shared memory with the encoder?
    ShmKey=ftok(MEMNAME, 65);
    //Question: What happens if this shared memory has already been created?
    ShmID=shmget(ShmKey, sizeof(struct Memory), IPC_CREAT | 0666);
    if (ShmID < 0) {
        cout<<"Encoder: shmget() error"<<endl;
        cout<<strerror(errno)<<endl;
        sem_close(sem_id);
        sem_unlink(SEMNAME);
        close(fd);
        return -1;
    }
    ShmPTR = (struct Memory *) shmat(ShmID, NULL, 0);
    if (ShmPTR == (void *)-1) {
        cout<<"Encoder: shmat() error"<<endl;
        cout<<strerror(errno)<<endl;
        shmctl(ShmID, IPC_RMID, NULL);
        sem_close(sem_id);
        sem_unlink(SEMNAME);
        close(fd);
        return -1;
    }

    cout<<"Encoder: sem_post()"<<endl;
    //Question: What is the purpose of posting a semaphore here?
    sem_post(sem_id);
    sleep(0.1);

    //Question: What shared resource are we protecting with this mutex?
    pthread_mutex_init(&lock_x, NULL);
    isRunning=true;
    ret = pthread_create(&tid_recv, NULL, recv_func, &fd);
    if(ret!=0) {
        isRunning = false;
        cout<<strerror(errno)<<endl;
        shmctl(ShmID, IPC_RMID, NULL);
        sem_close(sem_id);
        sem_unlink(SEMNAME);
        close(fd);
        return -1;
    }
    ret = pthread_create(&tid_send, NULL, send_func, &fd);
    if(ret!=0) {
        isRunning = false;
        cout<<strerror(errno)<<endl;
        shmctl(ShmID, IPC_RMID, NULL);
        sem_close(sem_id);
        sem_unlink(SEMNAME);
        close(fd);
        return -1;
    }

    packetIndex=0;
    while(isRunning) {
        packet.status=ShmPTR->packet[packetIndex].status;
        //Question: Why can't we proceed if status is not set to WRITTEN?
        if(packet.status!=WRITTEN) {
            sleep(0.3);
        } else {
            //Question: Would the following work?    memcpy(&packet, ShmPTR->packet, sizeof(ShmPTR->packet));
            packet.packetNumber = ShmPTR->packet[packetIndex].packetNumber;
            packet.len = ShmPTR->packet[packetIndex].len;
            packet.timeStamp = ShmPTR->packet[packetIndex].timeStamp;
            memset(packet.left, 0, BUF_LEN);
            memset(packet.right, 0, BUF_LEN);
            memset(packet.center, 0, BUF_LEN);
            memset(packet.leftSurround, 0, BUF_LEN);
            memset(packet.rightSurround, 0, BUF_LEN);
            memset(packet.lowFrequencyEffects, 0, BUF_LEN);
            //Question: Should we use BUF_LEN or ShmPTR->packet[packetIndex].len instead?
            memcpy(packet.left, ShmPTR->packet[packetIndex].left, BUF_LEN);
            memcpy(packet.right, ShmPTR->packet[packetIndex].right, BUF_LEN);
            memcpy(packet.center, ShmPTR->packet[packetIndex].center, BUF_LEN);
            memcpy(packet.leftSurround, ShmPTR->packet[packetIndex].leftSurround, BUF_LEN);
            memcpy(packet.rightSurround, ShmPTR->packet[packetIndex].rightSurround, BUF_LEN);
            memcpy(packet.lowFrequencyEffects, ShmPTR->packet[packetIndex].lowFrequencyEffects, BUF_LEN);
#ifdef DEBUG
            cout<<"Encoder: packet number "<<packet.packetNumber<<" length "<<packet.len<<endl;
#endif
            //Question: Why are we setting the status to READ?
            ShmPTR->packet[packetIndex].status=READ;
            pthread_mutex_lock(&lock_x);
            packets.push(packet);
            pthread_mutex_unlock(&lock_x);
            ++packetIndex;
            if(packetIndex>=NUM_PACKETS) packetIndex=0;
        }
    }

    //Detach the memory
    shmdt((void *)ShmPTR);
    shmctl(ShmID, IPC_RMID, NULL);

    sem_close(sem_id);
    sem_unlink(SEMNAME);
    close(fd);
    pthread_join(tid_send, NULL);
    pthread_join(tid_recv, NULL);
    pthread_mutex_destroy(&lock_x);

    int pid=fork();
    if(pid==0) {
	//Question: If the decoder is on another machine, how might we request it to shutdown?
        execlp("pkill", "pkill", "-2", "Decoder", NULL);
    }
    cout<<"Encoder shutting down"<<endl;

    return 0;
}

//Question: What is the general purpose of this receive thread?
void *recv_func(void *arg)
{
    int fd = *(int *)arg;
    struct AudioDelayInfo audioDelayInfo;
    double AudioDelays[NUM_DECODERS];
    char buf[BUF_LEN];
    struct sockaddr_in recvaddr;
    socklen_t addrlen = sizeof(recvaddr);

    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    //Question: What is setsockopt() attempting to do?
    setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    while(isRunning) {
        //Question: What are the possible sources of this incoming message?
        int len = recvfrom(fd, buf, BUF_LEN, 0, (struct sockaddr *)&recvaddr, &addrlen);
        //Question: If len is less than zero, did we receive something?
	if(len>0) {
            //Question: What information is stored in buf?
            memcpy(&audioDelayInfo, buf, len);
            AudioDelays[audioDelayInfo.decoder_number-1]=audioDelayInfo.decoder_delay;
            system("clear");
            for(int i=0; i<NUM_DECODERS; ++i) {
                cout<<"Decoder "<<(i+1)<<" Delay="<<AudioDelays[i]<<"ms"<<endl;
            }
        }
    }
    pthread_exit(NULL);
}

//Question: What is the general purpose of this send thread?
void *send_func(void *arg)
{
    int fd = *(int *)arg;
    struct sockaddr_in destaddr;

    while(isRunning) {
        while(packets.size()>0) {
            pthread_mutex_lock(&lock_x);
            //Question: What has been filling the packets queue?
            struct Packet packet=packets.front();
            packets.pop();
            pthread_mutex_unlock(&lock_x);
#ifdef DEBUG2
            cout<<packet.left<<endl;
            cout<<packet.right<<endl;
            cout<<packet.center<<endl;
            cout<<packet.leftSurround<<endl;
            cout<<packet.rightSurround<<endl;
            cout<<packet.lowFrequencyEffects<<endl;
#endif
            //Question: Will this encrypt all audio channels or just packet.left?
            EncryptPacketBuffer(packet.left, packet.len);
//          EncryptPacketBuffer(packet.right, packet.len);
//          EncryptPacketBuffer(packet.center, packet.len);
//          EncryptPacketBuffer(packet.leftSurround, packet.len);
//          EncryptPacketBuffer(packet.rightSurround, packet.len);
//          EncryptPacketBuffer(packet.lowFrequencyEffects, packet.len);
            //Question: To what is the encoder sending these packets?
            for(int i=0; i<NUM_DECODERS; ++i) {
                destaddr.sin_family = AF_INET;
                inet_pton(AF_INET, decoder[i].ip_addr, &destaddr.sin_addr);
                destaddr.sin_port = htons(decoder[i].ip_port);
                sendto(fd, &packet, sizeof(packet), 0, (struct sockaddr *)&destaddr, sizeof(destaddr));
            }
        }
    }
    pthread_exit(NULL);
}

void EncryptPacketBuffer(char *buf, int len)
{
    for(int i=0; i<len; ++i) {
        ++buf[i];;
    }
}
