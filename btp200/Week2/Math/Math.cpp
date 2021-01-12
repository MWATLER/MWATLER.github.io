//Math.cpp - math features

#include "Math.h"

int square(int num)
{
	return num * num;
}

double square(double num)
{
	return num * num;
}

double square(int numerator, int denominator)
{
	return (double)(numerator * numerator) / (denominator * denominator);
}