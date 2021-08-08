//clientIP.cpp - A client for multi-client messages to the radio application
//
// 08-Aug-21  M. Watler         Created.

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

//Processes on a different machine sending to the radio through IP
//Radio IP address
const int RADIO_PORT=1143;
const char RADIO_ADDR[]="192.168.8.130";
const char CLIENTIP_ADDR[]="192.168.8.130";
const int BUF_LEN=4096;
bool is_running;
int clientNo;

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
    int fd, ret, len, retVal=0;
    struct sockaddr_in myaddr;
    struct sockaddr_in radioAddr;
    socklen_t addrlen = sizeof(radioAddr);
    const int MYPORT_BASE=1144;
    int myport;

    if(argc!=2) {
        cout<<"usage: msgClient <clientNo>"<<endl;
        retVal = -1;
    }
    if(retVal==0) {
        signal(SIGINT, shutdownHandler);
        clientNo=atoi(argv[1]);
        myport=MYPORT_BASE+clientNo;

        fd=socket(AF_INET, SOCK_DGRAM | SOCK_NONBLOCK, 0);
        if(fd<0) {
            cout<<"Cannot create the socket"<<endl;
    	    cout<<strerror(errno)<<endl;
    	    retVal = -2;
        }
    }
    
    if(retVal==0) {
        memset((char *)&myaddr, 0, sizeof(myaddr));
        myaddr.sin_family = AF_INET;
        ret = inet_pton(AF_INET, CLIENTIP_ADDR, &myaddr.sin_addr);
        if(ret==0) {
            cout<<"No such address"<<endl;
            cout<<strerror(errno)<<endl;
            retVal = -4;
        }
        myaddr.sin_port = htons(myport);
    }

    if(retVal==0) {
        //The client has to bind itself to an address
        ret = bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr));
        if(ret<0) {
            cout<<"Cannot bind the socket to the local address"<<endl;
            cout<<strerror(errno)<<endl;
            retVal = -5;
        }
    }

    if(retVal==0) {
        memset((char *)&radioAddr, 0, sizeof(radioAddr));
        radioAddr.sin_family = AF_INET;
        ret = inet_pton(AF_INET, RADIO_ADDR, &radioAddr.sin_addr);
        if(ret==0) {
            cout<<"No such address"<<endl;
            cout<<strerror(errno)<<endl;
            retVal = -6;
        }
        radioAddr.sin_port = htons(RADIO_PORT);
    }

    if(retVal==0) {
        is_running=true;
        int messageNo=0;
        char buf[BUF_LEN];
        while(is_running) {
            memset(buf,0,BUF_LEN);
            int len=sprintf(buf, "%02hdclient %02d message %03d\n", clientNo, clientNo, messageNo++);
            sendto(fd, buf, len, 0, (struct sockaddr *)&radioAddr, addrlen);
            sleep(1);
        }
    }

    //clean up
    if(fd>=0) close(fd);

    return retVal;
}
