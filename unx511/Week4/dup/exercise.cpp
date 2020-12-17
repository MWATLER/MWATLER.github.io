//exercise.cpp - Test file for Quiz 4
//
// 26-Jan-19  M. Watler         Created.
//

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fd1, fd2, fd3;
    const char file[]="Quiz4.txt";

    fd1 = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(fd1<0) {
	return -1;
    }
    fd2 = dup(fd1);
    if(fd2<0) {
        close(fd1);
	return -1;
    }
    fd3 = open(file, O_RDWR);
    if(fd3<0) {
        close(fd1);
        close(fd2);
	return -1;
    }
    sleep(10);
//Question 1: Do fd1 and fd2 share the same file offset value?


//Question 2: Do fd1 and fd3 share the same file offset value?


    write(fd1, "Hello,", 6);
    write(fd2, "world", 5);
//Question 3: What will you see in Quiz4.txt at this point?

    sleep(10);
    lseek(fd2, 0, SEEK_SET);
    write(fd1, "HELLO,", 6);
//Question 4: What will you see in Quiz4.txt at this point?


    sleep(10);
    write(fd3, "Gidday", 6);
//Question 5: What will you see in Quiz4.txt at this point?


    close(fd1);
    close(fd2);
    close(fd3);
    return 0;
}
