//fileDup.cpp - Changing the standard error channel
//
// 31-Jan-19  M. Watler         Created.
//

#include <fcntl.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main(void)
{
    int fd1, fdErr;
    const char file[]="Error.log";

    fd1 = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(fd1<0) {
	return -1;
    }
    //int dup(int oldfd);
    //Returns (new) file descriptor on success, or –1 on error
    fdErr = dup(STDERR_FILENO);
    cout << "fd1: " << fd1 << " fdErr: " << fdErr << " STDERR_FILENO: " << STDERR_FILENO << endl;
    if(fdErr<0) {
        close(fd1);
	return -1;
    }

    cout << "1. This is the standard output channel" << endl;
    cerr << "1. This is the standard error channel" << endl;
    //int dup2(int oldfd, int newfd)
    //Returns (new) file descriptor on success, or –1 on error
    //STDERR_FILENO becomes fd1
    dup2(fd1, STDERR_FILENO);
    cout << "2. This is the standard output channel" << endl;
    cerr << "2. This is the standard error channel" << endl;
    //STDERR_FILENO becomes fdErr
    dup2(fdErr, STDERR_FILENO);
    cout << "3. This is the standard output channel" << endl;
    cerr << "3. This is the standard error channel" << endl;
    close(fd1);
    close(fdErr);
    return 0;
}
