//client.cpp - The client in the client server application
//
// 27-Mar-19  M. Watler         Created.
//
#include <iostream>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

char socket_path[] = "/tmp/tmp1";

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

int main(int argc, char *argv[]) {
    struct sockaddr_un addr;
    int fd;
    int len=strlen(buf)+1;
    timespec ts1, ts2;
    const long nanosecsPerSecond=1000000000;
    double elapsedTime;

    memset(&addr, 0, sizeof(addr));
    //Create the socket
    if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        cout << "client: " << strerror(errno) << endl;
        exit(-1);
    }

    addr.sun_family = AF_UNIX;
    //Set the socket path to a local socket file
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
cout << "client: addr.sun_path: " << addr.sun_path << endl;

cout << "client: connect()" << endl;
    //Connect to the local socket
    if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
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
