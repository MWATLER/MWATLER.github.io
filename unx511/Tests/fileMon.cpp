//fileMon.cpp - log file monitor
//
// 19-Jul-21  M. Watler         Created.
//

#include <fcntl.h>
#include <iostream>
#include <signal.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "memoryUsage.h"

using namespace std;
bool isRunning;
const int MAXBUF=64;
const int THRESHOLD=40000;

static void sigHandler(int sig) {
    //Question 28: Does sigHandler handle anything besides SIGINT?
    switch(sig) {
        case SIGINT:
            cout<<"fileMon: SIGINT received"<<endl;
            isRunning = false;
            break;
    }
}

int main(int argc, char *argv[])
{
    int entropyCount=1000;
    int retVal=0;
    int fd=open(keyFile, O_RDONLY);
    //Question 29: What does this ioctl do?
    int status = ioctl(fd, RNDGETENTCNT, &entropyCount);
    if(status<0) {
        cout<<strerror(errno)<<endl;
	retVal=-1;
    }
    if(entropyCount>10) {
        cout<<"fileMon: Permission not granted"<<endl;
        retVal=-2;
    }
    close(fd);

    if(retVal==0) {
        struct sigaction action;
        action.sa_handler = sigHandler;
        sigemptyset(&action.sa_mask);
        action.sa_flags = 0;
        sigaction(SIGINT, &action, NULL);

        isRunning = true;
        struct stat st;
        while(isRunning) {
            stat(logFile, &st);
            if(st.st_size>THRESHOLD) {
                int openFlags = O_RDWR | O_CREAT | O_TRUNC;
                mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
		//Question 30: What do the following two lines effectively do to the log file?
                fd=open(logFile, openFlags, filePerms);
		close(fd);
            }
            sleep(1);
        }
    }
    return 0;
}
