//client.cpp - The client in the client server application
//
// 04-Apr-19  M. Watler         Created.
//
#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

char socket_path[] = "/tmp/tmp1";

char buf[]="abcdefghijklmnopqrstuvwxyz";
const int MSG_SIZE=30;

int main(int argc, char *argv[]) {
    struct sockaddr_un addr;
    int fd, rc;
    int len;

    memset(&addr, 0, sizeof(addr));
    //Create the socket
    if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        cout << "client: " << strerror(errno) << endl;
        exit(-1);
    }

    addr.sun_family = AF_UNIX;
    //Set the socket path to a local socket file
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);

    //Connect to the local socket
    if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        cout << "client: " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

    len=strlen(buf)+1;
    rc=write(fd, buf, len);
    if(rc<0) {
        cout << "client: " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }
    memset(buf, 0, MSG_SIZE);
    rc=read(fd, buf, MSG_SIZE);
    if(rc<0) {
        cout << "client: " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }
    cout<<"client: received "<<buf<<endl;
   
    close(fd);
    return 0;
}
