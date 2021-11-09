// A Language for Complex Applications
// welcome.cpp
//
// To compile on linux:  g++ welcome.cpp
// To run compiled code: a.out
//
// To compile on windows:   cl welcome.cpp
//  To run compiled code: welcome
//
#include <iostream>

using namespace std;

namespace english {
    string message = "Welcome";
}

namespace french {
    string message = "Bonjour";
}

using namespace english;

int main() {
    cout << "Welcome to Object-Oriented Programming" << endl;
//  cout << english::message << endl;
//  cout << french::message << endl;
    cout << message << endl;
    return 0;
}