//recvsig.cpp - Process for receiving a signal
//              This program will run until it receives SIGINT
//
// 08-Feb-19  M. Watler         Created.

#include <errno.h>
#include <signal.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main ( ) {
   cout<<"This process id is "<<getpid()<<". Waiting for SIGINT."<<endl;
   for (int i=0;i<300;++i) {
       cout<<"recvsig: "<<i<<" seconds"<<endl;
       sleep(1);
   }
   cout<<"DONE!"<<endl;
   return 0;
}
