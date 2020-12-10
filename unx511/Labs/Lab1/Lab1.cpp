//Lab1.cpp - process monitor
//
// 08-Jan-19  M. Watler         Created.
//
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>

using namespace std;

char procDir[] = "/proc";

int main(void)
{
    vector<string> directories;
    DIR *dp;
    struct dirent *dirp;

    dp=opendir(procDir);
    if(dp==NULL) {
        cout << "Could not open the directory " << procDir << endl;
        return 1;
    }

    while(dirp=readdir(dp)) {
        if(isdigit(dirp->d_name[0])) {
            directories.push_back(dirp->d_name);
        }
    }

    closedir(dp);

    bool is_running = true;
    while(is_running) {
    system("clear");
    for(int i=0; i<directories.size(); ++i) {
	string filename = "/proc/" + directories.at(i) + "/status";
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
                    if(VmRss>=1000) {
                        cout << "Name: " << name << " Pid: " << pid << " VmRss: " << vmrss << endl;
                    }
                }
            }
        }
	infile.close();
    }
    sleep(2);
    }

    return 0;
}
