//MemMonitor.cpp - memory monitor
//
// 13-Jan-19  M. Watler         Created.
//
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

int main(void)
{
    string modelName, cpuMhz;
    string MemTotal, MemFree, MemAvailable;
    string procRunning, procBlocked;
    string uptime, idle;
    ifstream infile;
    bool isRunning = true;

    while(isRunning) {
        system("clear");//system() issues a system command on the command line
        cout << "MEMORY MONITOR" << endl << endl;

        // The file /proc/cpuinfo contains a collection of CPU and
        // system architecture dependent items
        infile.open("/proc/cpuinfo");
        if(infile.is_open()) {
            string data;
            bool dataFound = false;
            while(!dataFound && !infile.eof()) {
                infile >> data;
                // Search for model name
                if(data=="model") {
                    infile >> data;
                    if(data=="name") {
                        infile >> data;
                        getline(infile, modelName);
                    }
                // Search for cpu speed
                } else if(data=="cpu") {
                    infile >> data;
                    if(data=="MHz") {
                        infile >> cpuMhz;
                        infile >> cpuMhz;
                        dataFound = true;
                    }
                }
            }
            infile.close();
        }

        // The file /proc/meminfo reports statistics about memory usage on the system.
        infile.open("/proc/meminfo");
        if(infile.is_open()) {
            string data;
            infile >> data;
            infile >> MemTotal;
            infile >> data;
            infile >> data;
            infile >> MemFree;
            infile >> data;
            infile >> data;
            infile >> MemAvailable;
            infile.close();
        }

        // The file /proc/stat reports kernel/system statistics
        infile.open("/proc/stat");
        if(infile.is_open()) {
            string data;
            bool dataFound = false;
            while(!dataFound && !infile.eof()) {
                infile >> data;
                if(data=="procs_running") {
                    infile >> procRunning;
                } else if(data=="procs_blocked") {
                    infile >> procBlocked;
                    dataFound = true;
                }
            }
            infile.close();
        }

        // The file /proc/uptime contains the uptime of the system (seconds),
        // and the amount of time spent in idle process (seconds)
        infile.open("/proc/uptime");
        if(infile.is_open()) {
            infile >> uptime;
            infile >> idle;
            infile.close();
        }

        // Display all stats and then sleep
        cout << "Model Name:   " << modelName << endl;
        cout << "CPU MHz:       " << cpuMhz << endl;
        cout << endl;
        cout << "Mem Total:     " << MemTotal << " kB" << endl;
        cout << "Mem Free:      " << MemFree << " kB" << endl;
        cout << "Mem Avail:     " << MemAvailable << " kB" << endl;
        cout << endl;
        cout << "Procs Running: " << procRunning << endl;
        cout << "Procs Blocked: " << procBlocked << endl;
        cout << endl;
        cout << "System Uptime: " << uptime << endl;
        cout << "System Idle:   " << idle << endl;
        sleep(1);
    }

    return 0;
}
