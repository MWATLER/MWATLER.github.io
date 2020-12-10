/*
 * Author: Daniel Pliszka
 * Contact: dpliszka@myseneca.ca
 * Title: DPS912 Lab 02
 * Date: July 13, 2019
 *
 */

#include <linux/fb.h>
#include <fcntl.h> // open()
#include <string.h>
#include <sys/ioctl.h> // ioctl()
#include <unistd.h> // sleep(), close()
#include <iostream>

using namespace std;

int main()
{
    int fd, choice, ret;
    struct fb_fix_screeninfo fscreen; // For fixed screen info
    struct fb_var_screeninfo vscreen; // For variable screen info

    system("clear");
    cout << "Opening /dev/fb0" << endl;
    fd = open("/dev/fb0", O_RDONLY | O_NONBLOCK);
    if(fd < 0) {
       cout << "Cannot open device file..." << endl;
       return -1;
    }

    // Menu
    do {
        cout << "Make a selection:" << endl;
        cout << "1. Get Fixed Screen Info" << endl;
        cout << "2. Get Variable Screen Info" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Retrieving fixed screen parameters" << endl;
                ret = ioctl(fd, FBIOGET_FSCREENINFO, &fscreen);
                if(ret<0) {
                    cout << strerror(errno) << endl;
                } else {
                    cout << "Screen Visual(s): " << fscreen.visual << endl; // ANS: 2
                    cout << "Screen Accelerator: " << fscreen.accel << endl; // ANS: 0
                    cout << "Screen Capabilities: " << fscreen.capabilities << endl; // ANS: 0
                }
                sleep(5);
	        break;
	    case 2:
                cout << "Retrieving variable screen parameters" << endl;
                ret = ioctl(fd, FBIOGET_VSCREENINFO, &vscreen);
                if(ret<0) {
                    cout << strerror(errno) << endl;
                } else {
                    cout << "X Resolution: " << vscreen.xres << endl; // ANS: 1920
                    cout << "Y Resolution: " << vscreen.yres << endl; // ANS: 1080
                    cout << "Bits Per Pixel: " << vscreen.bits_per_pixel << endl; // 32
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

    cout << "GoodBye!" << endl;
    close(fd);

    return 0;
}
