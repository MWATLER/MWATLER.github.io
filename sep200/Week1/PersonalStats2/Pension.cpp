//Pension.cpp - source code for pension calculations

#include "Pension.h"

static int age=55;//Use age as it is defined in this file only
//extern int age;//Use age as it is defined externally (in PersonalMain.cpp)

double CalculatePension() {
	double amount = age * 23.34;
	return amount;
}