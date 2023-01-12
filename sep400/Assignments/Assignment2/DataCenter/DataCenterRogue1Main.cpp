//DataCenterRogue1Main.cpp - Main function for the rogue1 Data Center
//
// History:
// 05-May-22  M. Watler         Created.

#include "DataCenterRogue1.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc!=2) {
        cout<<"usage: dataRogue1 <dataCenterNo>"<<endl;
        return -1;
    }
    DataCenterRogue1 dataCenter(atoi(argv[1]));
    return dataCenter.run();
}
