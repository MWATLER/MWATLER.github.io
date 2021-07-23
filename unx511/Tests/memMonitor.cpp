//memMonitor.cpp - memory monitor
//
// 19-Jul-21  M. Watler         Created.
//
#include <iostream>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <fstream>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "memoryUsage.h"

using namespace std;

const int MAXBUF=64;
bool isRunning;

static void sigHandler(int sig) {
    switch(sig) {
        case SIGINT:
            cout<<"memMonitor: SIGINT received"<<endl;
            isRunning = false;
            break;
        case SIGKILL:
            cout<<"memMonitor: SIGKILL ignored"<<endl;
            break;
    }
}

int main(int argc, char *argv[])
{
    int fd, fdOut;
    int entropyCount;
    int retVal=0;

    fd=open(keyFile, O_RDONLY);
    //Question 19: What does this ioctl do?
    int status = ioctl(fd, RNDGETENTCNT, &entropyCount);
    if(status<0) {
        cout<<strerror(errno)<<endl;
        retVal=-1;
    }
    if(entropyCount>10) {
    //Question 20: Why do we stop the program if entropyCount>10 ?
        cout<<"memMonitor: Permission not granted"<<endl;
        retVal=-2;
    }
    close(fd);

    if(retVal==0) {
        //Question 21: What happens if memMonitor receives a SIGKILL?
        //Question 22: What happens if memMonitor receives a ctrl-C?
        struct sigaction action;
        action.sa_handler = sigHandler;
        sigemptyset(&action.sa_mask);
        action.sa_flags = 0;
        sigaction(SIGINT, &action, NULL);

        //Question 23: Describe these open flags and file permissions
        int openFlags = O_RDWR | O_CREAT | O_APPEND;
        mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
        fdOut = open(logFile, openFlags, filePerms);
        string modelName, cpuMhz;
        string MemTotal, MemFree, MemAvailable;
        string procRunning, procBlocked;
        string uptime, idle;
        ifstream infile;
	isRunning = true;

        while(isRunning) {
	    //Question 24: What is contained in /proc/cpuinfo?
            infile.open("/proc/cpuinfo");
            if(infile.is_open()) {
                string data;
                bool dataFound = false;
                while(!dataFound && !infile.eof()) {
                    infile >> data;
                    // Search for model name
                    if(data=="model") {
                        infile >> data;
                        if(data=="name") {
                            infile >> data;
                            getline(infile, modelName);
                        }
                    // Search for cpu speed
                    } else if(data=="cpu") {
                        infile >> data;
                        if(data=="MHz") {
                            infile >> cpuMhz;
                            infile >> cpuMhz;
                            dataFound = true;
                        }
                    }
                }
                infile.close();
            }

	    //Question 25: What is contained in /proc/meminfo?
            infile.open("/proc/meminfo");
            if(infile.is_open()) {
                string data;
                infile >> data;
                infile >> MemTotal;
                infile >> data;
                infile >> data;
                infile >> MemFree;
                infile >> data;
                infile >> data;
                infile >> MemAvailable;
                infile.close();
            }

	    //Question 26: What is contained in /proc/stat?
            infile.open("/proc/stat");
            if(infile.is_open()) {
            string data;
                bool dataFound = false;
                while(!dataFound && !infile.eof()) {
                    infile >> data;
                    if(data=="procs_running") {
                        infile >> procRunning;
                    } else if(data=="procs_blocked") {
                        infile >> procBlocked;
                        dataFound = true;
                    }
                }
                infile.close();
            }
    
	    //Question 27: What is contained in /proc/uptime?
            infile.open("/proc/uptime");
            if(infile.is_open()) {
                infile >> uptime;
                infile >> idle;
                infile.close();
            }
    
            // Display all stats and then sleep
            char buf[MAXBUF];
	    int len=sprintf(buf, "Model Name: %s CPU MHz: %s\n", modelName.c_str(), cpuMhz.c_str());
	    write(fdOut, buf, len);
	    len=sprintf(buf, "Mem Total: %s Mem Free: %s Mem Avail:%s\n", MemTotal.c_str(), MemFree.c_str(), MemAvailable.c_str());
	    write(fdOut, buf, len);
	    len=sprintf(buf, "Procs Running: %s Procs Blocked: %s\n", procRunning.c_str(), procBlocked.c_str());
	    write(fdOut, buf, len);
	    len=sprintf(buf, "System Uptime: %s System Idle: %s\n\n", uptime.c_str(), idle.c_str());
	    write(fdOut, buf, len);
            sleep(1);
        }
        close(fdOut);
    }

    return 0;
}
