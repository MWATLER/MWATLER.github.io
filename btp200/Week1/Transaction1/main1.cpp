// Modular Example
// main1.cpp

#include "main1.h"
#include "Transaction1.h"

int main() {
    int i;
    struct Transaction tr;

    for (i = 0; i < NO_TRANSACTIONS; i++) {
        enter(&tr);
        display(&tr);
    }
}