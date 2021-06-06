// fifo1.cpp - Demonstrates fifo performance
//
// 04-Apr-19  M. Watler         Created.
// 
#include <ctype.h> 
#include <errno.h> 
#include <iostream> 
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

using namespace std;

int main()
{
    int fd1;
    bool is_running=true;

    // FIFO file path
    char myfifo[] = "/tmp/myfifo"; 

    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    int ret=mkfifo(myfifo, 0666);
    if(ret!=0) {
        printf("%s\n", strerror(errno));
//      return -1;
    }

    char str1[30];
    // Zero the buffers
    memset(str1, 0, 30);

    // First open in read/write
    fd1 = open(myfifo,O_RDWR);
    ret=read(fd1, str1, 30);
    if(ret<0) {
        cout<<strerror(errno)<<endl;
//      close(fd1);
//      unlink(myfifo);
    }
    cout<<"fifo1: received "<<str1<<endl;
    char newBuf[30];
    memset(newBuf, 0, 30);
    int len=strlen(str1);
    for(int i=0; i<len; ++i)
        newBuf[i]=toupper(str1[i]);

    ret=write(fd1, newBuf, len);
    if(ret<0) {
        cout<<strerror(errno)<<endl;
        close(fd1);
        unlink(myfifo);
    }
    close(fd1);
    unlink(myfifo);
    return 0;
}
