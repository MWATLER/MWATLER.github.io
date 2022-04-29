//BankApplication.cpp - A banking application with the mapping application
//
// History:
// 04-Mar-22  M. Watler         Created.

#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include "BankApplication.h"

using namespace std;

int main() {
    int retVal = 0;
    int selection;
    double amount;

    const char BankFile[]="/dev/zero";
    int fd=open(BankFile, O_RDWR);
    BankApplication *addr;
    int size = sizeof(BankApplication);
    if(fd== -1) {
	cout<<"ERROR: Cannot open "<<BankFile<<endl;
	cout<<strerror(errno)<<endl;
        retVal = -1;
    }
    if(retVal==0) {
        addr = (BankApplication *)mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, fd, 0);
	if(addr == MAP_FAILED) {
	    cout<<"ERROR: mmap failed"<<endl;
	    cout<<strerror(errno)<<endl;
            retVal = -3;
        }
        close(fd);//We can close the file descriptor if mmap is successful.
                  //If mmap is unsuccessful, we want to close the file descriptor anyway.
    }

    if(retVal==0) {
        do {
            system("clear");
	    cout<<addr->accountNumber<<" "<<addr->transitNumber<<" balance $"<<addr->balance<<endl<<endl;
            cout<<"Make a selection:"<<endl;
            cout<<"1.Change Account Number."<<endl;
            cout<<"2.Change Transit Number."<<endl;
            cout<<"3.Withdraw."<<endl;
            cout<<"4.Deposit."<<endl;
            cout<<"5.Refresh."<<endl;
            cout<<"0.Quit."<<endl;
	    cout<<endl;
	    cout<<"Selection: ";
	    cin>>selection;

            switch(selection) {
            case 1:
                cout<<"Enter the new account number: ";
		cin>>addr->accountNumber;
		msync(addr, size, MS_SYNC);
            break;
            case 2:
                cout<<"Enter the new transit number: ";
		cin>>addr->transitNumber;
		msync(addr, size, MS_SYNC);
            break;
            case 3:
	        cout<<"Enter the withdrawal amount: $";
		cin>>amount;
		addr->balance -= amount;
		msync(addr, size, MS_SYNC);
            break;
            case 4:
	        cout<<"Enter the deposit amount: $";
		cin>>amount;
		addr->balance += amount;
		msync(addr, size, MS_SYNC);
            break;
            case 5://Refresh
            break;
            case 0:
                cout<<"Goodbye!"<<endl;
            break;
            default:
                cout<<"Invalid Selection!"<<endl;
                sleep(3);
            }

        } while (selection!=0);
    }
    if(retVal==0) {
        munmap(addr, size);
    }

    return retVal;
}
