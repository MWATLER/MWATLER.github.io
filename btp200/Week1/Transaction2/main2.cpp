// Modular Example
// main2.cpp

#include "main2.h"
#include "Transaction2.h"

int main() {
    int i;
    Transaction2 tr;

    for (i = 0; i < NO_TRANSACTIONS; i++) {
        tr.enter();
        tr.display();
    }
}