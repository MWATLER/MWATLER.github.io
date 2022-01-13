//deadlock.cpp - Demo code to demonstrate deadlocking with mutexes
//               Could use pthread_mutex_timedlock() to avoid this.
//
// 04-Aug-20  M. Watler         Created.
//
#include <errno.h>
#include <iostream>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void *countThread1(void *arg);
void *countThread2(void *arg);

using namespace std;

int count;
bool is_done;
bool is_running;
pthread_mutex_t lock_x;

static void shutdownHandler(int sig)
{
    switch(sig) {
        case SIGINT:
            is_done = true;
            is_running = false;
	    break;
    }
}

int main(void)
{
    count=0;
    pthread_t tid[2];
    struct sigaction action;

    //For sigaction, see http://man7.org/linux/man-pages/man2/sigaction.2.html
    action.sa_handler = shutdownHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    pthread_mutex_init(&lock_x, NULL);
    is_running=true;
    int ret = pthread_create(&tid[0], NULL, countThread1, NULL);
    if(ret!=0) {
        cout<<"Cannot create countThread1"<<endl;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    ret = pthread_create(&tid[1], NULL, countThread2, NULL);
    if(ret!=0) {
        cout<<"Cannot create countThread2"<<endl;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock_x);

    return 0;
}

void *countThread1(void *arg)
{
    cout<<"countThread1: The purpose of countThread1 is to take"<<endl;
    cout<<"              the variable count and increment it by one."<<endl;
    while(is_running) {
        is_done=false;
	sleep(0.5);
        cout<<"countThread1: pthread_mutex_lock() is_done:"<<is_done<<" count:"<<count<<endl;
	pthread_mutex_lock(&lock_x);
        --count;
	sleep(1);
        ++count;
	sleep(1);
        ++count;
	while(is_done==false) {
            cout<<"countThread1: sleep(1) is_done:"<<is_done<<" count:"<<count<<endl<<endl;
            sleep(1);
        }
        cout<<"countThread1: pthread_mutex_lock() is_done:"<<is_done<<" count:"<<count<<endl<<endl;
	pthread_mutex_unlock(&lock_x);
    }

    pthread_exit(NULL);
    
}

void *countThread2(void *arg)
{
    while(is_running) {
        cout<<"countThread2: pthread_mutex_lock() is_done:"<<is_done<<" count:"<<count<<endl;
	pthread_mutex_lock(&lock_x);
        ++count;
        is_done=true;
        cout<<"countThread2: pthread_mutex_unlock() is_done:"<<is_done<<" count:"<<count<<endl<<endl;
	pthread_mutex_unlock(&lock_x);
	sleep(1);
    }

    pthread_exit(NULL);
}

