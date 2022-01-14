// pipe.c - C program to illustrate pipe system call in C shared by Parent and Child 
//
// 14-Mar-19  M. Watler         Created.
//
#include <stdio.h> 
#include <string.h> 
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h> 

#define MSGSIZE 300 

char msg[] = "abcdefghijklmnopqrstuvwxyz" \
             "abcdefghijklmnopqrstuvwxyz" \
             "abcdefghijklmnopqrstuvwxyz" \
             "abcdefghijklmnopqrstuvwxyz" \
             "abcdefghijklmnopqrstuvwxyz" \
             "abcdefghijklmnopqrstuvwxyz" \
             "abcdefghijklmnopqrstuvwxyz" \
             "abcdefghijklmnopqrstuvwxyz" \
             "abcdefghijklmnopqrstuvwxyz" \
             "abcdefghijklmnopqrstuvwxyz";

  
int main() 
{ 
    char inbuf[MSGSIZE]; 
    int p[2], pid, nbytes; 
    bool is_running=true;
    int len=strlen(msg)+1;
  
    if (pipe(p) < 0) 
        return 1; 
  
    /* continued */
    pid = fork();
    if (pid > 0) {//The parent
        timespec ts1, ts2;
	const long nanosecsPerSecond=1000000000;
        double elapsedTime;
        printf("The parent is writing\n"); 
	clock_gettime(CLOCK_REALTIME, &ts1);
	for(int i=0; i<5000000; ++i) {
            write(p[1], msg, len); 
	}
	clock_gettime(CLOCK_REALTIME, &ts2);
        elapsedTime = (double)(ts2.tv_sec-ts1.tv_sec)*nanosecsPerSecond + (ts2.tv_nsec-ts1.tv_nsec);
        elapsedTime /= nanosecsPerSecond;
        printf("The elapsed time with pipe is %lf seconds.\n", elapsedTime);
        printf("The parent has finished writing\n"); 
	kill(pid, SIGINT);
    } else { 
        printf("The child is reading\n"); 
	while(is_running) {
            nbytes = read(p[0], inbuf, MSGSIZE);
	}
        printf("The child has finished reading\n"); 
    } 
    return 0; 
} 

