//pidUtil.cpp - A library of process utility functions
//
// 10-Jan-19  M. Watler         Created.
//
#include <dirent.h>
#include <fstream>
#include <vector>
#include "pidUtil.h"

using namespace std;

char procDir[] = "/proc";

string errMsg[] = {
    "OK",
    "Unable to open directory",
    "No such pid",
    "No such name"
};

ErrStatus GetAllPids(vector<int> &pidList)
{
    vector<string> directories;
    DIR *dp;
    struct dirent *dirp;

    dp=opendir(procDir);
    if(dp==NULL) {
        cout << "Could not open the directory " << procDir << endl;
        return Err_DirOpen;
    }

    while(dirp=readdir(dp)) {
        if(isdigit(dirp->d_name[0])) {
            pidList.push_back(stoi(dirp->d_name));
        }
    }

    closedir(dp);
    return Err_OK;
}

ErrStatus GetNameByPid(int pid, string &name)
{
    string filename = "/proc/" + to_string(pid) + "/comm";
    ifstream infile(filename.c_str());
    if(!infile.is_open()) {
       cout << "No such pid: " << pid << endl;
       return Err_NoPid;
    }
    infile >> name;
    infile.close();
    return Err_OK;
}

ErrStatus GetPidByName(string name, int &pid)
{
    vector<int> pidList;
    ErrStatus err = GetAllPids(pidList);
    if(err!=0) {
        cout << "Cannot get list of pids" << endl;
        return err;
    }
    bool pidFound = false;
    string tmpName;
    for(int i=0; i<pidList.size() && !pidFound; ++i) {
        string filename = "/proc/" + to_string(pidList.at(i)) + "/comm";
        ifstream infile(filename.c_str());
        if(infile.is_open()) {
            infile >> tmpName;
            if(tmpName==name) {
                pidFound = true;
                pid = pidList.at(i);
            }
            infile.close();
        }
    }
    if(pidFound==true) return Err_OK;
    cout << "Unable to find the pid for " << name << endl;
    return Err_NoName;
}

string GetErrorMsg(ErrStatus index)
{
    return errMsg[index];
}
