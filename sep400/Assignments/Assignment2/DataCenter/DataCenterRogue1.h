//DataCenterRogue1.h - The class for the rogue1 Data Center
//
// History:
// 05-May-22  M. Watler         Created.

#ifndef _DATACENTERROGUE1_H_
#define _DATACENTERROGUE1_H_

#include <arpa/inet.h>
#include <iostream>
#include <net/if.h>
#include <netinet/in.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

static void shutdownHandler(int sig);
void *recv_func(void *arg);

class DataCenterRogue1 {
    const int BUF_LEN=4096;
    bool is_running;
    bool is_subscribed;
    int dataCenterNo;
    int fd;
public:
    DataCenterRogue1(int num);
    int run();
    void shutdown();
    void ReceiveFunction();
    static DataCenterRogue1* instance;
};

#endif// _DATACENTERROGUE1_H_
