// pipeline.cpp - C program to illustrate piping.
//
// 04-Apr-19  M. Watler         Created.
//
#include <stdlib.h> 
#include <stdio.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 

char *cmd1[] = { "du", "-a", 0 }; 
char *cmd2[] = { "wc", 0 }; 

int main(int argc, char **argv) { 
    int pid, status; 
    int fd[2]; 
    pipe(fd); 
    switch (pid = fork()) { 
        case 0: /* child */ 
            int pid2; 
            switch (pid2 = fork()) { 
                case 0: /* child */ 
                    dup2(fd[0], 0); 
                    close(fd[1]);//child doesn’t need this end of the pipe 
                    execvp(cmd2[0], cmd2); 
                    perror(cmd2[0]); 
                default: /* parent */ 
                    dup2(fd[1], 1); 
                    close(fd[0]);//parent doesn’t need this end of the pipe 
                    execvp(cmd1[0], cmd1); 
                    perror(cmd1[0]); 
                case -1: 
                    perror("fork"); 
                    exit(1); 
            } 
            exit(0); 
        default: /* parent */ 
            while ((pid = wait(&status)) != -1) 
            fprintf(stderr, "process %d exits with %d\n", pid, 
                                                 WEXITSTATUS(status)); 
            break; 
        case -1: 
            perror("fork"); 
            exit(1); 
    } 
    exit(0); 
} 
