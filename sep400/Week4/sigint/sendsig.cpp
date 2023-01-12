//sendsig.cpp - Process for sending a signal
//
// 08-Feb-19  M. Watler         Created.

#include <errno.h>
#include <signal.h>
#include <iostream>

using namespace std;

int main ( ) {
    int process_id;
    cout<<"Enter process_id which you want to send a signal : ";
    cin>>process_id;

   if (!(kill ( process_id, SIGINT)))
       cout<<"SIGINT sent to "<<process_id<<endl;
   else if (errno == EPERM)
       cout<<"Operation not permitted."<<endl;
   else
       cout<<process_id<<" doesn't exist"<<endl;
}
