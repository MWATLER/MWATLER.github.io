// radioApplication.cpp - The radio application. It allows four processes to access its four channels at a time
//                        as well as four processes to send data via IP.
//
// 07-Aug-21  M. Watler         Created.
//
#include <arpa/inet.h>
#include <errno.h>
#include <iostream>
#include <fcntl.h>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/socket.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "client.h"

using namespace std;
bool is_running;
pthread_mutex_t lock_x;

queue<DestPacket> destPacket;
unsigned short packetNo=0;

void *recv_func(void *arg);
void *transmit_func(void *arg);

//Valid clients
const int NUM_CLIENTS=16;
const int ADDR_LEN = 24;
char client[NUM_CLIENTS][ADDR_LEN] ={
    "192.168.8.130:1161",
    "192.168.8.130:1162",
    "192.168.8.130:1163",
    "192.168.8.130:1164",
    "192.168.8.130:1165",
    "192.168.8.130:1166",
    "192.168.8.130:1167",
    "192.168.8.130:1168",
    "192.168.8.130:1169",
    "192.168.8.130:1170",
    "192.168.8.130:1171",
    "192.168.8.130:1172",
    "192.168.8.130:1173",
    "192.168.8.130:1174",
    "192.168.8.130:1175",
    "192.168.8.130:1176"
};

static void interruptHandler(int signum)
{
    switch(signum) {
        case SIGINT:
            cout<<"interruptHandler("<<signum<<"): SIGINT"<<endl;
            is_running=false;
	    break;
    }
}

int main(void) {
    int retVal=0;
    //sockets
    int master_fd, ret;
    struct sockaddr_in radioAddr;
    socklen_t addrlen = sizeof(radioAddr);

    //semaphores
    sem_t *sem_id;

    //threads
    pthread_t rxId=0, txId=0;

    //shared memory
    key_t          ShmKey;
    int            ShmID;
    struct Memory  *ShmPTR;

    //signals
    struct sigaction action;
    action.sa_handler = interruptHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    //set up the shared memory
    //key_t ftok(const char *pathname, int proj_id);
    //
    //The ftok() function uses the identity of the file named by the given pathname
    //and the least significant 8 bits of proj_id (which must be nonzero) to
    //generate a key_t type suitable for use with msgget(2), semget(2), or shmget(2).
    ShmKey=ftok(MEMNAME, 65);

    //int shmget(key_t key, size_t size, int shmflg);
    //
    //shmget() returns the identifier of the shared memory segment associated with
    //the value of the argument key.
    //struct Memory {
    //    int           packet_no;
    //    unsigned char sourceIP[4];
    //    unsigned char destIP[4];
    //    char          message[BUF_LEN];
    //};

    ShmID=shmget(ShmKey, sizeof(struct Memory), IPC_CREAT | 0666);
    if (ShmID < 0) {
        cout<<"shmget() error"<<endl;
        cout<<strerror(errno)<<endl;
        retVal = -1;
    }

    //void *shmat(int shmid, const void *shmaddr, int shmflg);
    //
    //shmat() attaches the shared memory segment identified by shmid to the
    //address space of the calling process. The attaching address is specified
    //by shmaddr. If shmaddr is NULL, the system chooses a suitable (unused)
    //page-aligned address to attach the segment.
    if(retVal==0) {
        ShmPTR = (struct Memory *) shmat(ShmID, NULL, 0);
        if (ShmPTR == (void *)-1) {
            cout<<"shmat() error"<<endl;
            cout<<strerror(errno)<<endl;
            retVal = -2;
        }
    }

    //set up the socket for receiving connections
    if(retVal==0) {
        master_fd=socket(AF_INET, SOCK_DGRAM, 0);
        if(master_fd<0) {
            cout<<"Cannot create the socket"<<endl;
            cout<<strerror(errno)<<endl;
            retVal = -3;
        }
    }

    if(retVal==0) {
        memset((char *)&radioAddr, 0, sizeof(radioAddr));
        radioAddr.sin_family = AF_INET;
        ret = inet_pton(AF_INET, RADIO_ADDR, &radioAddr.sin_addr);
        if(ret==0) {
            cout<<"No such address"<<endl;
            cout<<strerror(errno)<<endl;
            retVal = -4;
        }
        radioAddr.sin_port = htons(RADIO_PORT);
    }

    if(retVal==0) {
        ret = bind(master_fd, (struct sockaddr *)&radioAddr, sizeof(radioAddr));
        if(ret<0) {
            cout<<"Cannot bind the socket to the local address"<<endl;
            cout<<strerror(errno)<<endl;
            retVal = -5;
        }
    }

    //initialize the mutex
    if(retVal==0) {
        ret = pthread_mutex_init(&lock_x, NULL);
        if(ret<0) {
            cout<<"Unable to initialize the mutex"<<endl;
            cout<<strerror(errno)<<endl;
            retVal = -6;
        }
    }

    //set up the receive thread
    if(retVal==0) {
        ret = pthread_create(&rxId, NULL, recv_func, &master_fd);
        if(ret!=0) {
            cout<<"Cannot start the receive thread"<<endl;
            cout<<strerror(errno)<<endl;
	    retVal = -7;
        }
    }

    //set up the transmit thread
    if(retVal==0) {
        ret = pthread_create(&txId, NULL, transmit_func, &master_fd);
        if(ret!=0) {
            cout<<"Cannot start the transmit thread"<<endl;
            cout<<strerror(errno)<<endl;
	    retVal = -8;
        }
    }

    //set up the semaphores
    if(retVal==0) {
        // initialize the named semaphore with a value of 4
        sem_unlink(SEMNAME);
        // If O_CREAT is specified in oflag, then the semaphore is
        // created if it does not already exist.
        sem_id = sem_open(SEMNAME, O_CREAT, SEM_PERMS, 4);
	if(sem_id==SEM_FAILED) {
            cout<<"Cannot open the semaphore"<<endl;
            cout<<strerror(errno)<<endl;
	    retVal = -9;
        }
    }

    //read from the shared memory
    if(retVal==0) {
        int channel;
        for(channel=0; channel<NUM_CHANNELS; ++channel) {//Initialize all channels to READ
            ShmPTR->radioChannel[channel].status=READ;
        }
        is_running=true;
        while(is_running) {
            bool isFound=false;
            for(channel=0; channel<NUM_CHANNELS; ++channel) {//Go through all the channels
                if(ShmPTR->radioChannel[channel].status==WRITTEN) {
                    pthread_mutex_lock(&lock_x);
                    DestPacket packet;
                    packet.source = ShmPTR->radioChannel[channel].source;
		    packet.packetNo = packetNo++;
		    strncpy(packet.message, ShmPTR->radioChannel[channel].message, BUF_LEN);
                    destPacket.push(packet);
                    pthread_mutex_unlock(&lock_x);
                    ShmPTR->radioChannel[channel].status=READ;
                    isFound=true;
                }
            }
            sleep(0.1);
        }
    }
    if(retVal!=0) {
        is_running=false;//shutdown the threads
    }

    //close the semaphore
    if(sem_id!=SEM_FAILED) {
        sem_close(sem_id);
        sem_unlink(SEMNAME);
    }

    //detach from and remove the shared memory
    if (ShmPTR != (void *)-1) shmdt((void *)ShmPTR);
    if (ShmID >= 0) shmctl(ShmID, IPC_RMID, NULL);

    //wait for the receive and transmit threads to terminate
    if(rxId!=0) pthread_join(rxId, NULL);
    if(txId!=0) pthread_join(txId, NULL);

    //destroy the mutex
    pthread_mutex_destroy(&lock_x);
        
    //close the socket
    if(master_fd>=0) close(master_fd);

    cout<<"radioApplication: DONE"<<endl;

    return retVal;
}

