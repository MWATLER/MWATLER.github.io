//Transducer.cpp - Converts seismic activity into a data stream which is written
//                 into shared memory
//
// History:
// 03-May-22  M. Watler         Created.

#include "Transducer.h"

Transducer* Transducer::instance=nullptr;

using namespace std;

static void interruptHandler(int signum)
{
    switch(signum) {
        case SIGINT:
            Transducer::instance->shutdown();
            break;
    }
}

Transducer::Transducer() {
    is_running=false;
    ShmPTR=nullptr;
    Transducer::instance = this;
}

void Transducer::createRandByteArray(unsigned char *buf, int size)
{
    for(int i =0; i<size; i++)
    {
        buf[i] = 32/*space*/ +((int)rand())%95;//alpha-numeric characters
    }
}

void Transducer::shutdown() {
    cout<<"Transducer::shutdown:"<<endl;
    is_running=false;
}

int Transducer::run() {
    action.sa_handler = interruptHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

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
    //struct SeismicData {
    //    MemStatus      status;
    //    unsigned short packetLen;
    //    char           data[BUF_LEN];
    //};
    //
    //struct SeismicMemory {
    //    unsigned short packetNo;
    //    struct SeismicData seismicData[NUM_DATA];
    //};

    ShmID=shmget(ShmKey, sizeof(struct SeismicMemory), IPC_CREAT | 0666);
    if (ShmID < 0) {
        cout<<"Transducer: shmget() error"<<endl;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    //void *shmat(int shmid, const void *shmaddr, int shmflg);
    //
    //shmat() attaches the shared memory segment identified by shmid to the
    //address space of the calling process. The attaching address is specified
    //by shmaddr. If shmaddr is NULL, the system chooses a suitable (unused)
    //page-aligned address to attach the segment.
    ShmPTR = (struct SeismicMemory *) shmat(ShmID, NULL, 0);
    if (ShmPTR == (void *)-1) {
        cout<<"Transducer: shmat() error"<<endl;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    // initialize named semaphore, can be used between processes
    // If O_CREAT is specified, and a semaphore with the given name
    // already exists, then mode and value are ignored.
    sem_id1 = sem_open(SEMNAME, O_CREAT, SEM_PERMS, 1);
    is_running=true;
    int seismicDataIndex=0;
    ShmPTR->packetNo=0;;
    while(is_running) {
        //Semaphores might not be necessary
        if(ShmPTR->seismicData[seismicDataIndex].status!=WRITTEN) {
            unsigned char buffer[BUF_LEN];
	    createRandByteArray(buffer, BUF_LEN);
            sem_wait(sem_id1);
            if(++ShmPTR->packetNo>PACKET_NO_MAX) {
                ShmPTR->packetNo=0;
            }
            ShmPTR->seismicData[seismicDataIndex].packetLen = BUF_LEN;
            memcpy(ShmPTR->seismicData[seismicDataIndex].data, buffer, BUF_LEN);
            ShmPTR->seismicData[seismicDataIndex].status=WRITTEN;
            sem_post(sem_id1);
            ++seismicDataIndex;
            if(seismicDataIndex>NUM_DATA) seismicDataIndex=0;
        }
	sleep(1);
    }
    sem_close(sem_id1);
    sem_unlink(SEMNAME);

    shmdt((void *)ShmPTR);
    shmctl(ShmID, IPC_RMID, NULL);

    cout<<"Transducer: DONE"<<endl;

    return 0;
}
