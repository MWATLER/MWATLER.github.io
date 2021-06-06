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
        memcpy(ifr.ifr_name,if_name,if_name_len);
        ifr.ifr_name[if_name_len]=0;
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
	cout << "2. Maximum Transfer Unit (MTU)" << endl;
	cout << "3. Interface Flags" << endl;
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
            ret = ioctl(fd, SIOCGIFMTU, &ifr);
            if(ret<0) {
                cout << strerror(errno);
            } else {
                cout << "MTU: " << to_string(ifr.ifr_mtu) << endl;
	    }
            break;
        case 3:
            ret = ioctl(fd, SIOCGIFFLAGS, &ifr);
            if(ret<0) {
                cout << strerror(errno);
            } else {
                short flags = ifr.ifr_flags;
		if(flags & IFF_UP) cout << "Interface is running" << endl;
                if(flags & IFF_BROADCAST) cout << "Valid broadcast address set." << endl;
                if(flags & IFF_DEBUG) cout << "Internal debugging flag." << endl;
                if(flags & IFF_LOOPBACK) cout << "Interface is a loopback interface." << endl;
                if(flags & IFF_POINTOPOINT) cout << "Interface is a point-to-point link." << endl;
                if(flags & IFF_RUNNING) cout << "Resources allocated." << endl;
                if(flags & IFF_NOARP) cout << "No arp protocol, L2 destination address not set." << endl;
                if(flags & IFF_PROMISC) cout << "Interface is in promiscuous mode." << endl;
                if(flags & IFF_NOTRAILERS) cout << "Avoid use of trailers." << endl;
                if(flags & IFF_ALLMULTI) cout << "Receive all multicast packets." << endl;
                if(flags & IFF_MASTER) cout << "Master of a load balancing bundle." << endl;
                if(flags & IFF_SLAVE) cout << "Slave of a load balancing bundle." << endl;
                if(flags & IFF_MULTICAST) cout << "Supports multicast" << endl;
                if(flags & IFF_PORTSEL) cout << "Is able to select media type via ifmap." << endl;
                if(flags & IFF_AUTOMEDIA) cout << "Auto media selection active." << endl;
                if(flags & IFF_DYNAMIC) cout << "The addresses are lost when the interface goes down." << endl;
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
