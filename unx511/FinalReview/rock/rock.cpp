// rock.c - C program to illustrate execlp()
//
// 04-Apr-19  M. Watler         Created.
//
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
int main() 
{ 
    int pid; 
    printf("\nWe are the champions!\n"); 
    pid = fork(); 
    if( pid > 0 ){ 
        printf("We will\n"); 
        sleep(1); 
        execlp("./rock", "rock", NULL); 
        printf("rock you!\n"); 
    }else if( pid == 0 ){ 
        printf("I've paid my debts\n"); 
        execlp("/bin/date", "date", NULL); 
        printf("I will never lose!\n"); 
    } 
    printf("The Leafs are the champions! (in 1967)\n"); 
}

