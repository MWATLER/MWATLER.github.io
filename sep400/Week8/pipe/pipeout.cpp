// pipeout.c - Demonstrating the popen() function
//

#include <stdio.h>

#define COMMAND_LEN 16
#define DATA_SIZE 512

int main(int argc,char *argv[]){
    FILE *pf;
    char command[COMMAND_LEN];
    char data[DATA_SIZE];

    // Execute a process listing
    sprintf(command, "ls");
//  sprintf(command, "./pipeline");

    // Setup our pipe for reading and execute our command.
    pf = popen(command, "r");

    if(!pf){
        fprintf(stderr, "Could not open pipe for output.\n");
        return -1;
    }

    // Grab data from process execution
    while( fgets(data, DATA_SIZE , pf) != NULL) {
        // Print grabbed data to the screen.
        printf("%s\n",data);
    }

    if (pclose(pf) != 0)
        fprintf(stderr," Error: Failed to close command stream \n");

    return 0;
}
