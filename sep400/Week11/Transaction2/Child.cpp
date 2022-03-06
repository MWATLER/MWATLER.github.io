//Transaction.cpp - A transaction application between parent and forked process with the mapping application
//
// History:
// 06-Mar-22  M. Watler         Created.

#include <fcntl.h>
#include <iostream>
#include <signal.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Transaction.h"

using namespace std;

bool is_running;
Transaction *trans;

int main() {
    int retVal = 0;
    int selection;
    double amount;
    pthread_t tid;
    const char TransFile[]="/dev/zero";
    struct sigaction action;
    int size = sizeof(Transaction);

    int fd=open(TransFile, O_RDWR);
    if(fd==-1) {
        cout<<"CHILD: Cannot open "<<TransFile<<endl;
        cout<<strerror(errno)<<endl;
        retVal = -10;
    }

    if(retVal==0){
        action.sa_handler = sigHandler;
        sigemptyset(&action.sa_mask);
        action.sa_flags = 0;
        sigaction(SIGINT, &action, NULL);

        trans = (Transaction *)mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, fd, 0);
	if(trans == MAP_FAILED) {
	    cout<<"CHILD: mmap failed"<<endl;
	    cout<<strerror(errno)<<endl;
            retVal = -1;
        }
    }

    if(retVal==0) {//start off a thread to display information
	trans->accountNumber = 1000123;
	trans->transitNumber = 415;
        int ret = pthread_create(&tid, NULL, display_func, NULL);
	if(ret!=0) {
	    cout<<"CHILD: pthread_create failed"<<endl;
	    cout<<strerror(errno)<<endl;
            retVal = -2;
            munmap(trans, size);
        }
    }
    if(retVal==0) {
        is_running=true;
        while(is_running) {
            trans->balance += 2000;//add money every two weeks
            msync(trans, size, MS_SYNC);
            sleep(2);//sleep for two weeks
        }
    }

    if(retVal==0) {
        pthread_join(tid, NULL);
        munmap(trans, size);
    }

    return retVal;
}

void *display_func(void *arg) {
    while(is_running) {
        cout<<"CHILD:"<<trans->accountNumber<<" "<<trans->transitNumber<<" balance $"<<trans->balance<<endl<<endl;
        sleep(2);//see the balance each 2 weeks
    }
    pthread_exit(NULL);
}

static void sigHandler(int sig) {
    switch(sig) {
        case SIGINT:
            cout<<"Shutting down..."<<endl;
            is_running=false;
        break;
    }
}

