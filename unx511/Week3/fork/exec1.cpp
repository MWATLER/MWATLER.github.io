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
    char *args[3] = {"ls", "-al", NULL};

    cout << endl << "pid:" << getpid() << " Hello World" << endl;
    childPid = fork();
    if(childPid==0) {
	for(int i=0; i<3; ++i) {
            sleep(1);
	    ++data;
            cout << "Child: i:" << i << " data:" << data << endl;
	}
	cout << "Child: executing ls -al" << endl;
	execvp(args[0], args);
	cout << "Child: finished executing ls -al" << endl;
    } else {
        cout << "Parent: pid:" << getpid() << " childPid:" << childPid << endl;
	for(int i=0; i<3; ++i) {
            sleep(1);
	    ++data;
            cout << "Parent: i:" << i << " data:" << data << endl;
	}
    }

    cout << "pid:" << getpid() << " This is a common area" << endl;
    cout << "pid:" << getpid() << " Finished!" << endl;

    return 0;
}
