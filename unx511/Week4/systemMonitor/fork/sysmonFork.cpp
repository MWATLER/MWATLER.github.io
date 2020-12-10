//sysmonFork.cpp - A system monitor using fork
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
bool isRunning=true;
bool isParent = true;//Distinguishes between the parent
                     //process and the child process(es)
pid_t childPid[NUM];
char intf[][MAXBUF]={"lo", "ens33"};

int main()
{

    cout << endl << "parent:main: pid:" << getpid() << endl;
    for(int i=0; i<NUM & isParent; ++i) {
        childPid[i] = fork();
        if(childPid[i]==0) {//the child
            isParent=false;
            intfMonitor(intf[i]);
        }
    }
    if(isParent) {
        sleep(1);
        systemMonitor();
    }

    cout << "pid:" << getpid() << " This is a common area" << endl;
    cout << "pid:" << getpid() << " Finished!" << endl;

    return 0;
}

int intfMonitor(char* interface)//run by the child process(es)
{
    int retVal=0;
    const char logfile[]="Network.log";//store network data in Network.log
    char statPath[MAXBUF];
    int fd=open(logfile, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    cout<<"child:intfMonitor("<<interface<<"):  pid:"<<getpid()<<endl;

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

int systemMonitor()//run by the parent process
{
    int status=-1;
    pid_t pid=0;

    while(isRunning && pid>=0) {
        cout << "parent:systemMonitor: pid:"<<getpid()<<endl;
        pid=wait(&status);//blocking. waitpid() is non-blocking and
	                  //waits for a specific pid to terminate
        cout << "parent:systemMonitor: status:"<<status<<". The child pid:"<<pid<<" has finished"<< endl;
	//find the child that has terminated and restart it.
	bool isFound=false;
	for(int i=0; i<NUM && isParent && !isFound; ++i) {
            if(pid==childPid[i]) {
                isFound=true;
                cout<<"parent:systemMonitor: Restart the child process for "<<intf[i]<<endl;
                childPid[i] = fork();
                if(childPid[i]==0) {//the child
                    isParent=false;
                    intfMonitor(intf[i]);
                }
            }	
        }
    }

    return 0;
}