void *recv_func(void *arg)
{
    int fd = *(int *)arg;
    struct sockaddr_in remoteAddr;
    socklen_t addrlen = sizeof(remoteAddr);
    const int MAX_SIZE=256;
    const int IP_SIZE=16;
    char buf[MAX_SIZE];
    char remoteIP[IP_SIZE];
    int remotePort;
    char remoteFullAddr[ADDR_LEN];

   //Set a socket timeout of 5 seconds
    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    setsockopt(fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    while(is_running) {
        memset(buf,0,MAX_SIZE);
        int len = recvfrom(fd, buf, MAX_SIZE, 0, (struct sockaddr *)&remoteAddr, &addrlen);
	if(len > 0) {
	    strncpy(remoteIP, inet_ntoa(remoteAddr.sin_addr), IP_SIZE);
	    remotePort = ntohs(remoteAddr.sin_port);
	    sprintf(remoteFullAddr, "%s:%d", remoteIP, remotePort);
            //Is the address valid?
            bool isFound=false;
            for(int i=0; i<NUM_CLIENTS && !isFound; ++i) {
                if(strcmp(client[i], remoteFullAddr)==0) isFound=true;
            }
	    if(!isFound) cout<<"Invalid client at "<<remoteFullAddr<<endl;
            else {
                pthread_mutex_lock(&lock_x);
                DestPacket packet;
                packet.source = 10*(buf[0]-48)+(buf[1]-48);//the first two bytes contains the source
		//ASCII '0' equals 48
                packet.packetNo = packetNo++;
                strncpy(packet.message, &buf[2], BUF_LEN);//the remainder contains the message
                destPacket.push(packet);
                pthread_mutex_unlock(&lock_x);
	    }
        }
    }
    pthread_exit(NULL);
}

void *transmit_func(void *arg)
{
    int fd = *(int *)arg;
    struct sockaddr_in destAddr;
    socklen_t addrlen = sizeof(destAddr);
    const int MAX_SIZE=256;
    char buf[MAX_SIZE];

    //set up the destination address of the transmissions
    memset((char *)&destAddr, 0, sizeof(destAddr));
    destAddr.sin_family = AF_INET;
    destAddr.sin_port = htons(DEST_PORT);
    int ret = inet_pton(AF_INET, DEST_ADDR, &destAddr.sin_addr);
    if(ret==0) {
        cout<<"No such address... transmit thread aborted"<<endl;
        cout<<strerror(errno)<<endl;
    } else {
        while(is_running) {
            pthread_mutex_lock(&lock_x);
            while(destPacket.size()>0) {
                DestPacket packet;
                packet = destPacket.front();
                destPacket.pop();	
                memset(buf,0,MAX_SIZE);
		int len=sprintf(buf, "%d %d %s", packet.source, packet.packetNo, packet.message);
                sendto(fd, buf, len, 0, (struct sockaddr *)&destAddr, sizeof(destAddr));
            }
            pthread_mutex_unlock(&lock_x);
        }
    }
    pthread_exit(NULL);
}
