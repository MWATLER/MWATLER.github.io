//msgPump.cpp - The server for multi-client text messages
//              The connection protocol is UDP.
//
// 04-Aug-20  M. Watler         Created.

#include <arpa/inet.h>
#include <iostream>
#include <net/if.h>
#include <netinet/in.h>
#include <queue>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

using namespace std;

const int PORT=1153;
const char IP_ADDR[]="192.168.239.128";
const int BUF_LEN=4096;
bool is_running;

typedef struct clientIP {
    int clientNo;
    char ipAddr[32];
    int port;
} ClientIP;

typedef struct message {
    int len;
    char buf[BUF_LEN];
} Message;

queue<Message> messageQueue;

pthread_mutex_t lock_x;

ClientIP client[] = {//Each client is bound to one of the following addresses.
	             //The server is bound to 192.168.239.128:1153.
    {1,  "192.168.239.128", 2001},
    {2,  "192.168.239.128", 2002},
    {3,  "192.168.239.128", 2003},
    {4,  "192.168.239.128", 2004},
    {5,  "192.168.239.128", 2005},
    {6,  "192.168.239.128", 2006},
    {7,  "192.168.239.128", 2007},
    {8,  "192.168.239.128", 2008},
    {9,  "192.168.239.128", 2009},
    {10, "192.168.239.128", 2010},
    {11, "192.168.239.128", 2011},
    {12, "192.168.239.128", 2012},
    {13, "192.168.239.128", 2013},
    {14, "192.168.239.128", 2014},
    {15, "192.168.239.128", 2015},
    {16, "192.168.239.128", 2016},
};

void *recv_func(void *arg);

static void shutdownHandler(int sig)
{
    switch(sig) {
        case SIGINT:
            is_running=false;
            break;
    }
}

int main(void)
{
    int fd, ret, len;
    struct sockaddr_in myaddr;
    struct sockaddr_in destaddr;
    socklen_t addrlen = sizeof(myaddr);
    char buf[BUF_LEN];

    signal(SIGINT, shutdownHandler);
    fd=socket(AF_INET, SOCK_DGRAM | SOCK_NONBLOCK, 0);
    if(fd<0) {
        cout<<"Cannot create the socket"<<endl;
	cout<<strerror(errno)<<endl;
	return -1;
    }

    memset((char *)&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    ret = inet_pton(AF_INET, IP_ADDR, &myaddr.sin_addr);
    if(ret==0) {
        cout<<"No such address"<<endl;
	cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }
    myaddr.sin_port = htons(PORT);

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
    pthread_mutex_init(&lock_x, NULL);
    is_running = true;
    pthread_t tid;
    ret = pthread_create(&tid, NULL, recv_func, &fd);
    if(ret!=0) {
        cout<<"Cannot create receive thread"<<endl;
	cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }

    while(is_running) {
        if(messageQueue.size()==0) sleep(1);
	else {
            pthread_mutex_lock(&lock_x);
            Message tmpMsg = messageQueue.front();
	    messageQueue.pop();
            pthread_mutex_unlock(&lock_x);
            int destClient = atoi(&tmpMsg.buf[1]);
            memset((char *)&destaddr, 0, sizeof(destaddr));
            destaddr.sin_family = AF_INET;
            ret = inet_pton(AF_INET, client[destClient-1].ipAddr, &destaddr.sin_addr);
            if(ret==0) {
                cout<<"No such address"<<endl;
                cout<<strerror(errno)<<endl;
            }
            destaddr.sin_port = htons(client[destClient-1].port);
#ifdef DEBUG
	    char destAddr[32];
	    sprintf(destAddr, "%s:%d", inet_ntoa(destaddr.sin_addr), ntohs(destaddr.sin_port));
            cout<<"queue size:"<<messageQueue.size()<<" destaddr: "<<destAddr<<endl;
            cout<<"queue size:"<<messageQueue.size()<<" sendto: "<<tmpMsg.buf;
#endif
            ret = sendto(fd, tmpMsg.buf, tmpMsg.len, 0, (struct sockaddr *)&destaddr, sizeof(destaddr));
	}
    }

#ifdef DEBUG
    cout<<"Server is quitting..."<<endl;
#endif
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
#ifdef DEBUG
	    char recvAddr[32];
	    sprintf(recvAddr, "%s:%d", inet_ntoa(recvaddr.sin_addr), ntohs(recvaddr.sin_port));
            cout<<"recvaddr: "<<recvAddr<<endl;
            cout<<"recvfrom: "<<buf;
#endif
            Message tmpMsg;
	    tmpMsg.len = len;
	    strncpy(tmpMsg.buf, buf, len);
            pthread_mutex_lock(&lock_x);
            messageQueue.push(tmpMsg);
            pthread_mutex_unlock(&lock_x);
	}
    }

    pthread_exit(NULL);
}
