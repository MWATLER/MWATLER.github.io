#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/ioctl.h>

#define WR_VALUE _IOW('a','a',int32_t*)
#define RD_VALUE _IOR('a','b',int32_t*)
#define BUF_LEN 32

int main()
{
        int fd, ret;
        char value[BUF_LEN], number[BUF_LEN];
	int nbytes;
        printf("*********************************\n");
        printf("*******WWW.EmbeTronicX.com*******\n");

        printf("\nOpening Driver\n");
        fd = open("/dev/etx_device", O_RDWR);
        if(fd < 0) {
                printf("Cannot open device file...\n");
                return 0;
        }

        printf("Enter the Value to send\n");
        scanf("%s", number);
        printf("Writing Value to Driver\n");
	nbytes = strlen(number);
        printf("write(fd:%d, number:%s, nbytes:%d)\n", fd, number, nbytes);
        ret=write(fd, number, nbytes); 
        printf("ret:%d = write()\n", ret);

        printf("Reading Value from Driver\n");
	nbytes = BUF_LEN;
        ret=read(fd, value, nbytes);
        printf("ret:%d = read()\n", ret);
        printf("Value is %s\n", value);

        printf("Closing Driver\n");
        close(fd);
}
