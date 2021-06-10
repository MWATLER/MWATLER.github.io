//client1.cpp - A client that adds to and reads from a database. 
//
// 22-Nov-20  M. Watler         Created.
#include <arpa/inet.h>
#include <fcntl.h>
#include <iostream>
#include <net/if.h>
#include <netinet/in.h>
#include <semaphore.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include "client.h"

using namespace std;

const int PORT1=1161;//Port of client 1
const char IP_ADDR[]="127.0.0.1";//Address of the database
const int BUF_LEN=4096;
const int KEY_LEN=32;
bool is_running;
sem_t *sem_id;

void *send_func(void *arg);

static void shutdownHandler(int sig)
{
    switch(sig) {
        case SIGINT:
            is_running=false;
	    break;
    }
}

int main(int argc, char *argv[])
{
    pthread_t tid;
    int retVal=0;
    int fd, ret, len;
    struct sockaddr_in myaddr;

    //Declare a variable of type struct sigaction
    struct sigaction sig;
    sig.sa_handler = shutdownHandler;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags = 0;

    //Create the semaphore
    sem_unlink(SEMNAME);//Make sure one doesn't exist already
    sem_id = sem_open(SEMNAME, O_CREAT, SEM_PERMS, 0);

    //Register signal handler for ctrl-C
    ret = sigaction(SIGINT, &sig, NULL);
    if(ret!=0) {
        retVal = -1;
    }

    if(retVal==0) {
        fd=socket(AF_INET, SOCK_DGRAM, 0);
	if(fd<0) {
            cout<<"Cannot create the socket"<<endl;
            cout<<strerror(errno)<<endl;
            retVal = -2;
        }
    }
    if(retVal==0) {
        memset((char *)&myaddr, 0, sizeof(myaddr));
        myaddr.sin_family = AF_INET;
        ret = inet_pton(AF_INET, IP_ADDR, &myaddr.sin_addr);
        myaddr.sin_port = htons(PORT1);
        if(ret==0) {
            cout<<"No such address"<<endl;
	    cout<<strerror(errno)<<endl;
            close(fd);
	    retVal = -3;
        }
    }

    if(retVal==0) {
        //The client has to bind itself to an address
	//The dataBase will keep a table of all clients
        ret = bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr));
        if(ret<0) {
            cout<<"Cannot bind the socket to the local address"<<endl;
            cout<<strerror(errno)<<endl;
            retVal = -3;
            close(fd);
        }
    }
    if(retVal==0) {
        is_running=true;
        int ret1 = pthread_create(&tid, NULL, send_func, &fd);
	if(ret1!=0) {
            cout<<"Cannot create the thread"<<endl;
            cout<<strerror(errno)<<endl;
            retVal = -3;
        }
    }
    if(retVal==0) {
        pthread_join(tid, NULL);
    }

    close(fd);
    sem_unlink(SEMNAME);
    return retVal;
}

void *send_func(void *arg)
{
    int fd = *(int *)arg;
    char buf[BUF_LEN];
    int len;
    struct sockaddr_in servaddr, recvaddr;
    socklen_t addrlen = sizeof(servaddr);

    memset((char *)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, IP_ADDR, &servaddr.sin_addr);
    servaddr.sin_port = htons(PORT);
    char entry1='a';
    char entry2='a';
    while(is_running) {
        //Fill the database
        for(int j=0; j<25; ++j) {
            sem_wait(sem_id);
            for(int i=0; i<25; ++i) {
                len=sprintf(buf, "insert cl1%c%c,data1%c%c", entry2, entry1, entry2, entry1)+1;
		cout<<"send_func: len:"<<len<<" "<<buf<<endl;
                sendto(fd, buf, len, 0, (struct sockaddr *)&servaddr, addrlen);
                ++entry1;
	        sleep(0.1);
            }
            sem_post(sem_id);
	    entry1='a';
            ++entry2;
	    sleep(1);
        }
        int choice;
        do {
            cout<<"Make a selection:"<<endl;
            cout<<"1.Dump database"<<endl;
            cout<<"2.Quit"<<endl;
            cin>>choice;
            switch(choice) {
                case 1:
		    memset(buf, BUF_LEN, 0);
                    len=sprintf(buf, "dump")+1;
                    sem_wait(sem_id);
                    sendto(fd, buf, len, 0, (struct sockaddr *)&servaddr, addrlen);
		    memset(buf, BUF_LEN, 0);
		    do {
                        len=recvfrom(fd, buf, BUF_LEN, 0, (struct sockaddr *)&recvaddr, &addrlen);
			cout<<buf<<endl;
                    } while(strcmp(buf, "-1")!=0);//End of database: -1
                    sem_post(sem_id);
                    break;
                case 2:
                    cout<<"Ending program..."<<endl;
		    is_running=false;
                    break;
            }
        } while (choice!=2);
    }

    pthread_exit(NULL);
}
