#include <fcntl.h> 
#include <linux/hdreg.h>//for HDIO_GETGEO
#include <linux/fs.h>//for BLKGETSIZE 
#include <string.h>
#include <sys/ioctl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <iostream>

char diskFile[] = "/dev/sda";
char disk1File[] = "/dev/sda1";

using namespace std;

int main()
{
    int fd, fd1;
    int choice;
    int ret;
    struct hd_geometry hdGeo;
    long int blockSize;

    system("clear");
    cout << "Opening Drivers" << endl;
    fd = open(diskFile, O_RDONLY | O_NONBLOCK);
    if(fd < 0) {
       cout << "Cannot open device file..." << endl;
       return -1;
    }
    fd1 = open(disk1File, O_RDONLY | O_NONBLOCK);
    if(fd1 < 0) {
       cout << "Cannot open device file..." << endl;
       return -1;
    }

    do {
        cout << "Make a selection:" << endl;
        cout << "1. Get the BIOS disk parameters" << endl;
        cout << "2. Get the device size in sectors" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Retrieving the disk parameters" << endl;
		//See https://www.kernel.org/doc/Documentation/ioctl/hdio.txt
		memset(&hdGeo, 0, sizeof(hdGeo));
                ret = ioctl(fd, HDIO_GETGEO, &hdGeo);
//              retVal = ioctl(file_descriptor, command, &parameter_or_structure);
                if(ret<0) {
                    cout << strerror(errno) << endl;
                } else {
                    cout << "For " << diskFile << endl;
                    cout << "There are " << (int)hdGeo.heads << " heads" << endl;
                    cout << "There are " << (int)hdGeo.sectors << " sectors" << endl;
                    cout << "There are " << hdGeo.cylinders << " cylinders" << endl;
                    cout << "Start is " << hdGeo.start << endl;
                }
		memset(&hdGeo, 0, sizeof(hdGeo));
                ret = ioctl(fd1, HDIO_GETGEO, &hdGeo);
                if(ret<0) {
                    cout << strerror(errno) << endl;
                } else {
                    cout << "For " << disk1File << endl;
                    cout << "There are " << (int)hdGeo.heads << " heads" << endl;
                    cout << "There are " << (int)hdGeo.sectors << " sectors" << endl;
                    cout << "There are " << hdGeo.cylinders << " cylinders" << endl;
                    cout << "Start is " << hdGeo.start << endl;
                }
                sleep(5);
	        break;
	    case 2:
                cout << "Retrieving the device size" << endl;
                ret = ioctl(fd, BLKGETSIZE, &blockSize);
                if(ret<0) {
                    cout << strerror(errno) << endl;
                } else {
                    cout << "For " << diskFile << ", the device size is " << blockSize << " sectors" << endl;
                }
                ret = ioctl(fd1, BLKGETSIZE, &blockSize);
                if(ret<0) {
                    cout << strerror(errno) << endl;
                } else {
                    cout << "For " << disk1File << ", the device size is " << blockSize << " sectors" << endl;
                }
                sleep(2);
	        break;
	    case 0:
		cout << "Ending program..." << endl;
	        break;
            default:
                system("clear");
        }
	system("clear");
    } while (choice!=0);

    cout << "Closing Drivers" << endl;
    close(fd);
    close(fd1);
    return 0;
}
