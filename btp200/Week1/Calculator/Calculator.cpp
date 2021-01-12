// Calculator.cpp

#include "Calculator.h"

int power(int base, int exp) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
}

int exponent(int result, int base) {
    int exp = 0;
    while (result >= base) {
        exp++;
        result /= base;
    }
    return exp;
}