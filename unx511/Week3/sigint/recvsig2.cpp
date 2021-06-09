//recvsig2.cpp - Process for receiving a signal
//               This program handles various signals
//
// 08-Feb-19  M. Watler         Created.

#include <errno.h>
#include <signal.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

static void sigHandler(int sig);

int main ( ) {
   cout<<"This process id is "<<getpid()<<". Waiting for SIGINT."<<endl;
   sighandler_t err1=signal(SIGINT, sigHandler);
   sighandler_t err2=signal(SIGUSR1, sigHandler);
   sighandler_t err3=signal(SIGUSR2, sigHandler);
   if(err1==SIG_ERR || err2==SIG_ERR || err3==SIG_ERR) {
       cout<<"Cannot create the signal handler"<<endl;
       cout<<strerror(errno)<<endl;
       return -1;
   }
   for (int i=0;i<300;++i) {
       cout<<"recvsig2: "<<i<<" seconds"<<endl;
       sleep(1);
   }
   cout<<"DONE!"<<endl;
   return 0;
}

static void sigHandler(int sig)
{
    switch(sig) {
        case SIGINT:
            cout<<"sigHandler: SIGINT I refuse to go down"<<endl;
            for (int i=0;i<5;++i) {
                cout<<"sigHandler: SIGINT "<<i<<" seconds"<<endl;
                sleep(1);
            }
	    break;
        case SIGUSR1:
            cout<<"sigHandler: SIGUSR1 I refuse to go down"<<endl;
            for (int i=0;i<5;++i) {
                cout<<"sigHandler: SIGUSR1 "<<i<<" seconds"<<endl;
                sleep(1);
            }
	    break;
        case SIGUSR2:
            cout<<"sigHandler: SIGUSR2 I refuse to go down"<<endl;
            for (int i=0;i<5;++i) {
                cout<<"sigHandler: SIGUSR2 "<<i<<" seconds"<<endl;
                sleep(1);
            }
	    break;
	default:
	    cout<<"sigHandler: Undefined signal"<<endl;
    }
}
