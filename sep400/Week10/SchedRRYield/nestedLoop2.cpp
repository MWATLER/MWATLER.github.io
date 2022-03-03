//nestedLoop2.cpp - main program for testing the nested loop

#include <iostream>
#include <sched.h>
#include <sys/resource.h>

using namespace std;

int main() {
    int minPriority = sched_get_priority_min(SCHED_RR);
    int maxPriority = sched_get_priority_max(SCHED_RR);
    cout<<"nestedLoop2: minPriority:"<<minPriority<<" maxPriority:"<<maxPriority<<endl;

    sched_param scheduler;
    scheduler.sched_priority = maxPriority;
    sched_setscheduler(0, SCHED_RR, &scheduler);

    const long nanosecsPerSecond=1000000000;
    timespec timeSpec;
    sched_rr_get_interval(0, &timeSpec);
    double interval = (double)(timeSpec.tv_sec*nanosecsPerSecond + timeSpec.tv_nsec)/nanosecsPerSecond;
    cout<<"nestedLoop2: interval:"<<interval<<"s"<<endl;

    cout << "nestedLoop2: performing 3 dimensional nested loops"<<endl;
    for(int i=0; i<=30000; i+=1000) {
        for(int j=0; j<i; ++j) {
            sched_yield();
            for(int k=0; k<i; ++k) {
                int l=j*k;//do something
            }
        }
    }
    cout << "nestedLoop2: DONE"<<endl;
    return 0;
}
