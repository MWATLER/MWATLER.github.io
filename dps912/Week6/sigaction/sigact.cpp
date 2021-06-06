//sigact.cpp - Parent creates four children and shuts them down one by one
//
// 10-Feb-19  M. Watler         Created.

#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

void ProcessChild(int childNo);
void ProcessParent(int child[]);
bool isRunning;

int main() {
    const int numChildren=4;
    int childPid[numChildren];

    for(int i=0; i<numChildren; ++i) {
        pid_t id = fork();
        if(id==0) {
            char childNo[5];
	    sprintf(childNo, "%d", i);
            execlp("./processChild", "./processChild", childNo, NULL);
        } else {
            childPid[i]=id;
	}
    }

    sleep(10);
    //Stop child 2
    cout<<"ProcessParent: Stopping child 2"<<endl;
    kill(childPid[2], SIGINT);
    sleep(10);
    //Stop child 1
    cout<<"ProcessParent: Stopping child 1"<<endl;
    kill(childPid[1], SIGINT);
    sleep(10);
    //Stop child 3
    cout<<"ProcessParent: Stopping child 3"<<endl;
    kill(childPid[3], SIGINT);
    sleep(10);
    //Stop child 0
    cout<<"ProcessParent: Stopping child 0"<<endl;
    kill(childPid[0], SIGINT);
    cout<<"ProcessParent: DONE."<<endl;

    return 0;
}
