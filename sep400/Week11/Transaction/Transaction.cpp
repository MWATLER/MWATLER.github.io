//Transaction.cpp - A transaction application between parent and child with the mapping application
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
    int pid;

   struct sigaction action;
   action.sa_handler = sigHandler;
   sigemptyset(&action.sa_mask);
   action.sa_flags = 0;
   sigaction(SIGINT, &action, NULL);

    int size = sizeof(Transaction);
    if(retVal==0) {
        trans = (Transaction *)mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
	if(trans == MAP_FAILED) {
	    cout<<"ERROR: mmap failed"<<endl;
	    cout<<strerror(errno)<<endl;
            retVal = -1;
        }
    }

    if(retVal==0) {//start off a thread to display information
        pid=fork();
	trans->accountNumber = 1000123;
	trans->transitNumber = 415;
        int ret = pthread_create(&tid, NULL, display_func, &pid);
	if(ret!=0) {
	    cout<<"ERROR: pthread_create failed"<<endl;
	    cout<<strerror(errno)<<endl;
            retVal = -2;
            munmap(trans, size);
        }
    }
    if(retVal==0) {
        if(pid==0) {//child operations
            is_running=true;
            while(is_running) {
                trans->balance += 2000;//add money every two weeks
                msync(trans, size, MS_SYNC);
                sleep(2);//sleep for two weeks
             }
        } else {//parent process
             is_running=true;
             while(is_running) {
                trans->balance -= 4000;//remove 4000 every five weeks
                msync(trans, size, MS_SYNC);
                sleep(5);//sleep for five weeks
             }
        }
    }

    if(retVal==0) {
        pthread_join(tid, NULL);
        munmap(trans, size);
    }

    return retVal;
}

void *display_func(void *arg) {
    int pid = *(int *)arg;
    system("clear");

    if(pid==0) {//child process
        while(is_running) {
            cout<<"CHILD:"<<trans->accountNumber<<" "<<trans->transitNumber<<" balance $"<<trans->balance<<endl<<endl;
            sleep(2);//see the balance each 2 weeks
        }

    } else {//parent process
        while(is_running) {
            cout<<"PARENT:"<<trans->accountNumber<<" "<<trans->transitNumber<<" balance $"<<trans->balance<<endl<<endl;
            sleep(2);//see the balance each 5 weeks
        }
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

