#include <errno.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <net/if_arp.h>
#include <arpa/inet.h>
#include <unistd.h>

#define NAME_SIZE 16

using namespace std;

int main()
{
    int fd;
    int ret;
    int selection;
    struct ifreq ifr;
    char if_name[NAME_SIZE];
    unsigned char *mac=NULL;
    struct sockaddr_in *addr=NULL;

    cout << "Enter the interface name: ";
    cin >> if_name;

    size_t if_name_len=strlen(if_name);
    if (if_name_len<sizeof(ifr.ifr_name)) {
        memcpy(ifr.ifr_name, if_name, if_name_len);
        ifr.ifr_name[if_name_len]=0;//NULL terminate
    } else {
        cout << "Interface name is too long!" << endl;
	return -1;
    }

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd<0) {
        cout << strerror(errno);
	return -1;
    }

    system("clear");
    do {
        cout << "Choose from the following:" << endl;
	cout << "1. Hardware address" << endl;
	cout << "2. IP address" << endl;
	cout << "3. Network mask" << endl;
	cout << "4. Broadcast address" << endl;
	cout << "0. Exit" << endl << endl;
	cin >> selection;
	switch(selection) {
        case 1:
            ret = ioctl(fd, SIOCGIFHWADDR, &ifr);
            if(ret<0) {
                cout << strerror(errno);
            } else if(ifr.ifr_hwaddr.sa_family!=ARPHRD_ETHER) {
                cout << "not an Ethernet interface" << endl;
            } else {
                mac=(unsigned char*)ifr.ifr_hwaddr.sa_data;
                printf("MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n", mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
	    }
            break;
        case 2:
            ret = ioctl(fd, SIOCGIFADDR, &ifr);
            if(ret<0) {
                cout << strerror(errno);
            } else {
                addr = (struct sockaddr_in*)&ifr.ifr_addr;
                cout << "IP Address: " << inet_ntoa(addr->sin_addr) << endl;
	    }
            break;
        case 3:
            ret = ioctl(fd, SIOCGIFNETMASK, &ifr);
            if(ret<0) {
                cout << strerror(errno);
            } else {
                addr = (struct sockaddr_in*)&ifr.ifr_netmask;
                cout << "IP Address: " << inet_ntoa(addr->sin_addr) << endl;
	    }
            break;
        case 4:
            ret = ioctl(fd, SIOCGIFBRDADDR, &ifr);
            if(ret<0) {
                cout << strerror(errno);
            } else {
                addr = (struct sockaddr_in*)&ifr.ifr_broadaddr;
                cout << "IP Address: " << inet_ntoa(addr->sin_addr) << endl;
	    }
            break;
        }
	if(selection!=0) {
            char key;
            cout << "Press any key to continue: ";
            cin >> key;
            system("clear");
        }
    } while (selection!=0);


    close(fd); 
    return 0;
}
