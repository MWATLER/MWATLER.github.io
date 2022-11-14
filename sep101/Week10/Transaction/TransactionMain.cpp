// TransactionMain.cpp

#include <iostream>
#include "Transaction.h"

int main() {
    const int NO_TRANSACTIONS = 3;
    Transaction tr;
    double balance = 0.0;

    tr.enterAccount();
    for (int i = 0; i < NO_TRANSACTIONS; i++) {
        tr.enterTransaction();
        tr.display();
        tr.add(balance);//appears to be pass by value,
                        //but is in fact pass by address.
        std::cout << "balance is now " << balance << std::endl;
    }
}