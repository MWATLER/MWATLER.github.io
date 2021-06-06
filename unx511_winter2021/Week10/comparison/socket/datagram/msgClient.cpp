//msgClient.cpp - A client for text messages with the UDP protocol
//
// For a good tutorial, UDP sockets: see https://www.cs.rutgers.edu/~pxk/417/notes/sockets/udp.html
//                       IP sockets: see https://www.cs.rutgers.edu/~pxk/417/notes/sockets/index.html
//
// 27-Mar-19  M. Watler         Created.

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
const char IP_ADDR[]="127.0.0.1";//Address of the server
const int BUF_LEN=300;
char buf[]="abcdefghijklmnopqrstuvwxyz" \
           "abcdefghijklmnopqrstuvwxyz" \
           "abcdefghijklmnopqrstuvwxyz" \
           "abcdefghijklmnopqrstuvwxyz" \
           "abcdefghijklmnopqrstuvwxyz" \
           "abcdefghijklmnopqrstuvwxyz" \
           "abcdefghijklmnopqrstuvwxyz" \
           "abcdefghijklmnopqrstuvwxyz" \
           "abcdefghijklmnopqrstuvwxyz" \
           "abcdefghijklmnopqrstuvwxyz";

int main(void)
{
    int fd, ret, len;
    struct sockaddr_in servaddr;
    timespec ts1, ts2;
    const long nanosecsPerSecond=1000000000;
    double elapsedTime;
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

    clock_gettime(CLOCK_REALTIME, &ts1);
    for(int i=0; i<5000000; ++i) {
        ret=sendto(fd, buf, len, 0, (struct sockaddr *)&servaddr, addrlen);
    }
    clock_gettime(CLOCK_REALTIME, &ts2);
    elapsedTime = (double)(ts2.tv_sec-ts1.tv_sec)*nanosecsPerSecond + (ts2.tv_nsec-ts1.tv_nsec);
    elapsedTime /= nanosecsPerSecond;
    cout << "The elapsed time with datagram sockets is "<<elapsedTime<<" seconds."<<endl;

    close(fd);
    return 0;
}
