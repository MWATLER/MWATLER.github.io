//server.cpp - Server code for Lab5
//
// 24-Feb-19  M. Watler         Created.

#include <iostream>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include <vector>

using namespace std;

char socket_path[]="/tmp/lab5";
bool is_running;

int main()
{
    //Create the socket for inter-process communications
    struct sockaddr_un addr;
    char buf[100];
    int len;
    int fd,cl,rc;
    int ret;

    //Create the socket
    memset(&addr, 0, sizeof(addr));
    if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
        cout << "server: " << strerror(errno) << endl;
        exit(-1);
    }

    addr.sun_family = AF_UNIX;
    //Set the socket path to a local socket file
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
    unlink(socket_path);

    //Bind the socket to this local socket file
    if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        cout << "server: " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

    cout<<"Waiting for the client..."<<endl;
    //Listen for a client to connect to this local socket file
    if (listen(fd, 5) == -1) {
        cout << "server: " << strerror(errno) << endl;
        unlink(socket_path);
        close(fd);
        exit(-1);
    }

    cout<<"client connected to the server"<<endl;
    //Accept the client's connection to this local socket file
    cout<<"server: accept()"<<endl;
    if ( (cl = accept(fd, NULL, NULL)) == -1) {
        cout << "server: " << strerror(errno) << endl;
        unlink(socket_path);
        close(fd);
        exit(-1);
    }
    cout<<"The server requests the client's pid"<<endl;
    len = sprintf(buf, "Pid") + 1;
    ret = write(cl, buf, len);
    if(ret==-1) {
        cout<<"server: Write Error"<<endl;
        cout<<strerror(errno)<<endl;
    }
    ret = read(cl,buf,sizeof(buf));
    cout<<"server: "<<buf<<endl;

    cout<<"The server requests the client to sleep"<<endl;
    len = sprintf(buf, "Sleep") + 1;
    ret = write(cl, buf, len);
    if(ret==-1) {
        cout<<"server: Write Error"<<endl;
        cout<<strerror(errno)<<endl;
    }
    ret = read(cl,buf,sizeof(buf));
    if(ret==-1 || strcmp(buf, "Done")!=0) {
        cout<<"server: Read Error"<<endl;
        cout<<strerror(errno)<<endl;
    }

    cout<<"The server requests the client to quit"<<endl;
    len = sprintf(buf, "Quit") + 1;
    ret = write(cl, buf, len);
    if(ret==-1) {
        cout<<"server: Write Error"<<endl;
        cout<<strerror(errno)<<endl;
    }

    close(cl);
    close(fd);
    return 0;
}
