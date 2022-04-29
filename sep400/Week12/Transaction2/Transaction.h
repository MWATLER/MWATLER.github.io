//Transaction.h - header file for a transaction application
//
// History:
// 06-Mar-22  M. Watler         Created.

void *display_func(void *arg);
static void sigHandler(int sig);

struct Transaction {
    int accountNumber;
    int transitNumber;
    double balance;
};
