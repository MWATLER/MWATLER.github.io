// Modular Example
// Transaction2.cpp

#include <iostream> // for cout, cin
#include "Transaction2.h"  // for Transaction
using namespace std;

// prompts for and accepts Transaction data
//
void Transaction2::enter(void) {

    cout << "Enter the account number : ";
    cin >> acct;
    cout << "Enter the account type (d debit, c credit) : ";
    cin >> type;
    cout << "Enter the account amount : ";
    cin >> amount;
}

// displays Transaction data
//
void Transaction2::display(void) {

    cout << "Account " << acct;
    cout << ((type == 'd') ? " Debit $" : " Credit $") << amount;
    cout << endl;
}

void Transaction2::add(double& bal) {
    if (type == 'd') bal -= amount;
    else             bal += amount;
}