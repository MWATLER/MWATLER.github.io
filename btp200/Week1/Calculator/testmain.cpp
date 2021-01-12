// Test Main
// testmain.cpp

#include<iostream>
using namespace std;
#include "Tester.h"

int main() {
    int passed = 0;
    passed += testSuite(5, 3, 125);
    passed += testSuite(5, -3, 0.008);
    cout << passed << " Tests Passed" << endl;
}