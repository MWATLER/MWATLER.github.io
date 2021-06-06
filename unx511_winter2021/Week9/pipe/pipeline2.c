// pipeline.c - Demonstrate pipes inside a C program
//
//              du -a | grep Week | more
//
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

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>

int main (int argc, char **argv)
{
    int pfd1[2], pfd2[2];
    pid_t pid1, pid2, pid3;

    if (pipe (pfd1) == -1)
       perror ("pipe");

    pid1 = fork();
    if (pid1 == 0) {
        // first child, will become "du -a"
	// We bind the standard output to the write end of pipe 1
        if (dup2 (pfd1[1], STDOUT_FILENO) == -1)//STDOUT is now the output of pipe pfd1
            perror ("dup2");
	//We are now using STDOUT_FILENO as the write end of pipe 1. This is itself
        //a file descriptor. We therefore close all other unused file descriptors
        //for pipe 1. We don't need them any more.
        if (close (pfd1[0]) == -1)
            perror ("close");
        if (close (pfd1[1]) == -1)
            perror ("close");
        execlp ("du", "du", "-a", (char *) NULL);
        perror ("execlp");
    }

    /* parent process */
    if (pipe (pfd2) == -1)
       perror ("pipe");

    pid2 = fork();
    if (pid2 == 0) {
        // second child, who will become "grep Week"
	// We bind the standard input to the read end of pipe 1
        if (dup2 (pfd1[0], STDIN_FILENO) == -1)//STDIN is now the input of pipe pfd1
            perror ("dup2");
	// We bind the standard output to the write end of pipe 2
        if (dup2 (pfd2[1], STDOUT_FILENO) == -1)//STDOUT is now the output of pipe pfd2
            perror ("dup2");
	//We are now using STDIN_FILENO as the read end of pipe 1 and STDOUT_FILENO as
	//the write end of pipe 2. These are themselves file descriptors. We therefore
	//close all other unused file descriptors. We don't need them any more.
        if (close (pfd1[0]) == -1)
            perror ("close");
        if (close (pfd1[1]) == -1)
            perror ("close");
        if (close (pfd2[0]) == -1)
            perror ("close");
        if (close (pfd2[1]) == -1)
            perror ("close");
        execlp ("grep", "grep", "Week", (char *) NULL);
        perror ("execlp");
    }

    /* parent process */
    //Since communication is between two children, (child 1 and child 2) through
    //pipe 1, the parent has no use for these file descriptors at all, therefore
    //they are closed here. NOTE: Neither child should get to this point.
    if (close (pfd1[0]) == -1)
        perror ("close");
    if (close (pfd1[1]) == -1)
        perror ("close");

    pid3 = fork ();
    if (pid3 == 0) {
        // third child, who will become "more"
	// We bind the standard input to the read end of pipe 2
        if (dup2 (pfd2[0], STDIN_FILENO) == -1)
            perror ("dup2");
	//We are now using STDIN_FILENO as the read end of pipe 2. This is itself
        //a file descriptor. We therefore close all other unused file descriptors.
        //We don't need them any more.
        if (close (pfd2[0]) == -1)
            perror ("close");
        if (close (pfd2[1]) == -1)
            perror ("close");
        execlp ("more", "more", (char *) NULL);
        perror ("execlp");
    }

    /* parent process */
    //Since communication is between two children, (child 2 and child 3) through
    //pipe 2, the parent has no use for these file descriptors at all, therefore
    //they are closed here. NOTE: Neither child should get to this point.
    if (close (pfd2 [0]) == -1)
        perror ("close");
    if (close (pfd2 [1]) == -1)
        perror ("close");

    if (waitpid (pid1, NULL, 0) == -1)
         perror ("waitpid");
    if (waitpid (pid2, NULL, 0) == -1)
         perror ("waitpid");
    if (waitpid (pid3, NULL, 0) == -1)
         perror ("waitpid");
}
