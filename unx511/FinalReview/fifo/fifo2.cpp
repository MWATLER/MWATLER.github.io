// fifo2.cpp - Demonstrates fifo performance
//
// 04-Apr-19  M. Watler         Created.
// 
#include <ctype.h> 
#include <errno.h> 
#include <fcntl.h> 
#include <iostream> 
#include <stdio.h> 
#include <string.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

using namespace std;
  
int main() 
{ 
    int fd, ret; 
  
    // FIFO file path 
    char myfifo[] = "/tmp/myfifo"; 
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>, <permission>) 
    ret=mkfifo(myfifo, 0666);
    if(ret!=0) {
        printf("%s\n", strerror(errno));
//	return -1;
    }
  
    char str1[30];

    // Zero the buffer
    memset(str1, 0, 30);

    sprintf(str1, "abcdefghijklmnopqrstuvwxyz");
    int len=strlen(str1)+1;
    // Open FIFO for write only 
    fd = open(myfifo, O_RDWR); 
    // Write the input str1 on FIFO 
    ret=write(fd, str1, len); 
    if(ret<0) {
        cout<<strerror(errno)<<endl;
        close(fd);
	unlink(myfifo);
    }
    memset(str1, 0, 30);
    ret=read(fd, str1, 30); 
    if(ret<0) {
        cout<<strerror(errno)<<endl;
        close(fd);
	unlink(myfifo);
    }
    cout<<"fifo2: received "<<str1<<endl;

    close(fd); 
    unlink(myfifo);
    return 0; 
} 
