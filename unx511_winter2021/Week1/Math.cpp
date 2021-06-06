//Math.cpp - main file for the math library
//
// 14-Jan-19  M. Watler         Created.

#include <iostream>
#include <unistd.h>
#include "Math.h"

using namespace std;

int main(void)
{
    int selection=1;

    while(selection!=0) {
        system("clear");
        cout << " 1. General" << endl;
        cout << " 2. Geometry" << endl;
        cout << " 3. Unit Conversions" << endl;
        cout << " 0. Exit" << endl;
        cin >> selection;
        if(selection>=1 && selection<=3) {
            cout << endl;
            int sel;
            double num, result;
            switch(selection) {
                case 1:
                    cout << "   1. Factorial" << endl;
                    cout << "   2. Power" << endl;
                    cout << "   3. Absolute" << endl;
                    cin >> sel;
                    switch (sel) {
                        case 1:
                            cout << "     Enter a number: ";
                            cin >> num;
                            result = factorial(num);
                            cout << "     The factorial of " << num << " is " << result << endl;
                        break;
                        case 2:
                            int exp;
                            cout << "     Enter a number: ";
                            cin >> num;
                            cout << "     Enter a power: ";
                            cin >> exp;
                            result = power(num, exp);
                            cout << "    " << num << " to the power " << exp << " is " << result << endl;
                        break;
                        case 3:
                            cout << "     Enter a number: ";
                            cin >> num;
                            result = absolute(num);
                            cout << "     The absolute value of " << num << " is " << result << endl;
                        break;
                    }
                break;
                case 2:
                    cout << "   1. Circumference" << endl;
                    cout << "   2. Area" << endl;
                    cout << "   3. Volume" << endl;
                    cin >> sel;
                    switch(sel) {
                        case 1:
                            cout << "     Enter a radius: ";
                            cin >> num;
                            result = Circumference(num);
                            cout << "     The circumference of a circle with radius " << num << " is " << result << endl;
                        break;
                        case 2:
                            cout << "     Enter a radius: ";
                            cin >> num;
                            result = Area(num);
                            cout << "     The area of a circle with radius " << num << " is " << result << endl;
                        break;
                        case 3:
                            cout << "     Enter a radius: ";
                            cin >> num;
                            result = Volume(num);
                            cout << "     The volume of a sphere with radius " << num << " is " << result << endl;
                        break;
                    }
                break;
                case 3:
                    cout << "   1. Celsius to Fahrenheit" << endl;
                    cout << "   2. Fahrenheit to Celsius" << endl;
                    cout << "   3. Inches to Centimeters" << endl;
                    cout << "   4. Centimeters to Inches" << endl;
                    cout << "   5. Kilograms to Pounds" << endl;
                    cout << "   6. Pounds to Kilograms" << endl;
                    cin >> sel;
                    switch(sel) {
                        case 1:
                            cout << "     Enter the temperature in celsius: ";
                            cin >> num;
                            result = CelsiusToFahrenheit(num);
                            cout << "     " << num << " in degrees fahrenheit is " << result << endl;
                        break;
                        case 2:
                            cout << "     Enter the temperature in fahrenheit: ";
                            cin >> num;
                            result = FahrenheitToCelsius(num);
                            cout << "     " << num << " in degrees celsius is " << result << endl;
                        break;
                        case 3:
                            cout << "     Enter the length in inches: ";
                            cin >> num;
                            result = InchesToCentimeters(num);
                            cout << "     " << num << " in centimeters is " << result << endl;
                        break;
                        case 4:
                            cout << "     Enter the length in centimeters: ";
                            cin >> num;
                            result = CentimetersToInches(num);
                            cout << "     " << num << " in inches is " << result << endl;
                        break;
                        case 5:
                            cout << "     Enter the mass in kilograms: ";
                            cin >> num;
                            result = KilogramsToPounds(num);
                            cout << "     " << num << " in pounds is " << result << endl;
                        break;
                        case 6:
                            cout << "     Enter the mass in pounds: ";
                            cin >> num;
                            result = PoundsToKilograms(num);
                            cout << "     " << num << " in kilograms is " << result << endl;
                        break;
                    }
                break;
            }
            sleep(3);
        }
    }
}
