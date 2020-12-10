//client.cpp - client code.
//
// 24-Feb-19  M. Watler         Created.

#include <iostream>
#include <fstream>
#include <signal.h>
#include <string.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

using namespace std;

char socket_path[]="/tmp/sel";
bool is_running;
const int BUF_LEN=100;

int main(int argc, char *argv[])
{
    //Set up socket communications
    struct sockaddr_un addr;
    char buf[BUF_LEN];
    int len, ret;
    int fd,rc;

    cout<<"client("<<getpid()<<"): running..."<<endl;
    memset(&addr, 0, sizeof(addr));
    //Create the socket
    if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        cout << "client("<<getpid()<<"): "<<strerror(errno)<<endl;
        exit(-1);
    }

    addr.sun_family = AF_UNIX;
    //Set the socket path to a local socket file
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);

    //Connect to the local socket
    if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        cout << "client("<<getpid()<<"): " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

    is_running=true;
    while(is_running) {
        ret = read(fd,buf,BUF_LEN);//Read something from the server
        if(ret<0) {
            cout<<"client("<<getpid()<<"): error reading the socket"<<endl;
            cout<<strerror(errno)<<endl;
        }
	if(strcmp(buf, "Pid")==0) {//Server requests the pid of the client
            cout<<"client("<<getpid()<<"): received request for pid"<<endl;
            len = sprintf(buf, "This client has pid %d", getpid())+1;
            ret = write(fd, buf, len);//The client writes the pid to the server
            if(ret==-1) {
               cout<<"client("<<getpid()<<"): Write Error"<<endl;
               cout<<strerror(errno)<<endl;
            }
	    sleep(6);//delay 6 seconds
	    //Now send the parent pid
            len = sprintf(buf, "This client has parent pid %d", getppid())+1;
            ret = write(fd, buf, len);//The client writes the parent pid to the server
            if(ret==-1) {
               cout<<"client("<<getpid()<<"): Write Error"<<endl;
               cout<<strerror(errno)<<endl;
            }
	    sleep(6);//delay 6 seconds
	    //Now send the process name
            len = sprintf(buf, "This client has process name %s", argv[0])+1;
            ret = write(fd, buf, len);//The client writes the parent pid to the server
            if(ret==-1) {
               cout<<"client("<<getpid()<<"): Write Error"<<endl;
               cout<<strerror(errno)<<endl;
            }
        } else if(strcmp(buf, "Quit")==0) {//Server requests the client to terminate
            cout<<"client("<<getpid()<<"): received request to quit"<<endl;
            is_running = false;
        }
    }

    cout<<"client("<<getpid()<<"): stopping..."<<endl;
    close(fd);
    return 0;
}
