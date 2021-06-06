//Conversions.cpp - Simple Unit Conversions
//
// 14-Jan-19  M. Watler         Created.

#include "Conversions.h"
#include <stdio.h>
#ifdef DEBUG
#include <iostream>
using namespace std;
#endif

double CelsiusToFahrenheit(double celsius) {
#ifdef DEBUG
    cerr<<"CelsiusToFahrenheit(celsius: "<<celsius<<"):"<<endl;
#endif
    //Simulate a crash by accessing an area of memory which I have no privilege for
#ifdef CRASH
    char *ptr=0;
    printf("%02X %02X %02X\n", ptr[0], ptr[1], ptr[2]);
#endif
    return celsius * 9.0 / 5.0 + 32.0;
}

double FahrenheitToCelsius(double fahrenheit) {
#ifdef DEBUG
    cerr<<"FahrenheitToCelsius(fahrenheit: "<<fahrenheit<<"):"<<endl;
#endif
    return (fahrenheit-32) * 5.0 / 9.0;
}

double InchesToCentimeters(double inches) {
#ifdef DEBUG
    cerr<<"InchesToCentimeter(inches: "<<inches<<"):"<<endl;
#endif
    return 2.54 * inches;
}

double CentimetersToInches(double centimeters) {
#ifdef DEBUG
    cerr<<"CentimeterToInches(centimeters: "<<centimeters<<"):"<<endl;
#endif
    return centimeters / 2.54;
}

double KilogramsToPounds(double kilograms) {
#ifdef DEBUG
    cerr<<"KilogramsToPounds(kilograms: "<<kilograms<<"):"<<endl;
#endif
    return kilograms * 2.205;
}

double PoundsToKilograms(double pounds) {
#ifdef DEBUG
    cerr<<"PoundsToKilograms(pounds: "<<pounds<<"):"<<endl;
#endif
    return pounds / 2.205;
}
