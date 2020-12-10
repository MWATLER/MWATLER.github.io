//client.cpp - The client in the client server application
//
// 27-Mar-19  M. Watler         Created.
//
#include <arpa/inet.h>
#include <iostream>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

const int PORT=1153;
const char IP_ADDR[]="192.168.6.128";//Address of the server
const int BUF_LEN=30;

char buf[]="abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz \
abcdefghijklmnopqrstuvwxyz";//20

int main(int argc, char *argv[]) {
    struct sockaddr_in servaddr;
    int fd, ret;
    int len=strlen(buf)+1;
    timespec ts1, ts2;
    const long nanosecsPerSecond=1000000000;
    double elapsedTime;

    //Create the socket
    if ( (fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        cout << "client: " << strerror(errno) << endl;
        exit(-1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    ret = inet_pton(AF_INET, IP_ADDR, &servaddr.sin_addr);
    if(ret==0) {
        cout<<"No such address"<<endl;
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }
    servaddr.sin_port = htons(PORT);

cout << "client: connect()" << endl;
    //Connect to the local socket
    if (connect(fd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        cout << "client: " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

cout << "client: write()"<<endl;
    clock_gettime(CLOCK_REALTIME, &ts1);
    for(int i=0; i<5000000; ++i) {
        write(fd, buf, len);
    }
    clock_gettime(CLOCK_REALTIME, &ts2);
    elapsedTime = (double)(ts2.tv_sec-ts1.tv_sec)*nanosecsPerSecond + (ts2.tv_nsec-ts1.tv_nsec);
    elapsedTime /= nanosecsPerSecond;
    cout << "The elapsed time with stream sockets is "<<elapsedTime<<" seconds."<<endl;
   
cout << "client: close(fd)" << endl;
    close(fd);
    return 0;
}
