//car.cpp
//
// 30-Jan-19  M. Watler         Created.
//

#include <fcntl.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sys/uio.h>
#include <unistd.h>

using namespace std;

#define BUF_LEN 8

typedef struct car {
    char make[BUF_LEN];
    char model[BUF_LEN];
    char year[BUF_LEN];
    char cost[BUF_LEN];
} CAR;


int main(void)
{
    int fd;
    int len;
    CAR car1, car2;
    const char file[]="car.txt";
    struct iovec iov[2];

    fd = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(fd<0) {
	cout << strerror(errno);
	return -1;
    }
    memset(&car1, 0, sizeof(CAR));
    memset(&car2, 0, sizeof(CAR));
    strcpy(car1.make, "Toyota");
    strcpy(car1.model, "Corolla");
    strcpy(car1.year, "2013");
    strcpy(car1.cost, "9000");
    strcpy(car2.make, "Mazda");
    strcpy(car2.model, "Sport-3");
    strcpy(car2.year, "2007");
    strcpy(car2.cost, "7000");

    len=0;
    iov[0].iov_base = &car1;
    iov[0].iov_len = sizeof(CAR);
    len += iov[0].iov_len;
    cout << "len: " << len << endl;
    iov[1].iov_base = &car2;
    iov[1].iov_len = sizeof(CAR);
    len += iov[1].iov_len;

    int numWrite = writev(fd, iov, 2);
    if(numWrite<0) {
        cout << strerror(errno) << endl;
    } else if (numWrite != len) {
        cout << "Wrote fewer bytes than requested" << endl;
    }

    close(fd);
    return 0;
}
