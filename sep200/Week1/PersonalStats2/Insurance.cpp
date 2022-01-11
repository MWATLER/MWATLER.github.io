//Insurance.cpp - source code for insurance calculations

#include "Insurance.h"

static int age=55;

double CalculateInsurance() {
	double amount = (age-21.0) * 12.11;
	if (amount < 0.0) amount = 0.0;
	return amount;
}