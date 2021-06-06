//msgServer.cpp - The server for client text messages with the UDP protocol
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
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

using namespace std;

const int PORT=1153;
//const char IP_ADDR[]="192.168.6.128";
const char IP_ADDR[]="192.168.239.131";
const int BUF_LEN=30;

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
	close(fd);
	return -1;
    }

    len = recvfrom(fd, buf, BUF_LEN, 0, (struct sockaddr *)&remaddr, &addrlen);
    if(len<0) {
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }
    cout<<"server: received "<<buf<<endl;
    char newBuf[BUF_LEN];
    memset(newBuf, 0, BUF_LEN);
    for(int i=0; i<len; ++i)
        newBuf[i]=toupper(buf[i]);
    len=sendto(fd, newBuf, len, 0, (struct sockaddr *)&remaddr, addrlen);
    if(len<0) {
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
}
