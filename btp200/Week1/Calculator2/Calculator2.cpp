// Calculator2.cpp
#include <iostream>
#include "Calculator2.h"

using namespace std;

void Calculator2::power(void) {
    int i;
    result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    //There's actually no need to return result. result is visible within the class
}

void Calculator2::exponent(void) {
    exp = 0;
    while (result >= base) {
        exp++;
        result /= base;
    }
    //There's actually no need to return exp. exp is visible within the class
}

int Calculator2::testSuite(int BASE, int EXPONENT, int RESULT) {
    base = BASE;
    exp = EXPONENT;
    result = RESULT;

    int passed = 0;
    power();
    if (result == RESULT) {
        cout << "Raise to Power Test Passed" << endl;
        passed++;
    }
    else {
        cout << "Raise to Power Test Failed" << endl;
    }
    result = RESULT;
    exponent();
    if (exp == EXPONENT) {
        cout << "Find Exponent Test Passed" << endl;
        passed++;
    }
    else {
        cout << "Find Exponent Test Failed" << endl;
    }
    return passed;
}