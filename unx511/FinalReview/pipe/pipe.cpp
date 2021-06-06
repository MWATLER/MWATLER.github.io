// pipe.c - C program to illustrate pipe system call in C shared by Parent and Child 
//
// 04-Apr-19  M. Watler         Created.
//
#include <ctype.h>
#include <errno.h>
#include <iostream> 
#include <stdio.h> 
#include <string.h> 
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h> 

using namespace std;

#define MSGSIZE 30 

char msg[] = "abcdefghijklmnopqrstuvwxyz";
  
int main() 
{ 
    char inbuf[MSGSIZE]; 
    int p1[2], p2[2], pid, nbytes; 
    bool is_running=true;
    int len=strlen(msg)+1;
  
    if (pipe(p1) < 0) 
        return -1; 
    if (pipe(p2) < 0) 
        return -1; 
  
    /* continued */
    pid = fork();
    if (pid > 0) {//The parent
        nbytes = write(p1[1], msg, len); 
	if(nbytes<0) {
            cout<<strerror(errno)<<endl;
            return -1;
	}
	memset(inbuf, 0, MSGSIZE);
        nbytes = read(p2[0], inbuf, MSGSIZE);
	if(nbytes<0) {
            cout<<strerror(errno)<<endl;
            return -1;
	}
	cout<<"parent: received "<<inbuf<<endl;
    } else {//The child
	memset(inbuf, 0, MSGSIZE);
        nbytes = read(p1[0], inbuf, MSGSIZE);
	if(nbytes<0) {
            cout<<strerror(errno)<<endl;
            return -1;
	}
	cout<<"child: received "<<inbuf<<endl;
	char newBuf[MSGSIZE];
        memset(newBuf, 0, MSGSIZE);
        for(int i=0; i<nbytes; ++i)
            newBuf[i]=toupper(inbuf[i]);	
        nbytes = write(p2[1], newBuf, len); 
	if(nbytes<0) {
            cout<<strerror(errno)<<endl;
            return -1;
	}
    } 
    return 0; 
} 

