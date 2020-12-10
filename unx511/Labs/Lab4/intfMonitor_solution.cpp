//intfMonitor_solution.cpp - An interface monitor
//
// 07-Jul-20  M. Watler         Created.

#include <fcntl.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

const int MAXBUF=128;
bool isRunning=false;

//TODO: Declare your signal handler function prototype
static void sigHandler(int sig);

int main(int argc, char *argv[])
{
    //TODO: Declare a variable of type struct sigaction
    //      For sigaction, see http://man7.org/linux/man-pages/man2/sigaction.2.html
    struct sigaction action;
    int err1, err2, err3, err4;

    char interface[MAXBUF];
    char statPath[MAXBUF];
    const char logfile[]="Network.log";//store network data in Network.log
    int retVal=0;

    //TODO: Register signal handlers for SIGUSR1, SIGUSR2, ctrl-C and ctrl-Z
    action.sa_handler = sigHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    err1=sigaction(SIGUSR1, &action, NULL);
    err2=sigaction(SIGUSR2, &action, NULL);
    err3=sigaction(SIGINT, &action, NULL);
    err4=sigaction(SIGTSTP, &action, NULL);
    //TODO: Ensure there are no errors in registering the handlers
    if(err1!=0 || err2!=0 || err3!=0 || err4!=0) {
        cout<<"intfMonitor:main: interface:"<<interface<<": Cannot create the signal handler"<<endl;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    strncpy(interface, argv[1], MAXBUF);//The interface has been passed as an argument to intfMonitor
    int fd=open(logfile, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    cout<<"intfMonitor:main: interface:"<<interface<<":  pid:"<<getpid()<<endl;

    //TODO: Wait for SIGUSR1 - the start signal from the parent
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

//TODO: Create a signal handler that starts your program on SIGUSR1 (sets isRunning to true),
//      stops your program on SIGUSR2 (sets isRunning to false),
//      and discards any ctrl-C or ctrl-Z.
static void sigHandler(int sig)
{
    switch(sig) {
        case SIGUSR1:
            isRunning=true;
            cout<<"intfMonitor("<<getpid()<<") sigHandler: starting up"<<endl;
        break;
        case SIGINT:
            isRunning=true;
            cout<<"intfMonitor("<<getpid()<<") sigHandler: ctrl-C discarded"<<endl;
        break;
        case SIGTSTP:
            isRunning=true;
            cout<<"intfMonitor("<<getpid()<<") sigHandler: ctrl-Z discarded"<<endl;
        break;
        case SIGUSR2:
            isRunning=false;
            cout<<"intfMonitor("<<getpid()<<") sigHandler: shutting down"<<endl;
        break;
        default:
            cout<<"intfMonitor("<<getpid()<<") sigHandler: Undefined signal"<<endl;
    }
}
