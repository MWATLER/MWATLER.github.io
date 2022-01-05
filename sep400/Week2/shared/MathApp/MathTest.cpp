//MathTest.cpp - main file to test the math library
//
// 15-Jan-19  M. Watler         Created.

#include <iostream>
#include <unistd.h>
#include "Math.h"

using namespace std;

int main(void)
{
    double num, result;
    int intNum, exp;

    system("clear");
    //Run the tests
    intNum = 5;
    result = factorial(intNum);
    cout << "     The factorial of " << intNum << " is " << result << endl;
    num = 3.0;
    exp = 4;
    result = power(num, exp);
    cout << "    " << num << " to the power " << exp << " is " << result << endl;
    num = -4.15;
    result = absolute(num);
    cout << "     The absolute value of " << num << " is " << result << endl;
    num = 12.0;

    result = Circumference(num);
    cout << "     The circumference of a circle with radius " << num << " is " << result << endl;
    result = Area(num);
    cout << "     The area of a circle with radius " << num << " is " << result << endl;
    result = Volume(num);
    cout << "     The volume of a sphere with radius " << num << " is " << result << endl;

    num = 34;
    result = CelsiusToFahrenheit(num);
    cout << "     " << num << " in degrees fahrenheit is " << result << endl;
    num = 50;
    result = FahrenheitToCelsius(num);
    cout << "     " << num << " in degrees celsius is " << result << endl;
    num = 62;
    result = InchesToCentimeters(num);
    cout << "     " << num << " in centimeters is " << result << endl;
    num = 188;
    result = CentimetersToInches(num);
    cout << "     " << num << " in inches is " << result << endl;
    num = 102.0;
    result = KilogramsToPounds(num);
    cout << "     " << num << " in pounds is " << result << endl;
    num = 220;
    result = PoundsToKilograms(num);
    cout << "     " << num << " in kilograms is " << result << endl;
}
