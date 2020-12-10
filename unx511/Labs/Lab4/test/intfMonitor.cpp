//intfMonitor_solution.cpp - An interface monitor
//
// 13-Jul-20  M. Watler         Created.
// 22-Jul-20  L. Kloosterman    Modified

#include <fcntl.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

using namespace std;

const int MAXBUF=128;
bool isRunning=false;

static void signalHandler(int signal);

int main(int argc, char *argv[])
{
    struct sigaction new_action;

    char interface[MAXBUF];
    char statPath[MAXBUF];
    const char logfile[]="Network.log";//store network data in Network.log
    int retVal=0;

    bool should_continue = true;

    // Populate the sigaction struct's members for the handler and the mask
    new_action.sa_handler = signalHandler;
    sigemptyset(&(new_action.sa_mask));
    sigaddset(&(new_action.sa_mask), SIGUSR1);
    sigaddset(&(new_action.sa_mask), SIGUSR2);
    sigaddset(&(new_action.sa_mask), SIGINT);
    sigaddset(&(new_action.sa_mask), SIGTSTP);

    // Use sigaction on all of the signals we need to send to the handler,
    // making sure that none of them fail; otherwise the rest of the program
    // won't run
    int return_value = sigaction(SIGUSR1, &new_action, NULL);

    if (return_value != -1)
        return_value = sigaction(SIGUSR2, &new_action, NULL);

    if (return_value != -1)
        return_value = sigaction(SIGINT, &new_action, NULL);

    if (return_value != -1)
        return_value = sigaction(SIGTSTP, &new_action, NULL);

    if (return_value != -1) {
        strncpy(interface, argv[1], MAXBUF);//The interface has been passed as an argument to intfMonitor
        int fd=open(logfile, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
        cout<<"intfMonitor:main: interface:"<<interface<<":  pid:"<<getpid()<<endl;

        // Sleep every second to wait until the SIGUSR1 (start) signal is
        // received so the following loop can start
        while (!isRunning) {
            sleep(1);
        }

        while(isRunning) {
            //gather some stats
            int tx_bytes=0;
            int rx_bytes=0;
            int tx_packets=0;
            int rx_packets=0;
            ifstream infile;
                sprintf(statPath, "/sys/class/net/%s/statistics/tx_bytes", interface);
            infile.open(statPath);
            if(infile.is_open()) {
                infile>>tx_bytes;
                infile.close();
            }
                sprintf(statPath, "/sys/class/net/%s/statistics/rx_bytes", interface);
            infile.open(statPath);
            if(infile.is_open()) {
                infile>>rx_bytes;
                infile.close();
            }
                sprintf(statPath, "/sys/class/net/%s/statistics/tx_packets", interface);
            infile.open(statPath);
            if(infile.is_open()) {
                infile>>tx_packets;
                infile.close();
            }
                sprintf(statPath, "/sys/class/net/%s/statistics/rx_packets", interface);
            infile.open(statPath);
            if(infile.is_open()) {
                infile>>rx_packets;
                infile.close();
            }
            char data[MAXBUF];
            //write the stats into Network.log
            int len=sprintf(data, "%s: tx_bytes:%d rx_bytes:%d tx_packets:%d rx_packets: %d\n", interface, tx_bytes, rx_bytes, tx_packets, rx_packets);
            write(fd, data, len);
            sleep(1);
        }
        close(fd);
    } else {
        return return_value;
    }

    return 0;
}

static void signalHandler(int signal) {
    // Check which signal is being used
    switch (signal) {
        // If the start signal is received, print out the line and set isRunning
        // to true
        case SIGUSR1:
        {
            cout << "intfMonitor: starting up" << endl;
            isRunning = true;
            break;
        }
        // If the Ctrl-C signal is received, print out the line and do nothing
        case SIGINT:
        {
            cout << "intfMonitor: ctrl-C discarded" << endl;
            break;
        }
        // If the Ctrl-Z signal is received, print out the line and do nothing
        case SIGTSTP:
        {
            cout << "intfMonitor: ctrl-Z discarded" << endl;
            break;
        }
        // If the stop signal is received, print out the line and set isRunning
        // to false
        case SIGUSR2:
        {
            cout << "intfMonitor: shutting down" << endl;
            isRunning = false;
            break;
        }
        // If anything else is recieved, print a line saying it's undefined and
        // do nothing else
        default:
        {
            cout << "intfMonitor: undefined signal" << endl;
        }
    }
}
