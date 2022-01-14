// fifo1.cpp - Demonstrates fifo. Writes to a process then reads from it.
//
// 14-Mar-19  M. Watler         Created.
// 
#include <ctype.h> 
#include <errno.h> 
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int fd; 
  
    // FIFO file path 
    char myfifo[] = "/tmp/myfifo"; 
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>, <permission>) 
    int ret=mkfifo(myfifo, 0666);
    if(ret!=0) printf("%s\n", strerror(errno));
  
    char str1[80], str2[80]; 
    bool is_running=true;
    while (is_running) 
    { 
        // Zero the buffers
	memset(str1, 0, 80);
	memset(str2, 0, 80);

        // Open FIFO for write only 
        fd = open(myfifo, O_WRONLY); 
  
        // Take an input str2 from user. 
        // 80 is maximum length 
        printf("Enter a string: ");
        fgets(str1, 80, stdin); 
  
        // Write the input str1 on FIFO 
        // and close it 
        write(fd, str1, strlen(str1)+1); 
        close(fd); 
  
        // Open FIFO for Read only 
        fd = open(myfifo, O_RDONLY); 
  
        // Read from FIFO 
        read(fd, str2, sizeof(str2)); 
        printf("The string is now %s\n", str2);
  
        // Print the read message 
        close(fd); 
	if(strncmp(str2, "QUIT", 4)==0) is_running=false;
    } 
    unlink(myfifo);
    return 0; 
} 
