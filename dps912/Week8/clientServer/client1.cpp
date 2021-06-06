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

char socket_path[] = "/tmp/tmp1";

int main(int argc, char *argv[]) {
    struct sockaddr_un addr;
    char buf[100];
    int fd,rc;
    bool isRunning = true;

    memset(&addr, 0, sizeof(addr));
    //Create the socket
    if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        cout << "client1: " << strerror(errno) << endl;
        exit(-1);
    }

    addr.sun_family = AF_UNIX;
    //Set the socket path to a local socket file
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
cout << "client1: addr.sun_path: " << addr.sun_path << endl;

cout << "client1: connect()" << endl;
    //Connect to the local socket
    if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        cout << "client1: " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

cout << "client1: read(STDIN_FILENO)" << endl;
    //Read from the standard input (keyboard)
    while( isRunning ) {
		rc=read(STDIN_FILENO, buf, sizeof(buf));
cout << "client1: write(" << buf << ")" << endl;
        //Write to the socket
        if (write(fd, buf, rc) != rc) {
            if (rc > 0) fprintf(stderr,"partial write");
            else {
                cout << "client1: " << strerror(errno) << endl;
                close(fd);
                exit(-1);
            }
        }
	if(strncmp("quit", buf, 4)==0) {
	    isRunning = false;
	}
    }
   
cout << "client1: close(fd)" << endl;
    close(fd);
    return 0;
}
