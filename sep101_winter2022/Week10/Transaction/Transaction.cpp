// Modular Example
// Transaction.cpp

#include <iostream> // for cout, cin
#include "Transaction.h"  // for Transaction
using namespace std;

// prompts for and accepts Transaction data
//
void Transaction::enterAccount(void) {

    cout << "Enter the account number : ";
    cin >> acct;
}

void Transaction::enterTransaction(void) {

    cout << "Enter the transaction type (d debit, c credit) : ";
    cin >> type;
    cout << "Enter the account amount : ";
    cin >> amount;
}

// displays Transaction data
//
void Transaction::display(void) {

    cout << "Account " << acct;
    cout << ((type == 'd') ? " Debit $" : " Credit $") << amount;
    cout << endl;
}

void Transaction::add(double& bal) {
    if (type == 'd') bal -= amount;
    else             bal += amount;
}