// pipe2.c - Synchronization via pipes
//
// 14-Mar-19  M. Watler         Created.
//
#include <stdio.h> 
#include <string.h> 
#include <unistd.h> 

const int MSGSIZE=16;
char msg[] = "finished";
  
int main() 
{ 
    char inbuf[MSGSIZE]; 
    int p[2], pid, nbytes; 
  
    if (pipe(p) < 0) 
        return 1; 
  
    /* continued */
    if ((pid = fork()) > 0) { 
        printf("%d: The parent is waiting\n", getpid()); 
        nbytes = read(p[0], inbuf, MSGSIZE);
        printf("%d: The parent has finished waiting\n", getpid()); 
    } 
  
    else { 
        printf("%d: The child is doing something for five seconds\n", getpid());
	for(int i=0; i<5; ++i) sleep(1);
        printf("%d: The child has finished\n", getpid()); 
        write(p[1], msg, strlen(msg)); 
    } 

    close(p[0]);
    close(p[1]);

    printf("%d: DONE\n", getpid());
    return 0; 
} 

