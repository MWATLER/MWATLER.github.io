//msgServer.cpp - The server for multi-client text messages
//                The connection protocol is UDP.
//
// For a good tutorial, UDP sockets: see https://www.cs.rutgers.edu/~pxk/417/notes/sockets/udp.html
//                       IP sockets: see https://www.cs.rutgers.edu/~pxk/417/notes/sockets/index.html
//
// 05-Mar-19  M. Watler         Created.

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
const char IP_ADDR[]="192.168.6.129";
const int BUF_LEN=4096;
bool is_running;

int main(void)
{
    int fd, ret, len;
    struct sockaddr_in myaddr;
    struct sockaddr_in remaddr;
    socklen_t addrlen = sizeof(remaddr);
    char buf[BUF_LEN];


    fd=socket(AF_INET, SOCK_DGRAM, 0);
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

    is_running = true;

    //Set a socket timeout of 5 seconds
    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    while(is_running) {
#ifdef DEBUG
        cout<<"waiting on "<<inet_ntoa(myaddr.sin_addr)<<":"<<PORT<<endl;
#endif
        len = recvfrom(fd, buf, BUF_LEN, 0, (struct sockaddr *)&remaddr, &addrlen);
#ifdef DEBUG
	cout<<"received "<<len<<" bytes from "<<inet_ntoa(remaddr.sin_addr)<<endl;
#endif
	if(len > 0) {
            buf[len] = '\0';
            cout<<"received message: "<<buf<<endl;
	    if(strcmp(buf,"Quit")==0) is_running=false;

            len = sprintf(buf, "DONE")+1;
            ret = sendto(fd, buf, len, 0, (struct sockaddr *)&remaddr, sizeof(remaddr));
        } else {
            cout<<"Timed out, reading again"<<endl;
	}
    }

#ifdef DEBUG
    cout<<"Server is quitting..."<<endl;
#endif

    close(fd);
}
