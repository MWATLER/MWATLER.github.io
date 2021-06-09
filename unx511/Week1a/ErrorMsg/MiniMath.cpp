//MiniMath.cpp - Demo of error messages
//
// 15-Jan-19  M. Watler         Created.

#include <iostream>

using namespace std;

enum ErrMaths {
    Err_OK,
    Err_DivideByZero,
    Err_WrongType,
    Err_OutOfRange
};

char ErrMsg[][15] = {
    "OK",
    "Divide by Zero",
    "Wrong Type",
    "Out of Range"
};

int main()
{
    double numerator, denominator;
    system("clear");
    cout << "Let's do division, enter the numerator: ";
    cin >> numerator;
    cout << "                   enter the denominator: ";
    cin >> denominator;
    if(denominator==0) {
        cout << ErrMsg[Err_DivideByZero] << endl << endl;
    } else {
        cout << "The result is " << numerator/denominator << endl << endl;
    }

    int age;
    cout << "Enter your age: ";
    cin >> age;
#ifdef _EXTENDED_MATH
    if(age<0) {
        cout << ErrMsg[Err_OutOfRange] << endl << endl;
    } else {
        cout << "Your age in months is " << age*12 << endl << endl;
    }
#else
    cout << "Sorry this feature is not available on this version of software" << endl << endl;
#endif
    return 0;
}
