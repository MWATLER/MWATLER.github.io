//Pension.cpp - source code for pension calculations

#include "Pension.h"

extern int age;//age has been defined externally

double CalculatePension() {
	double amount = age * 23.34;
	return amount;
}