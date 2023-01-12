//server.cpp - The server in the client server application
//
// 30-Jan-19  M. Watler         Created.
//
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>

using namespace std;

char socket_path[] = "/tmp/tmp1";

int main(int argc, char *argv[]) {
    struct sockaddr_un addr;
    char buf[100];
    int fd,cl,rc;
    bool isRunning = true;

    memset(&addr, 0, sizeof(addr));
    //Create the socket
    if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
        cout << "server: " << strerror(errno) << endl;
        exit(-1);
    }

    addr.sun_family = AF_UNIX;
    //Set the socket path to a local socket file
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
cout << "server: addr.sun_path:" << addr.sun_path << endl;
    unlink(socket_path);

cout << "server: bind()" << endl;
    //Bind the socket to this local socket file
    if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        cout << "server: " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

cout << "server: listen()" << endl;
    //Listen for a client to connect to this local socket file
    if (listen(fd, 5) == -1) {
        cout << "server: " << strerror(errno) << endl;
        unlink(socket_path);
        close(fd);
        exit(-1);
    }

    while (isRunning) {
cout << "server: accept()" << endl;
        //Accept the client's connection to this local socket file
        if ( (cl = accept(fd, NULL, NULL)) == -1) {
            cout << "server: " << strerror(errno) << endl;
            unlink(socket_path);
            close(fd);
            exit(-1);
        }

cout << "server: read()" << endl;
        //Wait for data to read on this local socket file
        while ( (rc=read(cl,buf,sizeof(buf))) > 0) {
            cout << "read " << rc << " bytes: " << buf << endl;
            //Continue reading until the client sends "quit"
	    if(strncmp("quit", buf, 4)==0) {
	        isRunning = false;
	    }
        }
        if (rc < 0) {
	    //Cannot read from this local socket file
            cout << "server: " << strerror(errno) << endl;
            unlink(socket_path);
            close(fd);
            close(cl);
            exit(-1);
        }
        else if (rc == 0) {
	    //Clean up
            cout << "EOF" << endl;
            unlink(socket_path);
            close(fd);
            close(cl);
        }
    }

cout << "server: close(fd), close(cl)" << endl;
    unlink(socket_path);
    close(fd);
    close(cl);
    return 0;
}
