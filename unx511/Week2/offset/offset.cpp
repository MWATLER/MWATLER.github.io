//offset.cpp
//
// 30-Jan-19  M. Watler         Created.
//

#include <fcntl.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;

const int BUF_SIZ=10;
int main(void)
{
    int fd;
    const char file[]="offset.txt";
    char buf[BUF_SIZ];

    fd = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(fd<0) {
	cout << strerror(errno);
	return -1;
    }

    cout<<"Creating offset.txt"<<endl;
    for(int i=0; i<1000; ++i) {
        string data=" "+to_string(i);
	if(i%10==9) data+="\n";
	write(fd, data.c_str(), data.size());
    }

    cout<<"Reading from offset.txt"<<endl;
    for(int i=10; i<20; ++i) {
        int ret=pread(fd, buf, BUF_SIZ, i*10);
	if(ret<0) {
            cout << strerror(errno);
        }
        cout << "offset: " << i*10 << " buf:";
	for(int j=0; j<BUF_SIZ; ++j) {
            cout << buf[j];
        }
	cout << endl;
	sleep(1);
    }
    //One more from offset 500
    int ret=pread(fd, buf, BUF_SIZ, 500);
    if(ret<0) {
       cout << strerror(errno);
    }
    cout << "offset: 500 buf:";
    for(int j=0; j<BUF_SIZ; ++j) {
       cout << buf[j];
    }
    cout << endl;

    close(fd);
    return 0;
}
