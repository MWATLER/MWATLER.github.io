//General.cpp - General Calculations
//
// 14-Jan-19  M. Watler         Created.

#include "General.h"

int factorial(int num) {
    int result = 1;
    for (int i=1;i<=num;i++)
        result *= i;
    return result;
}

double power(double num, int exponent) {
    double result = 1;
    for (int i=0;i<exponent;i++)
        result *= num;
    return result;
}

double absolute(double num) {
    double result = num;
    if(result<0) result *= -1.0;
    return result;
}
