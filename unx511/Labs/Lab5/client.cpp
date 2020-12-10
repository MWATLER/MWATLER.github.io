//client.cpp - client code for Lab6
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

char socket_path[]="/tmp/lab5";
bool is_running;
const int BUF_LEN=100;

int main()
{
    //Set up socket communications
    struct sockaddr_un addr;
    char buf[BUF_LEN];
    int len, ret;
    int fd,rc;

    memset(&addr, 0, sizeof(addr));
    //Create the socket
    if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        cout << "client: "<<strerror(errno)<<endl;
        exit(-1);
    }

    addr.sun_family = AF_UNIX;
    //Set the socket path to a local socket file
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);

    //Connect to the local socket
    if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        cout << "client1: " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

    is_running=true;
    while(is_running) {
        ret = read(fd,buf,BUF_LEN);
        if(ret<0) {
            cout<<"client: error reading the socket"<<endl;
            cout<<strerror(errno)<<endl;
        }
	if(strcmp(buf, "Pid")==0) {
            cout<<"A request for the client's pid has been received"<<endl;
            len=sprintf(buf, "This client has pid %d", getpid()) + 1;
            ret = write(fd, buf, len);
            if(ret==-1) {
                cout<<"client: Write Error"<<endl;
                cout<<strerror(errno)<<endl;
            }
        } else if(strcmp(buf, "Sleep")==0) {
            cout<<"This client is going to sleep for 5 seconds"<<endl;
            sleep(5);
            len = sprintf(buf, "Done") + 1;
            ret = write(fd, buf, len);
            if(ret==-1) {
                cout<<"client: Write Error"<<endl;
                cout<<strerror(errno)<<endl;
            }
        } else if(strcmp(buf, "Quit")==0) {
            cout<<"This client is quitting"<<endl;
            is_running = false;
        }
    }

    close(fd);
    return 0;
}
