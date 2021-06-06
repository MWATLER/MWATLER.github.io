//msgClient.cpp - A client for text messages with the UDP protocol
//
// For a good tutorial, UDP sockets: see https://www.cs.rutgers.edu/~pxk/417/notes/sockets/udp.html
//                       IP sockets: see https://www.cs.rutgers.edu/~pxk/417/notes/sockets/index.html
//
// 04-Apr-19  M. Watler         Created.

#include <arpa/inet.h>
#include <iostream>
#include <net/if.h>
#include <netinet/in.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

using namespace std;

const int PORT=1153;
//const char IP_ADDR[]="192.168.6.128";//Address of the server
const char IP_ADDR[]="192.168.239.131";//Address of the server
const int BUF_LEN=30;
char buf[]="abcdefghijklmnopqrstuvwxyz";

int main(void)
{
    int fd, ret, len;
    struct sockaddr_in servaddr, recvaddr;
    socklen_t addrlen = sizeof(servaddr);

    fd=socket(AF_INET, SOCK_DGRAM, 0);
    if(fd<0) {
        cout<<"Cannot create the socket"<<endl;
	cout<<strerror(errno)<<endl;
	return -1;
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
    len = strlen(buf)+1;

    ret=sendto(fd, buf, len, 0, (struct sockaddr *)&servaddr, addrlen);
    if(ret<0){
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }
    memset(buf, 0, BUF_LEN);
    ret=recvfrom(fd, buf, len, 0, (struct sockaddr *)&recvaddr, &addrlen);
    if(ret<0){
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }
    cout<<"client: received "<<buf<<endl;

    close(fd);
    return 0;
}
