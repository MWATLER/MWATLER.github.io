//uninterrupt.cpp - Process that is uninterruptible via ctrl-C or ctrl-Z
//
// 14-Feb-19  M. Watler         Created.

#include <errno.h>
#include <signal.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

static void sigHandler(int sig);

int main ( ) {
   struct sigaction action;
   action.sa_handler = sigHandler;
   sigemptyset(&action.sa_mask);
   action.sa_flags = 0;

   cout<<"This process id is "<<getpid()<<". It cannot be interrupted with ctrl-C or ctrl-Z."<<endl;
   sigaction(SIGINT, &action, NULL);
   sigaction(SIGTSTP, &action, NULL);
   for (int i=0;i<300;++i) {
       cout<<"uninterrupt: "<<i<<" seconds"<<endl;
       sleep(1);
   }
   cout<<"DONE!"<<endl;
   return 0;
}

static void sigHandler(int sig)
{
    switch(sig) {
        case SIGINT://Do absolutely nothing
            cout<<"sigHandler: SIGINT I refuse to go down"<<endl;
	    break;
        case SIGTSTP://Do absolutely nothing
            cout<<"sigHandler: SIGTSTP I refuse to go down"<<endl;
	    break;
	default:
	    cout<<"sigHandler: Undefined signal"<<endl;
    }
}
