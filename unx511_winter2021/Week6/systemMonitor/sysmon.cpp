//sysmon.cpp - A system monitor
//
// 31-Jan-20  M. Watler         Created.

#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;
const int NUM=2;
const int MAXBUF=64;

int intfMonitor(char*);
int systemMonitor();

int main()
{
    pid_t childPid[NUM];
    char intf[][MAXBUF]={"lo", "ens33"};

    cout << endl << "sysmon: pid:" << getpid() << endl;
    for(int i=0; i<NUM; ++i) {
        childPid[i] = fork();
        if(childPid[i]==0) {//the child
            intfMonitor(intf[i]);
        }
    }
    sleep(1);
    systemMonitor();

    cout << "pid:" << getpid() << " This is a common area" << endl;
    cout << "pid:" << getpid() << " Finished!" << endl;

    return 0;
}

int intfMonitor(char* interface)
{
    int retVal=0;
    const char logfile[]="Network.log";
    char statPath[MAXBUF];
    bool isRunning=true;
    int fd=open(logfile, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    cout<<"intfMonitor["<<getpid()<<"]: "<<interface<<endl;

    while(isRunning) {
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
	int len=sprintf(data, "%s: tx_bytes:%d rx_bytes:%d tx_packets:%d rx_packets: %d\n", interface, tx_bytes, rx_bytes, tx_packets, rx_packets);
	write(fd, data, len);
	sleep(1);
    }
    close(fd);

    return 0;
}

int systemMonitor()
{
    int status=-1;
    pid_t pid=0;


    while(pid>=0 && status<0) {
        cout << "systemMonitor["<<getpid()<<"]: pid=wait(&status)"<<endl;
        pid=wait(&status);
        if(status==0) {
            cout << "systemMOnitor["<<getpid()<<"]: The child has finished" << pid << endl;
        }
    }

    return 0;
}
