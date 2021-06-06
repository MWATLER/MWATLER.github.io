//client1.cpp - client 1 in the client server application
//
// 30-Jan-19  M. Watler         Created.
//
#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

const char socket_path[] = "/tmp/tmp1";
const int BUF_LEN=100;

int main(int argc, char *argv[]) {
    struct sockaddr_un addr;
    char buf[BUF_LEN];
    int fd,len;
    bool isRunning = true;

    memset(&addr, 0, sizeof(addr));
    //Create the socket
cout << "client1: socket()" << endl;
    if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        cout << "client1: " << strerror(errno) << endl;
        exit(-1);
    }

    addr.sun_family = AF_UNIX;
    //Set the socket path to a local socket file
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);

cout << "client1: connect()" << endl;
    //Connect to the local socket
    if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        cout << "client1: " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

    sprintf(buf,  "\nEnter something (quit to finish):\n");
    write(STDOUT_FILENO, buf, strlen(buf));
    while(isRunning) {
        //Read from the standard input (keyboard)
	memset(buf,0,BUF_LEN);
        len=read(STDIN_FILENO, buf, BUF_LEN);
	if(len<0) isRunning=false;
	else {
            //Write to the socket
            write(fd, buf, len);
	    if(strncmp("quit", buf, 4)==0) {
                isRunning = false;
            }
        }
    }
   
cout << "client1: close(fd)" << endl;
    close(fd);
    return 0;
}
