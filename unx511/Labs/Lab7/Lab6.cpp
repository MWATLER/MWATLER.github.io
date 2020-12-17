// Lab6.cpp - Pipe one command into another
//            The program is executed as follows:
//            ./Lab6 <argument1> <argument2>
//
//            <argument1> and <argument2> could be one, two or three strings in length.
//            If a command is more than one string in length, it has to be put in quotes.
//            For example:
//            ./Lab6 du "grep -i Lab6"
//
//            <argument1> would be du
//            <argument2> would be grep -i Lab6
//
//
// 14-Mar-19  M. Watler         Created.
//
// dup, dup2 and execlp:
//
// int dup(int oldfd);
//
// The dup() system call creates a copy of the file descriptor oldfd,
// using the lowest-numbered unused file descriptor for the new
// descriptor.
// 
// After a successful return, the old and new file descriptors may be
// used interchangeably.  They refer to the same open file description
// (see open(2)) and thus share file offset and file status flags; for
// example, if the file offset is modified by using lseek(2) on one of
// the file descriptors, the offset is also changed for the other.
//
//
// int dup2(int oldfd, int newfd);
//
// The dup2() system call performs the same task as dup(), but instead
// of using the lowest-numbered unused file descriptor, it uses the file
// descriptor number specified in newfd.  If the file descriptor newfd
// was previously open, it is silently closed before being reused.
//
// execlp(const char *file, const char *arg, ...);
//

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <vector>
#include <error.h>

const int LEN=32;

using namespace std;

int main (int argc, char **argv)
{
    int pfd1[2];
    pid_t pid1, pid2;

    if(argc!=3) {
        cout<<"usage: Lab6 <argument1> <argument2>"<<endl;
	return -1;
    }
#ifdef DEBUG
    cout<<"argv[1]: "<<argv[1]<<" argv[2]: "<<argv[2]<<endl<<endl;
#endif
    char argument1[LEN];
    char argument2[LEN];
    strcpy(argument1, argv[1]);
    strcpy(argument2, argv[2]);
    char arg1[3][LEN];
    char arg2[3][LEN];
    int len1=0, len2=0;

    char *token=strtok(argument1, " ");
    while(token!=NULL) {
        strcpy(arg1[len1], token);
#ifdef DEBUG
    cout<<"arg1["<<len1<<"]: "<<arg1[len1]<<endl;
#endif
        token=strtok(NULL, " ");
	++len1;
    }
    token=strtok(argument2, " ");
    while(token!=NULL) {
        strcpy(arg2[len2], token);
#ifdef DEBUG
    cout<<"arg2["<<len2<<"]: "<<arg2[len2]<<endl;
#endif
        token=strtok(NULL, " ");
	++len2;
    }

    if (pipe (pfd1) == -1) {
       cout<<strerror(errno)<<endl;
       return -1;
    }

    pid1 = fork();
    if (pid1 == 0) {
        // first child, will become <argument1>
        if (dup2 (pfd1[1], STDOUT_FILENO) == -1)//The output of pipe pfd1 is now STDOUT
            perror ("dup2");
        if (close (pfd1[0]) == -1)
            perror ("close");
        if (close (pfd1[1]) == -1)
            perror ("close");
	if(len1==1)
            execlp(arg1[0], arg1[0], (char *) NULL);
	else if(len1==2)
            execlp(arg1[0], arg1[0], arg1[1], (char *) NULL);
	else if(len1==3)
            execlp(arg1[0], arg1[0], arg1[1], arg1[2], (char *) NULL);
        perror ("execlp");
    }

    pid2 = fork();
    if (pid2 == 0) {
        // second child, who will become <argument2>
        if (dup2 (pfd1[0], STDIN_FILENO) == -1)//The input of pipe pfd1 is now STDIN
            perror ("dup2");
        if (close (pfd1[0]) == -1)
            perror ("close");
        if (close (pfd1[1]) == -1)
            perror ("close");
	if(len2==1)
            execlp(arg2[0], arg2[0], (char *) NULL);
	else if(len2==2)
            execlp(arg2[0], arg2[0], arg2[1], (char *) NULL);
	else if(len2==3)
            execlp(arg2[0], arg2[0], arg2[1], arg2[2], (char *) NULL);
        perror ("execlp");
    }

    /* parent process */
    if (close (pfd1[0]) == -1)
        perror ("close");
    if (close (pfd1[1]) == -1)
        perror ("close");

    if (waitpid (pid1, NULL, 0) == -1)
         perror ("waitpid");
    if (waitpid (pid2, NULL, 0) == -1)
         perror ("waitpid");
}
