// Test Main
// testmain.cpp

#include<iostream>

using namespace std;
#include "Calculator2.h"

int main() {
    int passed = 0;
    Calculator2 calc;
    passed += calc.testSuite(5, 3, 125);
    passed += calc.testSuite(5, -3, 0.008);
    cout << passed << " Tests Passed" << endl;
}