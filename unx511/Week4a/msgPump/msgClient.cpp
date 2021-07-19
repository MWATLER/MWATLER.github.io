//msgClient.cpp - A client for multi-client text messages
//                The connection protocol is UDP.
//
// For a good tutorial, UDP sockets: see https://www.cs.rutgers.edu/~pxk/417/notes/sockets/udp.html
//                       IP sockets: see https://www.cs.rutgers.edu/~pxk/417/notes/sockets/index.html
//
// 04-Aug-20  M. Watler         Created.

#include <arpa/inet.h>
#include <iostream>
#include <net/if.h>
#include <netinet/in.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

using namespace std;

const int PORT=1153;
const char IP_ADDR[]="192.168.239.128";//Address of the server
const int BUF_LEN=4096;
bool is_running;
int clientNo;

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
    struct sockaddr_in servaddr;
    socklen_t addrlen = sizeof(servaddr);
    const int MYPORT_BASE=2000;
    int myport;
    char buf[BUF_LEN];

    if(argc!=2) {
        cout<<"usage: msgClient <clientNo>"<<endl;
        return -1;
    }
    signal(SIGINT, shutdownHandler);
    clientNo=atoi(argv[1]);
    myport=MYPORT_BASE+clientNo;

    fd=socket(AF_INET, SOCK_DGRAM | SOCK_NONBLOCK, 0);
    if(fd<0) {
        cout<<"Cannot create the socket"<<endl;
	cout<<strerror(errno)<<endl;
	return -1;
    }

    memset((char *)&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    myaddr.sin_port = htons(myport);

    //The client has to bind itself to an address
    ret = bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr));
    if(ret<0) {
        cout<<"Cannot bind the socket to the local address"<<endl;
        cout<<strerror(errno)<<endl;
        return -1;
    } else {
#ifdef DEBUG
       cout<<"socket fd:"<<fd<<" bound to address "<<inet_ntoa(myaddr.sin_addr)<<endl;
#endif
    }

    memset((char *)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    ret = inet_pton(AF_INET, IP_ADDR, &servaddr.sin_addr);
    if(ret==0) {
        cout<<"No such address"<<endl;
	cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }
    servaddr.sin_port = htons(PORT);

    pthread_t tid;
    ret = pthread_create(&tid, NULL, recv_func, &fd);
    if(ret!=0) {
        cout<<"Cannot create receive thread"<<endl;
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }

    is_running = true;
    char message[BUF_LEN];
    int messageNo=1;
    int destClient=1;
    while(is_running) {
        //message = src dst message
        len = sprintf(message, "%d %d Test message %d\n", clientNo, destClient, messageNo++)+1;
#ifdef DEBUG
        cout<<"client:"<<clientNo<<" destClient:"<<destClient<<" sendto:"<<message;
#endif
	destClient = (destClient++)%12+1;//Wrap around at client 12
        ret = sendto(fd, message, len, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
	sleep(1);
    }

    cout<<"client:"<<clientNo<<" is quitting..."<<endl;
    pthread_join(tid, NULL);
    close(fd);
}

void *recv_func(void *arg)
{
    int fd = *(int *)arg;
    char buf[BUF_LEN];
    struct sockaddr_in recvaddr;
    socklen_t addrlen = sizeof(recvaddr);

    while(is_running) {
        int len = recvfrom(fd, buf, BUF_LEN, 0, (struct sockaddr *)&recvaddr, &addrlen);
        if(len<0) sleep(1);
        else {
            int srcMessage=atoi(&buf[0]);
#ifdef DEBUG
            cout<<"client:"<<clientNo<<" srcMessage:"<<srcMessage<<" recvfrom:"<<buf;
#endif
        }
    }
    pthread_exit(NULL);
}
