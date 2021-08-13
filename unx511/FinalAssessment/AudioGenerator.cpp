// AudioGenerator.cpp - Generates audio from text
//
// 29-Jul-21  M. Watler         Created.
//

#include <errno.h>
#include <iostream>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include "sharedMem.h"

using namespace std;
bool isRunning;
const char LOG_FILE[]="logFile.txt";

void *sendThread(void *arg);

void shutdownHandler(int signal)
{
    switch(signal) {
        case SIGINT:
            cout<<"Audio Generator shutting down"<<endl;
            isRunning = false;
            break;
    }
}

int main(void) {
    pthread_t sendId;
    int ret;
    double samplingFrequency=20000.0;//20KHz

    //Intercept ctrl-C
    struct sigaction action;

    action.sa_handler = shutdownHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    //Start the send thread
    isRunning=true;
    ret = pthread_create(&sendId, NULL, sendThread, &samplingFrequency);

    int selection=-1;
    while(selection!=0) {
        system("clear");
        cout<<"AUDIO GENERATOR"<<endl;
        cout<<"Current sampling frequency: "<<samplingFrequency<<endl<<endl;
        cout<<" 1. Set the sampling frequency"<<endl;
        cout<<" 2. Dump the log file here"<<endl;
        cout<<" 0. Shut down"<<endl<<endl;
        cout<<" selection: ";
        cin>>selection;
        if(selection>=0 && selection<=2) {
            int fdIn, numRead;
            char key;
            cout<<endl;
            switch(selection) {
                case 1:
                    cout<<"New sampling frequency (in Hz): ";
                    //Question: If sampling frequency is changed here, will it be changed in the send thread?
                    cin>>samplingFrequency;
                    if(samplingFrequency<=0) {
                        cout<<"Sampling frequency must be greater than zero"<<endl;
                        cout<<endl<<"Press any key to continue: ";
                        cin>>key;
                    }
                    break;
                case 2:
                    char buffer[BUF_LEN];
                    fdIn=open(LOG_FILE, O_RDONLY);
                    do {
                        numRead = read(fdIn, buffer, BUF_LEN);
                        //Question: What is the name of the file that is being dumped to the screen?
                        cout<<buffer;
                    } while (numRead>0);
                    close(fdIn);
                    cout<<endl<<"Press any key to continue: ";
                    cin>>key;
                    break;
                case 0:
                    isRunning=false;
                    break;
            }
        }
    }

    //Question: What happens if we do not use pthread_join()
    pthread_join(sendId, NULL);
    int pid=fork();
    if(pid==0) {
        //Question: How many AudioGenerator processes are running at this point?
        //Question: What is execlp attempting to do?
        execlp("pkill", "pkill", "-2", "Encoder", NULL);
    }
    cout<<"AudioGenerator: DONE"<<endl;

    return 0;
}

