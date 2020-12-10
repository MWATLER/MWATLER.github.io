// fifo2.cpp - Demonstrates fifo performance
//
// 26-Mar-19  M. Watler         Created.
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

const int SIZE=300;

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

    char str1[SIZE];
    // Zero the buffers
    memset(str1, 0, SIZE);

    // First open in read only and read
    fd1 = open(myfifo,O_RDONLY);
    while (is_running)
    {
        read(fd1, str1, SIZE);
    }
    // Print the read string and close
    cout<<"fifo2: quitting..."<<endl;
    close(fd1);
    unlink(myfifo);
    return 0;
}
