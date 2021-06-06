// client2.cpp - An exercise with named semaphores
//
// 01-Apr-19  M. Watler         Created.
//
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include "client.h"

using namespace std;


int main(void) {
    sem_t *sem_id2;
    int fd; 
    string keyInput[NUM];

    // initialize named semaphore, can be used between processes
    sem_id2 = sem_open(SEMNAME, O_CREAT, SEM_PERMS, 0);

    fd = open(FILENAME, OPENFLAGS, FILEPERMS);
    if(fd==-1) {
       cout<<"Error opening "<<FILENAME<<endl;
       perror("open");
       sem_close(sem_id2);
       sem_unlink(SEMNAME);
       return -1;
    }
    
    // post for client 1
    sem_post(sem_id2);
    sleep(1);

    cout<<"client2: Waiting for the semaphore."<<endl;
    sem_wait(sem_id2);
    cout<<"client2: Enter "<<NUM<<" strings for "<<FILENAME<<"."<<endl;
    for(int i=0; i<NUM; ++i) {
        cout<<"client2: String "<<to_string(i+1)<<": ";
	cin>>keyInput[i];
    }
    cout<<"client2: Writing strings to "<<FILENAME<<endl;
    for(int i=0; i<5; ++i) {
        write(fd, keyInput[i].c_str(), keyInput[i].length());
    }
    sem_post(sem_id2);
    cout<<"client2: Semaphore posted."<<endl;

    sleep(1);

    cout<<"client2: Let's do it again."<<endl;
    cout<<"client2: Waiting for the semaphore."<<endl;
    sem_wait(sem_id2);
    cout<<"client2: Enter "<<NUM<<" strings for "<<FILENAME<<"."<<endl;
    for(int i=0; i<NUM; ++i) {
        cout<<"client2: String "<<to_string(i+1)<<": ";
	cin>>keyInput[i];
    }
    cout<<"client2: Writing strings to "<<FILENAME<<endl;
    for(int i=0; i<5; ++i) {
        write(fd, keyInput[i].c_str(), keyInput[i].length());
    }
    sem_post(sem_id2);

    cout<<"client2: quitting..."<<endl;
    close(fd);
    sem_close(sem_id2);
    sem_unlink(SEMNAME);

    return 0;
}
