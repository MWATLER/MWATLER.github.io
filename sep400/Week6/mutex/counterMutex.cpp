//counterMutex.cpp - Demo code to demonstrate the need for mutexes
//
// 21-Mar-19  M. Watler         Created.
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
bool is_running;
pthread_mutex_t lock_x;

static void shutdownHandler(int sig)
{
    switch(sig) {
        case SIGINT:
            is_running = false;
	    break;
    }
}

int main(void)
{
    count=0;
    pthread_t tid[2];

    signal(SIGINT, shutdownHandler);

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
	pthread_mutex_lock(&lock_x);
        cout<<"countThread1: count:"<<count<<endl;
        --count;
	sleep(1);
        ++count;
	sleep(1);
        ++count;
        cout<<"countThread1: count:"<<count<<endl<<endl;
	pthread_mutex_unlock(&lock_x);
	sleep(1);
    }

    pthread_exit(NULL);
    
}

void *countThread2(void *arg)
{
    while(is_running) {
	pthread_mutex_lock(&lock_x);
        cout<<"countThread2: count:"<<count<<endl;
        ++count;
        cout<<"countThread2: count:"<<count<<endl<<endl;
	pthread_mutex_unlock(&lock_x);
	sleep(1);
    }

    pthread_exit(NULL);
}

