// fifo1.cpp - Demonstrates fifo performance
//
// 26-Mar-19  M. Watler         Created.
// 
#include <ctype.h> 
#include <errno.h> 
#include <fcntl.h> 
#include <iostream> 
#include <stdio.h> 
#include <string.h> 
#include <sys/stat.h> 
#include <sys/time.h> 
#include <sys/types.h> 
#include <unistd.h> 

using namespace std;
  
int main() 
{ 
    int fd; 
  
    // FIFO file path 
    char myfifo[] = "/tmp/myfifo"; 
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>, <permission>) 
    int ret=mkfifo(myfifo, 0666);
    if(ret!=0) {
        printf("%s\n", strerror(errno));
//	return -1;
    }
  
    char str1[300];
    timespec ts1, ts2;
    const long nanosecsPerSecond=1000000000;
    double elapsedTime;

    // Zero the buffer
    memset(str1, 0, 30);

    sprintf(str1, "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz");
    int len=strlen(str1)+1;
    // Open FIFO for write only 
    fd = open(myfifo, O_WRONLY); 
    clock_gettime(CLOCK_REALTIME, &ts1);
    for(int i=0; i<5000000; ++i)
    { 
        // Write the input str1 on FIFO 
        write(fd, str1, len); 
    } 
    clock_gettime(CLOCK_REALTIME, &ts2);
    elapsedTime = (double)(ts2.tv_sec-ts1.tv_sec)*nanosecsPerSecond + (ts2.tv_nsec-ts1.tv_nsec);
    elapsedTime /= nanosecsPerSecond;
    cout << "The elapsed time with fifo is "<<elapsedTime<<" seconds."<<endl;

    close(fd); 
    unlink(myfifo);
    return 0; 
}
