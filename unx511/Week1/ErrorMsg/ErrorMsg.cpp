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
    char filename[]="/home/miguelwatler/src/Week1/Math.cpp";
//  char filename[]="~/home/miguelwatler/src/Week1/Math.cpp";//This will provoke an error
    int rc=0;
    int err = chmod(filename, S_IRWXU|S_IRWXG|S_IROTH);
    system("clear");
    cout << "err is " << err << endl;
    cout << "errno is " << errno << endl;
    if(err==-1) {
        perror("chmod");
        cout << "strerror: " << strerror(errno) << endl;
    }

    uid_t          uid;
    gid_t          gid;
    struct passwd *pwd;
    struct group  *grp;

    pwd = getpwnam("miguelwatler");
//  pwd = getpwnam("root");//This will provoke an error
    if (pwd == NULL) {
        cout << "Cannot get password structure" << endl;
	rc = -1;
    }
    if(rc==0) {
        uid = pwd->pw_uid;

        grp = getgrnam("miguelwatler");
//      grp = getgrnam("root");//This will provoke an error
        if (grp == NULL) {
            cout << "Cannot get group name structure" << endl;
	    rc = -1;
        }
    }
    if(rc==0) {
        gid = grp->gr_gid;

        err = chown(filename, uid, gid);
        cout << "err is " << err << endl;
        cout << "errno is " << errno << endl;
        if(err==-1) {
            perror("chown");
            cout << "strerror: " << strerror(errno) << endl;
	    rc = -1;
        }
    }
    return rc;
}
