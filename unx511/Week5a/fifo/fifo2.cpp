// fifo2.cpp - Demonstrates fifo. Reads from the fifo
//             and changes everything to capital leters
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
    int fd1;

    // FIFO file path
    char myfifo[] = "/tmp/myfifo"; 

    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    int ret=mkfifo(myfifo, 0666);
    if(ret!=0) printf("%s\n", strerror(errno));

    char str1[80], str2[80];
    bool is_running=true;
    while (is_running)
    {
        // Zero the buffers
	memset(str1, 0, 80);
	memset(str2, 0, 80);

        // First open in read only and read
        fd1 = open(myfifo,O_RDONLY);
        read(fd1, str1, 80);

        // Print the read string and close
        close(fd1);
	
        printf("Read: %s\n", str1);
	for(int i=0; i<strlen(str1); ++i) str2[i]=toupper(str1[i]);
        printf("The string is now %s\n", str2);

        // Now open in write mode and write
        // string taken from user.
        fd1 = open(myfifo,O_WRONLY);
        write(fd1, str2, strlen(str2)+1);
        close(fd1);
	if(strncmp(str2, "QUIT", 4)==0) is_running=false;
    }
    unlink(myfifo);
    return 0;
}
