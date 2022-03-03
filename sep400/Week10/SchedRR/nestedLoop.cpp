//nestedLoop.cpp - main program for testing the nested loop

#include <fstream>
#include <iostream>
#include <sched.h>
#include <sys/resource.h>

using namespace std;

int main() {
    int niceValue = getpriority(PRIO_PROCESS, 0);
    cout<<"nestedLoop: niceValue:"<<niceValue<<endl;

    int retVal = setpriority(PRIO_PROCESS, 0, 0);
    niceValue = getpriority(PRIO_PROCESS, 0);
    cout<<"nestedLoop: retVal:"<<retVal<<" niceValue:"<<niceValue<<endl;

    int minPriority = sched_get_priority_min(SCHED_RR);
    int maxPriority = sched_get_priority_max(SCHED_RR);
    cout<<"nestedLoop: minPriority:"<<minPriority<<" maxPriority:"<<maxPriority<<endl;

    sched_param scheduler;
    scheduler.sched_priority = maxPriority;
    sched_setscheduler(0, SCHED_RR, &scheduler);


    const long nanosecsPerSecond=1000000000;
    timespec timeSpec;
    sched_rr_get_interval(0, &timeSpec);
    double interval = (double)(timeSpec.tv_sec*nanosecsPerSecond + timeSpec.tv_nsec)/nanosecsPerSecond;
    cout<<"nestedLoop: interval:"<<interval<<"s"<<endl;


    timespec startTime, endTime;
    double totalTime;
    //store the results to a file
    ofstream outfile;
    outfile.open("searchTime.dat");
    cout << "performing 3 dimensional nested loops"<<endl;
    for(int i=0; i<=30000; i+=1000) {
        clock_gettime(CLOCK_REALTIME, &startTime);
        for(int j=0; j<i; ++j) {
            for(int k=0; k<i; ++k) {
                int l=j*k;//do something
            }
        }
        clock_gettime(CLOCK_REALTIME, &endTime);
        totalTime = (double)(endTime.tv_sec-startTime.tv_sec)*nanosecsPerSecond + (endTime.tv_nsec-startTime.tv_nsec);
        outfile << i << ", " << totalTime << endl;
    }
    outfile.close();
    cout<<"nestedLoop: DONE"<<endl;

    return 0;
}
