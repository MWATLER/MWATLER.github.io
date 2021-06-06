#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>

char socket_path[] = "/tmp/tmp1";

int main(int argc, char *argv[]) {
    struct sockaddr_un addr;
    char buf[100];
    int fd,cl,rc;
    bool isRunning = true;

    memset(&addr, 0, sizeof(addr));
    if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket error");
        exit(-1);
    }

    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
printf("server: addr.sun_path:%s\n", addr.sun_path);
    unlink(socket_path);

printf("server: bind()\n");
    if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind error");
        close(fd);
        exit(-1);
    }

printf("server: listen()\n");
    if (listen(fd, 5) == -1) {
        perror("listen error");
        close(fd);
        exit(-1);
    }

    while (isRunning) {
printf("server: accept()\n");
        if ( (cl = accept(fd, NULL, NULL)) == -1) {
//      socklen_t addr_len = sizeof(addr);
//      if ( (cl = accept(fd, (struct sockaddr*)&addr, &addr_len)) == -1) {
            perror("accept error");
            continue;
        }

printf("server: read()\n");
        while ( (rc=read(cl,buf,sizeof(buf))) > 0) {
            printf("read %u bytes: %.*s\n", rc, rc, buf);
	    if(strncmp("quit", buf, 4)==0) {
	        isRunning = false;
	    }
        }
        if (rc == -1) {
            perror("read");
            close(fd);
            exit(-1);
        }
        else if (rc == 0) {
            printf("EOF\n");
            close(fd);
            close(cl);
        }
    }

printf("server: close(fd), close(cl)\n");
    close(fd);
    close(cl);
    return 0;
}
