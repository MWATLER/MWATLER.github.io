//fork1.cpp - Test the fork() function in Linux
//
// 01-Feb-19  M. Watler         Created.

#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

const long nanosecsPerSecond=1000000000;

int main() {
    string filename;
    string searchStr;
    string data;
    bool found;
    int err;
    timespec ts1, ts2;
    double elapsedTime;

    cout << "Enter the name of the file to search: ";
    cin >> filename;
    cout << "Enter the string to search: ";
    cin >> searchStr;

    clock_gettime(CLOCK_REALTIME, &ts1);
    ifstream infile;
    infile.open(filename.c_str());
    while(!infile.eof() && !found) {
        infile >> data;
        if(data==searchStr) {
	    found=true;
            cout << "ProcessParent["<<getpid()<<"]: The string has been found"<< endl;
            clock_gettime(CLOCK_REALTIME, &ts2);
            elapsedTime = (double)(ts2.tv_sec-ts1.tv_sec)*nanosecsPerSecond + (ts2.tv_nsec-ts1.tv_nsec);
            elapsedTime /= nanosecsPerSecond;
            cout<<"The search took "<<elapsedTime<<" seconds"<<endl;
	}
    }
    infile.close();
    if(found) return 0;
    return -1;
}
