//sysmonExec.cpp - A system monitor using fork and exec
//
// 05-Feb-20  M. Watler         Created.

#include <fcntl.h>
#include <fstream>
#include <cstring>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;
const int NUM=2;
const int MAXBUF=64;

int systemMonitor();
bool isRunning=true;
bool isParent = true;//Distinguishes between the parent
                     //process and the child process(es)
pid_t childPid[NUM];

char *args[][3] = {{"./intfMonitor", "lo", NULL},
                   {"./intfMonitor", "ens33", NULL}};

int main()
{
//  char *intf[]={"lo", "ens33"};
    cout << endl << "parent:main: pid:"<<getpid()<<endl;
    for(int i=0; i<NUM & isParent; ++i) {
        childPid[i] = fork();
        if(childPid[i]==0) {//the child
            cout << "child:main: pid:"<<getpid()<<endl;
            isParent=false;
            execvp(args[i][0], args[i]);
//          execlp("./intfMonitor", "./intfMonitor", intf[i], NULL);
            cout << "child:main: pid:"<<getpid()<<" I should not get here!"<<endl;
	    cout<<strerror(errno)<<endl;
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
                cout<<"parent:systemMonitor: Restart the child process"<<endl;
                childPid[i] = fork();
                if(childPid[i]==0) {//the child
                    cout << "child:main: pid:"<<getpid()<<endl;
                    isParent=false;
                    execvp(args[i][0], args[i]);
                    cout << "child:main: pid:"<<getpid()<<" I should not get here!"<<endl;
	            cout<<strerror(errno)<<endl;
                }
            }	
        }
    }

    return 0;
}
