//WorkPackage.cpp - A work package application with mapping
//
// History:
// 02-May-22  M. Watler         Created.

#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include "WorkPackage.h"

using namespace std;

int main() {
    int retVal = 0;
    int selection;
    double amount;

    const char WorkData[]="WorkData.txt";
    int fd=open(WorkData, O_CREAT | O_RDWR, 0644);
    struct stat sb;
    WorkPackage *addr;
    if(fd== -1) {
	cout<<"ERROR: Cannot open "<<WorkData<<endl;
	cout<<strerror(errno)<<endl;
        retVal = -1;
    }
    if(retVal==0) {
        if(fstat(fd, &sb)== -1) {
	    cout<<"ERROR: Cannot fstat "<<WorkData<<endl;
	    cout<<strerror(errno)<<endl;
            retVal = -2;
            close(fd);
        }
    }
    if(retVal==0) {
        addr = (WorkPackage *)mmap(NULL, sb.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
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
	    cout<<"WORK PACKAGE"<<endl<<endl;
	    cout<<"Entries: "<<addr->entries<<endl;
	    cout<<"Hours: "<<addr->hours<<endl;
	    cout<<"Balance: $"<<addr->balance<<endl<<endl;
            cout<<"Make a selection:"<<endl;
            cout<<"1.Log hours."<<endl;
            cout<<"2.Add Expense."<<endl;
            cout<<"3.Add Deposit."<<endl;
            cout<<"4.Refresh."<<endl;
            cout<<"5.Clear Data."<<endl;
            cout<<"0.Quit."<<endl;
	    cout<<endl;
	    cout<<"Selection: ";
	    cin>>selection;

            int hours;
	    double amount;
            switch(selection) {
            case 1:
                cout<<"Enter the hours: ";
		cin>>hours;
		++addr->entries;
		addr->hours += hours;
		msync(addr, sb.st_size, MS_SYNC);
            break;
            case 2:
                cout<<"Enter the expense: $";
                cin>>amount;
		addr->balance -= amount;
		msync(addr, sb.st_size, MS_SYNC);
            break;
            case 3:
                cout<<"Enter the deposit: $";
                cin>>amount;
		addr->balance += amount;
		msync(addr, sb.st_size, MS_SYNC);
            break;
            case 4://Refresh
            break;
            case 5://Reset all entries to zero
                addr->entries=0;
                addr->hours=0.0;
                addr->balance=0.0;
		msync(addr, sb.st_size, MS_SYNC);
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
    }

    return retVal;
}
