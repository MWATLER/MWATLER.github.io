#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

using namespace std;

sem_t semaphore;
bool is_running;

void *threadfunc(void *arg) {
    int threadNum = *(int *)arg;
    while (is_running) {
        sem_wait(&semaphore);
        cout<<"threadfunc: Hello from thread "<<threadNum<<endl;
        sleep(1);
        sem_post(&semaphore);
    }
    cout<<"threadfunc: exiting..."<<endl;
    pthread_exit(NULL);
}

int main(void) {
    
    string keyInput;

    // initialize semaphore, only to be used with threads in this process, set value to 1
    sem_init(&semaphore, 0, 2);
    
    pthread_t tid[2];
    int threadNo;
    
    // start the thread
    is_running=true;
    cout<<"main: Starting thread 1"<<endl;
    threadNo=1;
    pthread_create(&tid[0], NULL, threadfunc, &threadNo);
    sleep(1);
    cout<<"main: Starting thread 2"<<endl;
    threadNo=2;
    pthread_create(&tid[1], NULL, threadfunc, &threadNo);
    sleep(3);
    
    sem_wait(&semaphore);
    cout<<"main: Semaphore locked."<<endl;

    cout<<"main: Enter a string: ";
    cin>>keyInput;
    cout<<"main: You entered: "<<keyInput<<endl;
    
    sleep(3);
    sem_post(&semaphore);
    cout<<"main: Semaphore unlocked."<<endl;

    sleep(3);

    is_running=false;
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    sem_destroy(&semaphore);

    cout<<"main: exiting..."<<endl;
    return 0;
}
