#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char socket_path[] = "/tmp/tmp1";

int main(int argc, char *argv[]) {
    struct sockaddr_un addr;
    char buf[100];
    int fd,rc;
    bool isRunning = true;

    memset(&addr, 0, sizeof(addr));
    if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket error");
        exit(-1);
    }

    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
printf("client: addr.sun_path:%s\n", addr.sun_path);

printf("client: connect()\n");
    if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
printf("client: connect error exit\n");
        perror("connect error");
        close(fd);
        exit(-1);
    }

    while( isRunning && (rc=read(STDIN_FILENO, buf, sizeof(buf))) > 0) {
printf("client: write()\n");
        if (write(fd, buf, rc) != rc) {
            if (rc > 0) fprintf(stderr,"partial write");
            else {
                perror("write error");
                close(fd);
                exit(-1);
            }
        }
printf("client: strcmp(\"quit\", buf:%s)\n", buf);
	if(strncmp("quit", buf, 4)==0) {
	    isRunning = false;
	}
    }
   
printf("client: close(fd)\n");
    close(fd);
    return 0;
}
