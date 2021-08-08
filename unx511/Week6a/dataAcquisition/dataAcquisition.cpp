//dataAcquisition.cpp - The data acquisition system for the radio application
//
// 08-Aug-21  M. Watler         Created.

#include <arpa/inet.h>
#include <fcntl.h>
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

//data acquisition system IP address
const char DATA_ADDR[]="192.168.8.130";
const int DATA_PORT=1180;
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
    int fd, fdOut, ret, len, retVal=0;
    struct sockaddr_in myaddr;
    struct sockaddr_in remoteAddr;
    socklen_t addrlen = sizeof(myaddr);
    struct sigaction action;

    if(retVal==0) {
        action.sa_handler = shutdownHandler;
        sigemptyset(&action.sa_mask);
        action.sa_flags = 0;
        sigaction(SIGINT, &action, NULL);

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
        ret = inet_pton(AF_INET, DATA_ADDR, &myaddr.sin_addr);
        if(ret==0) {
            cout<<"No such address"<<endl;
            cout<<strerror(errno)<<endl;
            retVal = -4;
        }
        myaddr.sin_port = htons(DATA_PORT);
    }

    if(retVal==0) {
        //The data acquisition system has to bind itself to an address
        ret = bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr));
        if(ret<0) {
            cout<<"Cannot bind the socket to the local address"<<endl;
            cout<<strerror(errno)<<endl;
            retVal = -5;
        }
    }

    if(retVal==0) {
       //Set a socket timeout of 5 seconds
        struct timeval tv;
        tv.tv_sec = 5;
        tv.tv_usec = 0;
    
        setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

	//Print everything to a file
        int openFlags = O_CREAT | O_WRONLY | O_TRUNC;
        mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;/* rw-rw-rw- */;
        char dataFile[]="dataFile.txt";
        fdOut = open(dataFile, openFlags, filePerms);
        if(fdOut<0) {
            cout << "Error opening " << dataFile << endl;
            cout<<strerror(errno)<<endl;
            retVal = -6;
        }
    }

    if(retVal==0) {
        is_running=true;
        int messageNo=0;
        char buf[BUF_LEN];
        while(is_running) {
            memset(buf,0,BUF_LEN);
            int len = recvfrom(fd, buf, BUF_LEN, 0, (struct sockaddr *)&remoteAddr, &addrlen);
            if(len>0) {
                write(fdOut, buf, len);
            }
        }
    }

    //clean up
    if(fd>=0) close(fd);
    if(fdOut>=0) close(fdOut);

    return retVal;
}
