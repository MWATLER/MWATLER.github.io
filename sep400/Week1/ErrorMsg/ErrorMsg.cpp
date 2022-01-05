//ErrorMsg.cpp - Test the Error Message Facility
//
// For a list of Linux system functions see:
// http://man7.org/linux/man-pages/dir_all_alphabetic.html
//
// 15-Jan-19  M. Watler         Created.

#include <iostream>
#include <grp.h>
#include <pwd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main()
{
    char filename[]="/home/miguelwatler/sep400/Week1/ErrorMsg/Math.cpp";
//  char filename[]="~/home/miguelwatler/sep400/Week1/ErrorMsg/Math.cpp";//This will provoke an error
    int rc=0;
    int err = chmod(filename, S_IRWXU|S_IRWXG|S_IROTH);
    system("clear");
    cout << "Attempting to access the file "<<filename<<endl<<endl;
    cout << "err from chmod is " << err << endl;
    cout << "errno is " << errno << endl;
    if(err==-1) {
        cout<<"Error message from perror: ";
        perror("chmod");
        cout << "Error message from strerror: " << strerror(errno) << endl;
        rc = -1;
    }

    return rc;
}
