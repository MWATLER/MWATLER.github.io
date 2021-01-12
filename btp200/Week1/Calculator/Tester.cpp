// Tester.cpp

#include<iostream>
using namespace std;
#include "Calculator.h"

int testSuite(int BASE, int EXPONENT, int RESULT) {
    int passed = 0;
    int result;
    result = power(BASE, EXPONENT);
    if (result == RESULT) {
        cout << "Raise to Power Test Passed" << endl;
        passed++;
    }
    else {
        cout << "Raise to Power Test Failed" << endl;
    }
    result = exponent(RESULT, BASE);
    if (result == EXPONENT) {
        cout << "Find Exponent Test Passed" << endl;
        passed++;
    }
    else {
        cout << "Find Exponent Test Failed" << endl;
    }
    return passed;
}