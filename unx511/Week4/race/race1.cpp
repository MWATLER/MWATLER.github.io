//race1.cpp - Test file race conditions
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
    int fd1;
    const char file[]="race.txt";

    fd1 = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
//  fd1 = open(file, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
//  fd1 = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(fd1<0) {
        cout << "race1: " << strerror(errno);
	return -1;
    }

    for(int i=0; i<20; ++i) {
        string data = "race1: i: " + to_string(i) + "\n";
        int err=write(fd1, data.c_str(), data.size());
	if(err<0) {
	    cout << "Error in race1" << endl;
	    cout << strerror(errno);
        }
	sleep(1);
    }

    close(fd1);
    return 0;
}