void *sendThread(void *arg)
{
    double *frequency = (double *)arg;
    double samplingPeriod;
    sem_t *sem_id;
    key_t ShmKey;
    int   ShmID;
    struct Memory *ShmPTR;
    int fd[6], fdLog;
    const char LEFT_FILE[]="AudioBookLeft.txt";
    const char RIGHT_FILE[]="AudioBookRight.txt";
    const char CENTER_FILE[]="AudioBookCenter.txt";
    const char LEFT_SURROUND_FILE[]="AudioBookLeftSurround.txt";
    const char RIGHT_SURROUND_FILE[]="AudioBookRightSurround.txt";
    const char LFE_FILE[]="AudioBookLowFrequencyEffects.txt";
    char buf[BUF_LEN];
    int size, packetIndex;
    timespec ts;
    const long nanosecsPerSecond=1000000000;

    //Question: What process uses this semaphore with the audio generator?
    //Question: What is the initial value of this semaphore?
    sem_id=sem_open(SEMNAME, O_CREAT, SEM_PERMS, 0);
    if(sem_id==SEM_FAILED) {
        cout<<"AudioGenerator: sem_open() error"<<endl;
        cout<<strerror(errno)<<endl;
        cout<<"pthread_exit"<<endl;
        pthread_exit(NULL);;
    }

    //Question: What process uses this shared memory with the audio generator?
    ShmKey=ftok(MEMNAME, 65);
    //Question: Roughly, how big is this shared memory (please respond in bytes)?
    ShmID=shmget(ShmKey, sizeof(struct Memory), IPC_CREAT | 0666);
    if (ShmID < 0) {
        cout<<"AudioGenerator: shmget() error"<<endl;
        cout<<strerror(errno)<<endl;
        sem_close(sem_id);
        sem_unlink(SEMNAME);
        cout<<"pthread_exit"<<endl;
        pthread_exit(NULL);;
    }
    //Question: What structure is this shared memory based on?
    ShmPTR = (struct Memory *) shmat(ShmID, NULL, 0);
    if (ShmPTR == (void *)-1) {
        cout<<"AudioGenerator: shmat() error"<<endl;
        cout<<strerror(errno)<<endl;
        shmctl(ShmID, IPC_RMID, NULL);
        sem_close(sem_id);
        sem_unlink(SEMNAME);
        cout<<"pthread_exit"<<endl;
        pthread_exit(NULL);;
    }

    //Question: We are reading from the text files called AudioBookLeft.txt, AudioBookRight.txt, AudioBookCenter.txt, AudioBookLeftSurround.txt, AudioBookRightSurround.txt, and AudioBookLowFrequencyEffects. Where are we going to put the contents of these text files?
    fd[0]=open(LEFT_FILE, O_RDONLY);
    fd[1]=open(RIGHT_FILE, O_RDONLY);
    fd[2]=open(CENTER_FILE, O_RDONLY);
    fd[3]=open(LEFT_SURROUND_FILE, O_RDONLY);
    fd[4]=open(RIGHT_SURROUND_FILE, O_RDONLY);
    fd[5]=open(LFE_FILE, O_RDONLY);
    for(int i=0; i<NUM_CHANNELS; ++i) {
        if(fd[i]<0) {
            cout<<"AudioGenerator: Error opening audio files"<<endl;
            cout<<strerror(errno)<<endl;
            for(int j=i-1; j>=0; --j) {
                close(fd[j]);
            }
            shmdt((void *)ShmPTR);
            shmctl(ShmID, IPC_RMID, NULL);
            sem_close(sem_id);
            sem_unlink(SEMNAME);
            cout<<"pthread_exit"<<endl;
            pthread_exit(NULL);
        }
    }
    //Question: What happens if LOG_FILE already has content at this point?
    fdLog=open(LOG_FILE, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    isRunning=true;
    packetIndex=0;
    //Question: What is the audio generator waiting on at this point?
    sem_wait(sem_id);
    while(isRunning) {
        //Question: Why can't we proceed if status is set to WRITTEN?
        if(ShmPTR->packet[packetIndex].status == WRITTEN) {
            char msg[64];
            time_t my_time=time(NULL);
            sprintf(msg, "AudioGenerator: %sThis segment has not been read yet\n\n", ctime(&my_time));
            write(fdLog, msg, strlen(msg));
        } else {
            //Question: Why might we need a packet number?
            ShmPTR->packet[packetIndex].packetNumber=packetIndex+1;
            clock_gettime(CLOCK_REALTIME, &ts);
            //Question: Why do we need a time stamp?
            ShmPTR->packet[packetIndex].timeStamp = ts.tv_sec*nanosecsPerSecond + ts.tv_nsec;
            memset(ShmPTR->packet[packetIndex].left, 0, BUF_LEN);
            memset(ShmPTR->packet[packetIndex].right, 0, BUF_LEN);
            memset(ShmPTR->packet[packetIndex].center, 0, BUF_LEN);
            memset(ShmPTR->packet[packetIndex].leftSurround, 0, BUF_LEN);
            memset(ShmPTR->packet[packetIndex].rightSurround, 0, BUF_LEN);
            memset(ShmPTR->packet[packetIndex].lowFrequencyEffects, 0, BUF_LEN);
            //Question: What does len represent?
            ShmPTR->packet[packetIndex].len = read(fd[0], ShmPTR->packet[packetIndex].left, BUF_LEN);
            ShmPTR->packet[packetIndex].len+= read(fd[1], ShmPTR->packet[packetIndex].right, BUF_LEN);
            ShmPTR->packet[packetIndex].len+= read(fd[2], ShmPTR->packet[packetIndex].center, BUF_LEN);
            ShmPTR->packet[packetIndex].len+= read(fd[3], ShmPTR->packet[packetIndex].leftSurround, BUF_LEN);
            ShmPTR->packet[packetIndex].len+= read(fd[4], ShmPTR->packet[packetIndex].rightSurround, BUF_LEN);
            ShmPTR->packet[packetIndex].len+= read(fd[5], ShmPTR->packet[packetIndex].lowFrequencyEffects, BUF_LEN);
            //Question: Where is the data for the audio channel 'low frequency effects' actually stored inside of the structure Packet?
            if(ShmPTR->packet[packetIndex].len == 0) {//End of file
                //Question: What does lseek() do at this point?
                for(int i=0; i<NUM_CHANNELS; ++i) {
                    lseek(fd[i], 0, SEEK_SET);
                }
                ShmPTR->packet[packetIndex].len = read(fd[0], ShmPTR->packet[packetIndex].left, BUF_LEN);
                ShmPTR->packet[packetIndex].len+= read(fd[1], ShmPTR->packet[packetIndex].right, BUF_LEN);
                ShmPTR->packet[packetIndex].len+= read(fd[2], ShmPTR->packet[packetIndex].center, BUF_LEN);
                ShmPTR->packet[packetIndex].len+= read(fd[3], ShmPTR->packet[packetIndex].leftSurround, BUF_LEN);
                ShmPTR->packet[packetIndex].len+= read(fd[4], ShmPTR->packet[packetIndex].rightSurround, BUF_LEN);
                ShmPTR->packet[packetIndex].len+= read(fd[5], ShmPTR->packet[packetIndex].lowFrequencyEffects, BUF_LEN);
            }
#ifdef DEBUG
            cout<<"AudioGenerator: packet number "<<ShmPTR->packet[packetIndex].packetNumber<<endl;
#endif
            //Question: Why are we setting status to WRITTEN at this point?
            ShmPTR->packet[packetIndex].status=WRITTEN;
            if(ShmPTR->packet[packetIndex].len<0) {
                cout<<"AudioGenerator: Error reading the audio files"<<endl;
                cout<<strerror(errno)<<endl;
                for(int i=0; i<NUM_CHANNELS; ++i) {
                    close(fd[i]);
                }
                shmdt((void *)ShmPTR);
                shmctl(ShmID, IPC_RMID, NULL);
                sem_close(sem_id);
                sem_unlink(SEMNAME);
                cout<<"pthread_exit"<<endl;
                pthread_exit(NULL);;
            }
            //Question: What is the purpose of packetIndex?
            ++packetIndex;
            if(packetIndex>=NUM_PACKETS) {
                packetIndex=0;
#ifdef DEBUG2
                int openFlags = O_CREAT | O_WRONLY | O_TRUNC;
                mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

                int fdTest=open("TestFile.txt", openFlags, filePerms);
                for(int i=0; i<NUM_PACKETS; ++i) {
                    write(fdTest, &ShmPTR->packet[i].left, BUF_LEN);
                    write(fdTest, &ShmPTR->packet[i].right, BUF_LEN);
                    write(fdTest, &ShmPTR->packet[i].center, BUF_LEN);
                    write(fdTest, &ShmPTR->packet[i].leftSurround, BUF_LEN);
                    write(fdTest, &ShmPTR->packet[i].rightSurround, BUF_LEN);
                    write(fdTest, &ShmPTR->packet[i].lowFrequencyEffects, BUF_LEN);
                }
                close(fdTest);
#endif
            }
        }
        samplingPeriod = 1000000.0/(*frequency);
        usleep(samplingPeriod);
    }

    //Detach the memory
    shmdt((void *)ShmPTR);
    //Question: Which process actually destroys the shared memory?
    shmctl(ShmID, IPC_RMID, NULL);

    //Close the semaphore
    sem_close(sem_id);
    sem_unlink(SEMNAME);

    //Close the audio text files and the log file
    for(int i=0; i<NUM_CHANNELS; ++i) {
       close(fd[i]);
    }
    close(fdLog);

    cout<<"AudioGenerator: pthread_exit"<<endl;
    pthread_exit(NULL);
}
