//race2.cpp - Test file race conditions
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
    int fd2;
    const char file[]="race.txt";

    fd2 = open(file, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
//  fd2 = open(file, O_RDWR | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
//  fd2 = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(fd2<0) {
        cout << "race2: " << strerror(errno);
	return -1;
    }

    for(int i=0; i<20; ++i) {
        string data = "race2: i: " + to_string(i) + "\n";
        int err=write(fd2, data.c_str(), data.size());
	if(err<0) {
            cout << "Error in race2" << endl;
            cout << strerror(errno);
        }
	sleep(1);
    }

    close(fd2);
    return 0;
}
