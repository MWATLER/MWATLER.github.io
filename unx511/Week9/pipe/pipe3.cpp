// pipe.c - C program to illustrate pipe system call in C shared by Parent and Child 
//
// 14-Mar-21  M. Watler         Created.
//
#include <stdio.h> 
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 
#define MSGSIZE 32 
char msg1[][MSGSIZE] = {"parent: hello, world #1",
	                "parent: hello, world #2",
                        "parent: hello, world #3"}; 
char msg2[][MSGSIZE] = {"child: hello, world #1",
	                "child: hello, world #2",
                        "child: hello, world #3"}; 
const int numMessages=3;
  
int main() 
{ 
    char inbuf[MSGSIZE]; 
    int p[2], pid, nbytes; 
  
    if (pipe(p) < 0) 
        return 1; 
  
    /* continued */
    if ((pid = fork()) > 0) { 
        printf("The parent is writing\n"); 
	for(int i=0; i<numMessages; ++i) {
            write(p[1], msg1[i], MSGSIZE); 
	}
        printf("The parent has finished writing\n"); 
	sleep(1);

        printf("The parent is reading\n"); 
	for(int i=0; i<numMessages; ++i) {
            nbytes = read(p[0], inbuf, MSGSIZE/2);
            printf("%s\n", inbuf); 
	    int count;
	    ioctl(p[0], FIONREAD, &count);
	    printf("%d bytes remaining\n\n", count);
	}
        printf("The parent has finished reading\n"); 
	int status;
	wait(&status);
    } 
  
    else { 
        printf("The child is reading\n"); 
	for(int i=0; i<numMessages; ++i) {
            nbytes = read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf); 
	}
        printf("The child has finished reading\n"); 

        printf("Now the child is writing\n"); 
	for(int i=0; i<numMessages; ++i) {
            write(p[1], msg2[i], MSGSIZE); 
	}
        printf("The child has finished writing\n"); 
    } 
    close(p[0]);
    close(p[1]);
    return 0; 
} 

