// counter.cpp - A simple counter to demonstrate threads
//
// 14-Mar-19  M. Watler         Created.
//

#include <errno.h>
#include <iostream>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
 
#define NUM_THREADS 5 
#define NUM_SECONDS 10

using namespace std;
 
void *thr_func(void *arg) {
    int tNum = *(int *)arg;
 
    for(int i=0; i<NUM_SECONDS; ++i) {
        cout<<"Thread "<<tNum<<": "<<i<<" seconds"<<endl;
	sleep(1);
    }
 
    pthread_exit(NULL);
}
 
int main(int argc, char **argv) {
    pthread_t tid[NUM_THREADS];
    int i, rc;
    int threadNum;
 
    /* create threads */
    for (i = 0; i < NUM_THREADS; ++i) {
        threadNum = i+1;
        rc = pthread_create(&tid[i], NULL, thr_func, &threadNum);
	    if(rc!=0) {
            cout<<strerror(errno)<<endl;
            return -1;
        }
        sleep(1);
    }
    /* block until all threads complete */
    for (i = 0; i < NUM_THREADS; ++i) {
        pthread_join(tid[i], NULL);
    }
 
    return EXIT_SUCCESS;
}
