//Conversions.cpp - Simple Unit Conversions
//
// 14-Jan-19  M. Watler         Created.

#include "Conversions.h"
#include <stdio.h>

double CelsiusToFahrenheit(double celsius) {
    //Simulate a crash by accessing an area of memory which I have no privilege for
#ifdef CRASH
    char *ptr=0;
    printf("%02X %02X %02X\n", ptr[0], ptr[1], ptr[2]);
#endif
    return celsius * 9.0 / 5.0 + 32.0;
}

double FahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit-32) * 5.0 / 9.0;
}

double InchesToCentimeters(double inches) {
    return 2.54 * inches;
}

double CentimetersToInches(double centimeters) {
    return centimeters / 2.54;
}

double KilogramsToPounds(double kilograms) {
    return kilograms * 2.205;
}

double PoundsToKilograms(double pounds) {
    return pounds / 2.205;
}
