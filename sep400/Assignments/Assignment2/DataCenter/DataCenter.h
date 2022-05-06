//DataCenter.h - The class for the Data Center
//
// History:
// 05-May-22  M. Watler         Created.

#ifndef _DATACENTER_H_
#define _DATACENTER_H_

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

class DataCenter {
    const int BUF_LEN=4096;
    bool is_running;
    bool is_subscribed;
    int dataCenterNo;
    int fd;
public:
    DataCenter(int num);
    int run();
    void shutdown();
    void ReceiveFunction();
    static DataCenter* instance;
};

#endif// _DATACENTER_H_
