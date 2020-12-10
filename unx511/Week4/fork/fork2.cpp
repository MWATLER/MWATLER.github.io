//fork1.cpp - Test the fork() function in Linux
//
// 01-Feb-19  M. Watler         Created.

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

const int NO_OF_CHILDREN=4;

using namespace std;

int main() {
    pid_t childId;
    bool isParent=true;
    int childNo;

    cout << endl << "parent [" << getpid() << "]: BEGIN" << endl << endl;
    for(childNo=0; childNo<NO_OF_CHILDREN && isParent; ++childNo) {
        childId=fork();
	sleep(1);
        if(childId==0) isParent=false;
    }
    if(isParent) {
        int status;
        pid_t pid=0;
        while(pid>=0) {
            pid=wait(&status);
	    status = status >> 8;//Bits 8-15
	    cout << "pid:" << pid << endl;
	    if(pid>=0) cout << "parent [" << getpid() << "]: child [" << pid << "] " << status << " has terminated." << endl;
	    else       cout << "parent [" << getpid() << "]: no more children." << endl;
        }
    } else {
	for(int data=1; data<=10; ++data) {
            sleep(1);
            cout << "child " << to_string(childNo) << "[" << getpid() << "]: data:" << data << endl;
	}
    }

    cout << "[" << getpid() << "]:  This is a common area" << endl;
    cout << "[" << getpid() << "]:  Finished!" << endl;

    if(!isParent) exit(childNo);
    else exit(0);
}
