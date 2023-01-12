//DataCenterRogue2Main.cpp - Main function for the rogue2 Data Center
//
// History:
// 05-May-22  M. Watler         Created.

#include "DataCenterRogue2.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc!=2) {
        cout<<"usage: dataRogue2 <dataCenterNo>"<<endl;
        return -1;
    }
    DataCenterRogue2 dataCenter(atoi(argv[1]));
    return dataCenter.run();
}
