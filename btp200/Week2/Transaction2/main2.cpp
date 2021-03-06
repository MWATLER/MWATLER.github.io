// Modular Example
// main2.cpp

#include <iostream>
#include "main2.h"
#include "Transaction2.h"

int main() {
    int i;
    Transaction2 tr;
    double balance = 0;

    for (i = 0; i < NO_TRANSACTIONS; i++) {
        tr.enter();
        tr.display();
        tr.add(balance);//appears to be pass by value,
		                //but is in fact pass by address.
        std::cout << "balance is now " << balance << std::endl;
    }
}