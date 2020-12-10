//procMonitor.cpp - process monitor child
//
// 05-Feb-20  M. Watler         Created.
//
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>

using namespace std;

char procDir[] = "/proc";

int main(int argc, char *argv[])
{
    bool isRunning=true;
    int begin;
    int end;
    int retVal=0;

    if(argc<3) {
        cout<<"procMonitor: Incorrect number of parameters"<<endl;
	isRunning=false;
	retVal=-1;
    } else {
        begin = atoi(argv[1]);
        end = atoi(argv[2]);
        cout<<"procMonitor:main: pid:"<<getpid()<<" begin:"<<begin<<" end:"<<end<<endl;
    }
    while(isRunning) {
        for(int i=begin; i<=end; ++i) {
            string filename = "/proc/" + to_string(i) + "/status";
            string name;
            string pid;
            string vmrss;
            ifstream infile(filename.c_str());
            if(infile.is_open()) {
                string data;
                while(!infile.eof()) {
                    infile >> data;
                    if(data=="Name:") {
                        infile >> name;
                    } else if(data=="Pid:") {
                        infile >> pid;
                    } else if(data=="VmRSS:") {
                        infile >> vmrss;
                        int VmRss = atoi(vmrss.c_str());
                        if(VmRss>=10000) {
                            cout<<"Name: "<<name<<" Pid: "<<pid<<" VmRss: "<<vmrss<<endl;
                        }
                    }
                }
                infile.close();
            }
        }
	sleep(1);
    }

    return retVal;
}
