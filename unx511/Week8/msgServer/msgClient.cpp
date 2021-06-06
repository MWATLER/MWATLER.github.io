//msgClient.cpp - A client for multi-client text messages
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
const char IP_ADDR[]="192.168.6.128";//Address of the server
const int BUF_LEN=4096;
bool is_running;

int main(void)
{
    int fd, ret, len;
    struct sockaddr_in servaddr;
    socklen_t addrlen = sizeof(servaddr);
    char buf[BUF_LEN];


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

    is_running = true;
    char message[][64]={"Hello", "Feeling Good", "Feeling Better", "Quit"};
    for(int i=0; i<4; ++i) {
//  while(is_running) {
        len = strlen(message[i]);
        ret = sendto(fd, message[i], len, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
#ifdef DEBUG
        cout<<"waiting on "<<inet_ntoa(servaddr.sin_addr)<<":"<<PORT<<endl;
#endif
        len = recvfrom(fd, buf, BUF_LEN, 0, (struct sockaddr *)&servaddr, &addrlen);
#ifdef DEBUG
        cout<<"received "<<len<<" bytes from "<<inet_ntoa(servaddr.sin_addr)<<endl;
#endif
        if(len > 0) {
            buf[len] = '\0';
            cout<<"received message: "<<buf<<endl;
        }

	sleep(1);
    }


    close(fd);
}
