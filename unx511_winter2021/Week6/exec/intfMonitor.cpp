//intfMonitor.cpp - An interface monitor
//
// 05-Feb-20  M. Watler         Created.

#include <fcntl.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

const int MAXBUF=64;
bool isRunning=false;

static void sigHandler(int sig);

int main(int argc, char *argv[])
{
    char interface[MAXBUF];
    char statPath[MAXBUF];
    const char logfile[]="Network.log";//store network data in Network.log
    int retVal=0;

    //Register my signal handler
    sighandler_t err1=signal(SIGINT, sigHandler);
    sighandler_t err2=signal(SIGUSR1, sigHandler);
    sighandler_t err3=signal(SIGUSR2, sigHandler);
    if(err1==SIG_ERR || err2==SIG_ERR || err3==SIG_ERR) {
        cout<<"intfMonitor:main: interface:"<<interface<<": Cannot create the signal handler"<<endl;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    strncpy(interface, argv[1], MAXBUF);
    int fd=open(logfile, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    cout<<"intfMonitor:main: interface:"<<interface<<":  pid:"<<getpid()<<endl;

    while(!isRunning) {//Wait for the start signal from the parent
        sleep(0.1);//sleep 100ms
    }

    while(isRunning) {
        //gather some stats
        int tx_bytes=0;
        int rx_bytes=0;
        int tx_packets=0;
        int rx_packets=0;
	ifstream infile;
        sprintf(statPath, "/sys/class/net/%s/statistics/tx_bytes", interface);
	infile.open(statPath);
	if(infile.is_open()) {
	    infile>>tx_bytes;
	    infile.close();
	}
        sprintf(statPath, "/sys/class/net/%s/statistics/rx_bytes", interface);
	infile.open(statPath);
	if(infile.is_open()) {
	    infile>>rx_bytes;
	    infile.close();
	}
        sprintf(statPath, "/sys/class/net/%s/statistics/tx_packets", interface);
	infile.open(statPath);
	if(infile.is_open()) {
	    infile>>tx_packets;
	    infile.close();
	}
        sprintf(statPath, "/sys/class/net/%s/statistics/rx_packets", interface);
	infile.open(statPath);
	if(infile.is_open()) {
	    infile>>rx_packets;
	    infile.close();
	}
	char data[MAXBUF];
	//write the stats into Network.log
	int len=sprintf(data, "%s: tx_bytes:%d rx_bytes:%d tx_packets:%d rx_packets: %d\n", interface, tx_bytes, rx_bytes, tx_packets, rx_packets);
	write(fd, data, len);
	sleep(1);
    }
    close(fd);

    return 0;
}

static void sigHandler(int sig)
{
    switch(sig) {
        case SIGUSR1:
            isRunning=true;
	    cout<<"intfMonitor("<<getpid()<<") sigHandler: starting up"<<endl;
	    break;
        case SIGINT:
        case SIGUSR2:
            isRunning=false;
	    cout<<"intfMonitor("<<getpid()<<") sigHandler: shutting down"<<endl;
	    break;
	default:
            cout<<"intfMonitor("<<getpid()<<") sigHandler: Undefined signal"<<endl;
    }
}
