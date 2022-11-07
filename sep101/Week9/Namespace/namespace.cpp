// A Language for Complex Applications
// welcome.cpp
//
// To compile on linux:  g++ welcome.cpp
// To run compiled code: a.out
//
// To compile on windows:   cl welcome.cpp
//  To run compiled code: welcome
//
#include <iostream>//string, cout, endl

using namespace std;//iostream is inside the std namespace

namespace english {
    string message = "Welcome";
}

namespace french {
	string message = "Bonjour";
}

//using namespace french;

int main() {
    cout << "Welcome to Object-Oriented Programming" << endl;
    cout << "This is the english message: " << english::message << endl;
    cout << "C'est la information francais: " << french::message << endl;//what will be printed here? Welcome or Bonjour?
//  cout << message << endl;
    return 0;
}