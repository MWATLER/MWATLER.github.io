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

void CreateTestFile(const char* name);
int ProcessChild(int num, int numProc, string fileName, int fileSize, string searchStr);
int ProcessParent();

const long nanosecsPerSecond=1000000000;

int main() {
    string filename;
    string searchString;
    int numProcesses;
    int filesize;
    bool isParent;
    int err;
    timespec ts1, ts2;
    double elapsedTime;

    cout << "Enter the name of the file to search: ";
    cin >> filename;
    cout << "Enter the string to search: ";
    cin >> searchString;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    struct stat filestatus;
    int ret=stat(filename.c_str(), &filestatus);
    if(ret<0) CreateTestFile(filename.c_str());
    stat(filename.c_str(), &filestatus);
    filesize = filestatus.st_size;//in bytes

    clock_gettime(CLOCK_REALTIME, &ts1);
    isParent=true;
    for(int i=0; i<numProcesses && isParent; ++i) {
        pid_t childId = fork();
        if(childId==0) {
            isParent = false;
            err=ProcessChild(i, numProcesses, filename, filesize, searchString);
        }
    }
    if(isParent) {
        err=ProcessParent();
        clock_gettime(CLOCK_REALTIME, &ts2);
	elapsedTime = (double)(ts2.tv_sec-ts1.tv_sec)*nanosecsPerSecond + (ts2.tv_nsec-ts1.tv_nsec);
        elapsedTime /= nanosecsPerSecond;
	cout<<"The search took "<<elapsedTime<<" seconds"<<endl;
    }

    return err;
}

int ProcessChild(int num, int numProc, string fileName, int fileSize, string searchStr)
{
    string data;
    bool found = false;
    int begin = fileSize*num/numProc;
    int end   = fileSize*(num+1)/numProc;
    ifstream infile;
    infile.open(fileName.c_str());
    infile.seekg(begin);
cout << "ProcessChild["<<getpid()<<"]: tellg:"<<infile.tellg()<<" end:"<<end<<endl;
    while(infile.tellg()<end && !found) {
        infile >> data;
	if(data==searchStr) found=true;
    }
    infile.close();
    if(found) return 0;
    return -1;
}

int ProcessParent()
{
    int status=-1;
    pid_t pid=0;

    while(pid>=0 && status<0) {
cout << "ProcessParent["<<getpid()<<"]: pid=wait(&status)"<<endl;
        pid=wait(&status);
	if(status==0) {
            cout << "ProcessParent["<<getpid()<<"]: The string has been found in pid " << pid << endl;
	}
    }
    return 0;
}

void CreateTestFile(const char* name)
{
    cout<<"Creating the Test file"<<endl;
    ofstream outfile;
    outfile.open(name);
    for(int i=0; i<9999999; ++i)
        outfile<<"Hello World"<<endl;
    outfile<<"Hello Bambi"<<endl;
    for(int i=0; i<10000000; ++i)
        outfile<<"Hello World"<<endl;
    cout<<"Test file created"<<endl;

    outfile.close();
}
