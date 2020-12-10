#include <fcntl.h> 
#include <string.h>
#include <sys/ioctl.h> 
#include <linux/fb.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <iostream>

char screenFile[] = "/dev/fb0";

using namespace std;

int main()
{
    int fd;
    int choice;
    int ret;
    int lock;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;

    system("clear");
    cout << "Opening Driver" << endl;
    fd = open(screenFile, O_RDONLY | O_NONBLOCK);
    if(fd < 0) {
       cout << "Cannot open device file..." << endl;
       return 0;
    }

    do {
        cout << "Make a selection:" << endl;
        cout << "1. Fixed Screen Info " << endl;
        cout << "2. Variable Screen Info" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Getting Fixed Screen Info" << endl;
                ret = ioctl(fd, FBIOGET_FSCREENINFO, &finfo); 
                if(ret<0) {
                    cout << strerror(errno) << endl;
                } else {
                    //See FB_VISUAL,               see FB_ACCEL_,            see FB_CAP.
                    cout<<"visual:"<<finfo.visual<<" accel:"<<finfo.accel<<" capabilities:"<<finfo.capabilities<<endl;
	            sleep(4);
		}
	        break;
	    case 2:
                cout << "Getting Variable Screen Info" << endl;
                ret = ioctl(fd, FBIOGET_VSCREENINFO, &vinfo); 
                if(ret<0) {
                    cout << strerror(errno) << endl;
                } else {
                    cout<<"xres:"<<vinfo.xres<<" yres:"<<vinfo.yres<<" bits/pixel:"<<vinfo.bits_per_pixel<<endl;
	            sleep(4);
		}
	        break;
            default:
                system("clear");
        }
	sleep(1);
	system("clear");
    } while (choice!=0);

    cout << "Closing Driver" << endl;
    close(fd);
}
