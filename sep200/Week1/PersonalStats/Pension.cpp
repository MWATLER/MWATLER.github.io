//Pension.cpp - source code for pension calculations

#include "Pension.h"

extern int age;

double CalculatePension() {
	double amount = age * 23.34;
	return amount;
}