// user_file.c - Calls into kernel space
//
// 18-Sep-20  M. Watler         Created.
//
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "device_file_io.h"

const char devFile[]="/dev/simple-driver";
const int  BUF_LEN=256;

using namespace std;

int main()
{
    int fd, rc=0;
    char buf[BUF_LEN];
    int  nbytes;

    fd=open(devFile, O_RDWR);
    if(fd < 0) {
        cout<<"Cannot open the device file...\n"<<endl;
	rc=-1;
    }
    if(rc==0) {
        nbytes=read(fd, buf, BUF_LEN);
	cout<<nbytes<<" read: "<<buf<<endl;
    }

    char userStr[]="Hello world from user space!\n\0";
    ioctl(fd, DEVICE_FILE_WRITE_STRING, userStr);
    sleep(5);
    memset(userStr, 0, sizeof(userStr));
    ioctl(fd, DEVICE_FILE_READ_STRING, userStr);
    cout<<"read: "<<userStr<<endl;
    close(fd);

    return rc;
}
