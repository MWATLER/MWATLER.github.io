// hack.cpp - A program that attempts to break the RSA encryption while varying the
//            priority of the current process
//
//
#include <fstream>
#include <iostream>
#include <math.h>
#include <sched.h>
#include <sys/resource.h>

using namespace std;

bool DeterminePrimes();

// Code to hack the RSA algorithm
int main()
{
    int ret=0;
    int retVal=0;
    const long nanosecsPerSecond=1000000000;
    timespec startTime, endTime;
    double totalTime;

    //TODO: Open a file


    //TODO: Call DeterminePrimes() 20 times while varying the
    //      priority from -20 to +19
    //TODO: For each call to DeterminePrimes() measure the time
    //      taken to crack the modulus n of the RSA scheme.
    //TODO: Use the high resolution timing function clock_gettime()
    //      which gives time to the nanosecond.
    //      Store the time before the call to DeterminePrimes() and
    //      after the call to DeterminePrimes(). The difference is the
    //      time it took to hack them modulus n of the RSA scheme.
    //TODO: Store the hack time of each call in a file
    //TODO: You will make a plot of hack-time vs nice value


    //TODO: Be sure to close your file when done

    return ret;
}

bool DeterminePrimes() {
    unsigned long long n=5335952767283123;//49182449ull * 108493027ull
    unsigned long long p=2;
    unsigned long long q=0;
    long double temp;
    bool found=false;
    while(!found && p<n) {
        temp = (long double)n/p;
        q = n/p;
	    if(temp==(long double)q) found=true;//no numbers after the decimal place
                                            //means we have found a factor
	    else ++p;//Usually we would call a function to get the next prime number
	             //instead of simply incrementing by one. But such a function does
                 //basically the same thing as we are doing here.
    }
    if(found) {
        cout<<"p:"<<p<<" q:"<<q<<" n:"<<n<<endl;
    } else {
        cout<<"factors not found for n:"<<n<<endl;
    }
    return found;
}
