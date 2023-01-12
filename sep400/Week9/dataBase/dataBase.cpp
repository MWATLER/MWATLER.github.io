//dataBase.cpp - A data base server
//
// 22-Nov-20  M. Watler         Created.
#include <arpa/inet.h>
#include <iostream>
#include <net/if.h>
#include <netinet/in.h>
#include <queue>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include "client.h"

using namespace std;

const char IP_ADDR[]="127.0.0.1";//Address of the database
const int IP_LEN=32;
const int KEY_LEN=32;
const int BUF_LEN=4096;
const int DBASE_SIZE=10000;
const int NUM_CLIENTS=3;
bool is_running;

void *recv_func(void *arg);

typedef struct clientIP {
    char ipAddr[IP_LEN];
    int  port;
} ClientIP;

// The database keeps a table of client IP addresses
ClientIP client[NUM_CLIENTS] = {
    {"127.0.0.1", 1161},
    {"127.0.0.1", 1162},
    {"127.0.0.1", 1163},
};

typedef struct dBase {
    char key[KEY_LEN];
    char value[BUF_LEN];
} DBase;

DBase database[DBASE_SIZE];
queue<DBase> dBaseEntry;
int numEntries=0;

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

    //Register signal handlers for SIGUSR1, SIGUSR2, ctrl-C and ctrl-Z
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
        myaddr.sin_port = htons(PORT);
        if(ret==0) {
            cout<<"No such address"<<endl;
	    cout<<strerror(errno)<<endl;
	    retVal = -3;
        }
    }

    if(retVal==0) {
        //The dataBase has to bind itself to an address
	//The dataBase has a table of all clients
        ret = bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr));
        if(ret<0) {
            cout<<"Cannot bind the socket to the local address"<<endl;
            cout<<strerror(errno)<<endl;
            retVal = -4;
        }
    }
    if(retVal==0) {
        is_running=true;
        int ret1 = pthread_create(&tid, NULL, recv_func, &fd);
	if(ret1!=0) {
            cout<<"Cannot create the threads"<<endl;
            cout<<strerror(errno)<<endl;
            retVal = -5;
        }
    }
    if(retVal==0) {
        pthread_join(tid, NULL);
    }

    close(fd);
    return retVal;
}

void *recv_func(void *arg)
{
    int fd = *(int *)arg;
    char buf[BUF_LEN];
    struct sockaddr_in recvaddr;
    socklen_t addrlen = sizeof(recvaddr);

    while(is_running) {
        memset(buf, BUF_LEN, 0);
        int len = recvfrom(fd, buf, BUF_LEN, 0, (struct sockaddr *)&recvaddr, &addrlen);
	cout<<"recv_func: buf:"<<buf<<endl;
	//Verify the sender
	char ip[IP_LEN];
	int  port;
	sprintf(ip, "%s", inet_ntoa(recvaddr.sin_addr));
	port=ntohs(recvaddr.sin_port);
	bool validSender=false;
        for(int i=0; i<NUM_CLIENTS && !validSender; ++i) {
            if(strcmp(ip, client[i].ipAddr)==0 && port==client[i].port) {
                validSender=true;
            }
        }
        if(validSender) {
            if(strncmp(buf, "insert", 6)==0) {
                char *bufPtr = &buf[7];
                int  len=strlen(bufPtr);
                int  index=0;
                while(bufPtr[index]!=',') ++index;//Search for the comma delimiter
                //Example: buf="insert cl1aa,data1aa"
                //         bufPtr="cl1aa,data1aa"
                //         len=13
                //         index=5
                memcpy(database[numEntries].key, &bufPtr[0], index);//copy everything until the comma
                memcpy(database[numEntries].value, &bufPtr[index+1], len-index-1);//copy everything after the comma
                cout<<"recv_func: database["<<numEntries<<"] key:"<<database[numEntries].key<<" value:"<<database[numEntries].value<<endl;
                if(numEntries<DBASE_SIZE-1) ++numEntries;
            } else if(strncmp(buf, "dump", 4)==0) {
                char buf2[KEY_LEN+BUF_LEN+1];
                for(int i=0; i<numEntries; ++i) {
                    memset(buf2, BUF_LEN, 0);
                    len=sprintf(buf2, "%s,%s\n", database[i].key, database[i].value)+1;
                    sendto(fd, buf2, len, 0, (struct sockaddr *)&recvaddr, addrlen);
		    sleep(0.1);
                }
		//Add end of database
                memset(buf2, BUF_LEN, 0);
                len=sprintf(buf2, "-1")+1;
                cout<<"recv_func: sendto("<<buf2<<")"<<endl;
                sendto(fd, buf2, len, 0, (struct sockaddr *)&recvaddr, addrlen);
                sleep(0.1);
            }
        }
    }

    pthread_exit(NULL);
}
