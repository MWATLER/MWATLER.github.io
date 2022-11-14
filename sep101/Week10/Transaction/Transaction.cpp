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
    //   double value = (a==b) ? 100.0 : 10.0;//(comparison) ? true_case : false_case;
    cout << ((type == 'd') ? " Debit $" : " Credit $") << amount;
    cout << endl;
}

//double balance=0.0;
//tr.add(balance);
void Transaction::add(double& bal) {//bal is actually a reference to balance,
    if (type == 'd') bal -= amount; //so whatever we do to bal we do to balance.
    else             bal += amount;
}