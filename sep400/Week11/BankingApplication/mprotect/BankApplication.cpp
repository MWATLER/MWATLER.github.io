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

    const char BankDatabase[]="BankDatabase.txt";
    int fd=open(BankDatabase, O_RDWR);
    struct stat sb;
    BankApplication *addr;
    if(fd== -1) {
	cout<<"ERROR: Cannot open "<<BankDatabase<<endl;
	cout<<strerror(errno)<<endl;
        retVal = -1;
    }
    if(retVal==0) {
        if(fstat(fd, &sb)== -1) {
	    cout<<"ERROR: Cannot fstat "<<BankDatabase<<endl;
	    cout<<strerror(errno)<<endl;
            retVal = -2;
            close(fd);
        }
    }
    if(retVal==0) {
        addr = (BankApplication *)mmap(NULL, sb.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(addr == MAP_FAILED) {
	    cout<<"ERROR: mmap failed"<<endl;
	    cout<<strerror(errno)<<endl;
            retVal = -3;
        }
        close(fd);//We can close the file descriptor if mmap is successful.
                  //If mmap is unsuccessful, we want to close the file descriptor anyway.
    }

    if(retVal==0) {
        bool hasAccess=true;
        do {
            system("clear");
	    if(hasAccess) cout<<addr->accountNumber<<" "<<addr->transitNumber<<" balance $"<<addr->balance<<endl<<endl;
            cout<<"Make a selection:"<<endl;
            cout<<"1.Change Account Number."<<endl;
            cout<<"2.Change Transit Number."<<endl;
            cout<<"3.Withdraw."<<endl;
            cout<<"4.Deposit."<<endl;
            cout<<"5.Refresh."<<endl;
            cout<<"6.Toggle Access."<<endl;
            cout<<"0.Quit."<<endl;
	    cout<<endl;
	    cout<<"Selection: ";
	    cin>>selection;

            switch(selection) {
            case 1:
                cout<<"Enter the new account number: ";
		cin>>addr->accountNumber;
		msync(addr, sb.st_size, MS_SYNC);
            break;
            case 2:
                cout<<"Enter the new transit number: ";
		cin>>addr->transitNumber;
		msync(addr, sb.st_size, MS_SYNC);
            break;
            case 3:
	        cout<<"Enter the withdrawal amount: $";
		cin>>amount;
		addr->balance -= amount;
		msync(addr, sb.st_size, MS_SYNC);
            break;
            case 4:
	        cout<<"Enter the deposit amount: $";
		cin>>amount;
		addr->balance += amount;
		msync(addr, sb.st_size, MS_SYNC);
            break;
            case 5://Refresh
            break;
            case 6://toggle access
	        if(hasAccess) {
                    mprotect(addr,sb.st_size, PROT_NONE);
                    hasAccess=false;
                } else {
                    mprotect(addr,sb.st_size, PROT_READ|PROT_WRITE);
                    hasAccess=true;
                }
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
        munmap(addr, sb.st_size);
	close(fd);
    }

    return retVal;
}
