//fcntl.cpp - Test file race conditions
//
// 30-Jan-19  M. Watler         Created.
//

#include <fcntl.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;

int main(void)
{
    int fd;
    int flags;
    const char file[]="race.txt";

    fd = open(file, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
//  fd = open(file, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
    if(fd<0) {
	cout << strerror(errno);
	return -1;
    }

    for(int i=0; i<10; ++i) {
        string data = "fcntl: i: " + to_string(i) + "\n";
        int err=write(fd, data.c_str(), data.size());
	if(err<0) {
	    cout << "Error in fcntl" << endl;
	    cout << strerror(errno);
        }
	sleep(1);
    }
    
#if 1
    flags = fcntl(fd, F_GETFL);
    printf("1.flags:%08X O_RDWR:%08X O_CREAT:%08X O_APPEND:%08X O_EXCL:%08X\n", flags, O_RDWR, O_CREAT, O_APPEND, O_EXCL);
    flags = flags & ~O_APPEND;
//  flags &= ~O_EXCL;
    printf("2.flags:%08X O_RDWR:%08X O_CREAT:%08X O_APPEND:%08X O_EXCL:%08X\n", flags, O_RDWR, O_CREAT, O_APPEND, O_EXCL);
    flags = flags | O_EXCL;
//  flags |= O_APPEND;
    printf("3.flags:%08X O_RDWR:%08X O_CREAT:%08X O_APPEND:%08X O_EXCL:%08X\n", flags, O_RDWR, O_CREAT, O_APPEND, O_EXCL);
    fcntl(fd, F_SETFL, flags);
#endif
    for(int i=10; i<20; ++i) {
        string data = "fcntl: i: " + to_string(i) + "\n";
        int err=write(fd, data.c_str(), data.size());
	if(err<0) {
	    cout << "Error in fcntl" << endl;
	    cout << strerror(errno);
        }
	sleep(1);
    }

    cout<<"fcntl: DONE"<<endl;
    close(fd);
    return 0;
}
