//Math.cpp - math features

#include "Math.h"

int Math::square(int num)
{
	return num * num;
}

double Math::square(double num)
{
	return num * num;
}

double Math::square(int numerator, int denominator)
{
	return (double)(numerator * numerator) / (denominator * denominator);
}

double Math::square(double numerator, double denominator)
{
	return (numerator * numerator) / (denominator * denominator);
}