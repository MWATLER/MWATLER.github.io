// client2.cpp - An exercise with named semaphores
//
// 02-Dec-20  M. Watler         Created.
//
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/stat.h>
#include "client.h"

using namespace std;

bool is_running;

static void interruptHandler(int signum)
{
    switch(signum) {
        case SIGINT:
            cout<<"interruptHandler("<<signum<<"): SIGINT"<<endl;
            is_running=false;
            break;
    }
}

int main(void) {
    sem_t *sem_id;
    int fd; 
    char buf[BUF_LEN];
    int offset=0;

    struct sigaction action;
    action.sa_handler = interruptHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    // initialize named semaphore, can be used between processes
    sem_id = sem_open(SEMNAME, O_CREAT, SEM_PERMS, 0);

    is_running=true;
    while(is_running) {
        memset(buf, 0, BUF_LEN);
        sem_wait(sem_id);
        fd = open(FILENAME, O_RDONLY);
	if(fd>0) {
	    int ret = pread(fd, buf, BUF_LEN-1, offset);
	    if(ret>0) {
	        cout<<"client2: "<<buf<<endl;
		offset += ret;
            }
	    close(fd);
	}
	sem_post(sem_id);
	if(offset>3000) offset=0;
	sleep(1);
    }

    cout<<"client2: quitting..."<<endl;
    close(fd);
    sem_close(sem_id);
    sem_unlink(SEMNAME);

    return 0;
}
