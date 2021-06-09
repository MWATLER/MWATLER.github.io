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
    while (is_running) {
        sem_wait(&semaphore);
        cout<<"threadfunc: Hello from da thread!"<<endl;
        sleep(1);
        sem_post(&semaphore);
    }
    cout<<"threadfunc: exiting..."<<endl;
    pthread_exit(NULL);
}

int main(void) {
    
    string keyInput;

    // initialize semaphore, only to be used with threads in this process, set value to 1
    sem_init(&semaphore, 0, 1);
    
    pthread_t tid;
    
    // start the thread
    is_running=true;
    cout<<"main: Starting the thread"<<endl;
    pthread_create(&tid, NULL, threadfunc, NULL);
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
    pthread_join(tid, NULL);
    sem_destroy(&semaphore);

    cout<<"main: exiting..."<<endl;
    return 0;
}
