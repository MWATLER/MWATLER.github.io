//userWriter.cpp - user level code for writing to a peripheral
//
// 26-Dec-20  M. Watler         Created.
//
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "peripheralWriter.h"

const char devFile[]="/dev/perwr";
const int  BUF_LEN=512;

using namespace std;

int main()
{
    int fd, rc=0;
    char buf[BUF_LEN];
    int  nbytes;
    int  perIndex;
    PERIPHERAL_INFO perInfo;

    fd=open(devFile, O_RDWR);
    if(fd < 0) {
        printf("Cannot open the device file...\n");
        rc=-1;
    }
    if(rc==0) {
        sprintf(buf, "Hello\n");
        nbytes=write(fd, buf, strlen(buf));
        printf("nbytes:%d = write()\n", nbytes);
        nbytes=read(fd, buf, BUF_LEN);
        printf("nbytes:%d = read() buf:%s\n", nbytes, buf);
        nbytes=write(fd, buf, strlen(buf));
        printf("nbytes:%d = write()\n", nbytes);
        nbytes=read(fd, buf, BUF_LEN);
        printf("nbytes:%d = read() buf:%s\n", nbytes, buf);
        ioctl(fd, PERIPHERAL_WRITER_GET_INFO, &perInfo);
        printf("perInfo.num_channels:%d perInfo.size_channel:%d\n", perInfo.num_channels, perInfo.size_channel);
        ioctl(fd, PERIPHERAL_WRITER_GET_CHANNEL_INDEX, &perIndex);
        printf("perIndex:%d\n", perIndex);
        perIndex=0;
        ioctl(fd, PERIPHERAL_WRITER_SET_CHANNEL_INDEX, &perIndex);
        ioctl(fd, PERIPHERAL_WRITER_GET_CHANNEL_INDEX, &perIndex);
        printf("perIndex:%d\n", perIndex);
    }

    close(fd);

    return rc;
}

