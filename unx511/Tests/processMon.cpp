//processMon.cpp - A process monitor for memory usage
//
// 19-Jul-21  M. Watler         Created.

#include <fcntl.h>
#include <fstream>
#include <cstring>
#include <iostream>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "memoryUsage.h"

using namespace std;
const int NUM=2;
const int MAXBUF=64;

int processMonitor();
bool isRunning;
bool isParent;

pid_t childPid[NUM];
int fd;

char args[NUM][MAXBUF] = {"./fileMon", "./memMonitor"};

static void sigHandler(int sig) {
    switch(sig) {
        case SIGINT:
            cout<<"processMonitor: SIGINT received"<<endl;
	    isRunning = false;
	    break;
    }
}

int main()
{
    //Question 4: What happens if the following is executed from the command line: "pkill -2 processMon"
    struct sigaction action;
    action.sa_handler = sigHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);
    //Question 5: Is keyFile really a file?
    fd=open(keyFile, O_RDONLY);
    isParent = true;
    for(int i=0; i<NUM && isParent; ++i) {
        //Question 6: NOTE: The random number generator in the Linux kernel uses an entropy counter that increments gradually with time.
	//Question 6: NOTE: For this ioctl to work, you have to run this program as superuser.
        //Question 6: What is this ioctl doing?
        int status = ioctl(fd, RNDZAPENTCNT, 0);
        if(status<0) std::cout<<strerror(errno)<<std::endl;
        childPid[i] = fork();
	//Question 7: How many processes are running at this point?
        if(childPid[i]==0) {//the child
            isParent=false;
            //Question 8: Why am I closing the file here?
	    close(fd);
            execlp(args[i], args[i], NULL);
            //Question 9: Why is it an error if the program continues beyond execlp()?
	    cout<<strerror(errno)<<endl;
        }
    }
    if(isParent) {
        sleep(1);
        processMonitor();
    }

    for(int i=0; i<NUM; ++i) {
        //Question 10: What function in the child processes is called when they receive a SIGINT?
        kill(childPid[i], SIGINT);
    }
    cout << "pid:" << getpid() << " Finished!" << endl;

    close(fd);

    return 0;
}

int processMonitor()
{
    int status=-1;
    pid_t pid=0;

    isRunning = true;
    while(isRunning && pid>=0) {
        //Question 11: What are we waiting on here?
        pid=wait(&status);
        //Question 12: What does it mean if pid is negative?
        //Question 13: What does it mean if pid is positive?
	char buf[MAXBUF];
        //Question 14: What is processMon attempting to do with the log file?
        int openFlags = O_RDWR | O_CREAT | O_APPEND;
        mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
	int fdLog = open(logFile, openFlags, filePerms);
	int len=sprintf(buf, "\nprocessMonitor: status:%d The child pid:%d has finished\n", status, pid);
	write(fdLog, buf, len);
	bool isFound=false;
	for(int i=0; i<NUM && isParent && !isFound; ++i) {
            //Question 15: What are we looking for here?
            if(pid==childPid[i]) {
                isFound=true;
	        len=sprintf(buf, "processMonitor: Restart the child process\n\n");
		write(fdLog, buf, len);
		//Question 16: Why are we executing this ioctl again?
                int status = ioctl(fd, RNDZAPENTCNT, 0);
		if(status<0) cout<<strerror(errno)<<endl;
                childPid[i] = fork();
                if(childPid[i]==0) {//the child
		//Question 17: How many processes are running here?
                    isParent=false;
		    close(fd);
		    //Question 18: Why are we invoking execlp() again here?
                    execlp(args[i], args[i], NULL);
	            cout<<strerror(errno)<<endl;
                }
            }	
        }
        close(fdLog);
	sleep(1);
    }

    return 0;
}
