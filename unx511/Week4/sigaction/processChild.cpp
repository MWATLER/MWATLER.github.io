//processChild.cpp - Child process for sigact.cpp
//
// 01-Oct-20  M. Watler         Created.

#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

static void interruptHandler(int signum);
bool isRunning;

int main(int argc, char* argv[]) {
    int childNo = atoi(argv[1]);

    int *seconds;
    struct sigaction action;

    //For sigaction, see http://man7.org/linux/man-pages/man2/sigaction.2.html
    action.sa_handler = interruptHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    sigaction(SIGSTOP, &action, NULL);
    sigaction(SIGTSTP, &action, NULL);

    seconds=new int;
    *seconds = 0;
    isRunning = true;
    while(isRunning) {
        cout<<"ProcessChild("<<childNo<<"): "<<*seconds<<" seconds"<<endl;
	sleep(1);
	++*seconds;
    }
    cout<<"ProcessChild("<<childNo<<"): Cleaning up"<<endl;
    delete seconds;
    cout<<"ProcessChild("<<childNo<<"): DONE."<<endl;

    return 0;
}

static void interruptHandler(int signum)
{
    switch(signum) {
        case SIGINT:
            cout<<"interruptHandler("<<signum<<"): SIGINT"<<endl;
            isRunning=false;
	    break;
        case SIGUSR1:
            cout<<"interruptHandler("<<signum<<"): SIGUSR1"<<endl;
	    break;
        case SIGUSR2:
            cout<<"interruptHandler("<<signum<<"): SIGUSR2"<<endl;
	    break;
        case SIGSTOP:
            cout<<"interruptHandler("<<signum<<"): SIGSTOP"<<endl;
            cout<<"interruptHandler("<<signum<<"): I do not want to stop!"<<endl;
	    break;
        case SIGTSTP:
            cout<<"interruptHandler("<<signum<<"): SIGTSTP"<<endl;
            cout<<"interruptHandler("<<signum<<"): I do not want to stop!"<<endl;
	    break;
        default:
            cout<<"interruptHandler("<<signum<<"): Undefined signal"<<endl;
    }
}
