//Automobile.c - function definitions for the automobile

#include <stdio.h>
#include "Automobile.h"

int drive(struct Automobile* automobile, double _distance) {
	int retVal = 0;
	if (_distance < 0) retVal = -1;
	else {
		double fuelConsumed = automobile->fuelEfficiency / 100 * _distance;
		automobile->fuelInTank -= fuelConsumed;
		if (automobile->fuelInTank<0) {
			retVal = -2;
			automobile->fuelInTank = 0;
			printf("WARNING: The %s %d %s %s has no gas left in the tank.\n",
				automobile->colour, automobile->year, automobile->make, automobile->model);
		}
	}
	return retVal;
}

void displayReport(struct Automobile automobile) {
	printf("The %s %d %s %s has %lf litres left in the tank.\n",
		automobile.colour, automobile.year, automobile.make, automobile.model, automobile.fuelInTank);
}