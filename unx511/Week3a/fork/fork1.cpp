//fork1.cpp - Test the fork() function in Linux
//
// 01-Feb-19  M. Watler         Created.

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main() {
    int data=1;
    pid_t childPid;

    cout << endl << "pid:" << getpid() << " Hello World" << endl;
    childPid = fork();
    if(childPid==0) {//the child
        cout << "Child: pid:" << getpid() << endl;
	for(int i=0; i<10; ++i) {
            sleep(1);
            cout << "Child [" << getpid() << "]: i:" << i << " data:" << data << endl;
	}
    } else {//the parent
        cout << "Parent: pid:" << getpid() << endl;
	for(int i=0; i<10; ++i) {
            sleep(1);
	    ++data;
            cout << "Parent [" << getpid() << "]: i:" << i << " data:" << data << endl;
	}
    }

    cout << "pid:" << getpid() << " This is a common area" << endl;
    cout << "pid:" << getpid() << " Finished!" << endl;

    return 0;
}
