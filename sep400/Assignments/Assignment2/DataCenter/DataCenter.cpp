//DataCenter.cpp - Function definitions for the Data Center
//
// History:
// 05-May-22  M. Watler         Created.

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
#include "DataCenter.h"

using namespace std;

DataCenter* DataCenter::instance=nullptr;

static void shutdownHandler(int sig)
{
    switch(sig) {
        case SIGINT:
            DataCenter::instance->shutdown();
	    break;
    }
}

DataCenter::DataCenter(int num) {
    is_running=false;
    is_subscribed=false;
    dataCenterNo = num;
    DataCenter::instance=this;
}

void DataCenter::shutdown() {
    cout<<"DataCenter::shutdown:"<<endl;
    is_running=false;
}

int DataCenter::run()
{
    int ret, len;
    struct sockaddr_in myaddr;
    struct sockaddr_in servaddr;
    socklen_t addrlen = sizeof(servaddr);
    const int MYPORT_BASE=1160;
    const int PORT=1153;//Address of the server
    const char IP_ADDR[]="127.0.0.1";//Address of the server
    int myport;
    char buf[BUF_LEN];
    struct sigaction action;
    action.sa_handler = shutdownHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    myport=MYPORT_BASE+dataCenterNo;

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
    myaddr.sin_port = htons(myport);

    //The data center has to bind itself to an address
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

    is_running = true;
    pthread_t tid;
    ret = pthread_create(&tid, NULL, recv_func, this);
    if(ret!=0) {
        cout<<"Cannot create receive thread"<<endl;
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }

    char message[BUF_LEN];
    while(is_running && !is_subscribed) {
        //authenticate with the data acquisition unit
	cout<<"dataCenter:"<<dataCenterNo<<" attempting to subscribe"<<endl;
        len = sprintf(message, "Subscribe,DataCenter%d,Leaf", dataCenterNo);
        ret = sendto(fd, message, len, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
        sleep(5);
    }
    sleep(30);
    //cancel with the data acquisition unit
    len = sprintf(message, "Cancel,DataCenter%d", dataCenterNo);
    ret = sendto(fd, message, len, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    is_running=false;

    cout<<"dataCenter:"<<dataCenterNo<<" is quitting..."<<endl;
    pthread_join(tid, NULL);
    close(fd);
    return 0;
}

void *recv_func(void *arg)
{
    DataCenter *dataCenter = (DataCenter *)arg;
    dataCenter->ReceiveFunction();
    pthread_exit(NULL);
}

void DataCenter::ReceiveFunction()
{
    char buf[BUF_LEN];
    struct sockaddr_in recvaddr;
    socklen_t addrlen = sizeof(recvaddr);

    while(is_running) {
        int len = recvfrom(fd, buf, BUF_LEN, 0, (struct sockaddr *)&recvaddr, &addrlen);
        if(len<=0) sleep(1);
        else {//TODO: do something with the data
            if(strcmp(buf, "Subscribed")==0) is_subscribed=true;
            int packetNo=(int)buf[0];
            cout<<"dataCenter:"<<dataCenterNo<<" received packet "<<packetNo<<", "<<len<<" bytes"<<endl;
        }
    }
    pthread_exit(NULL);
}

