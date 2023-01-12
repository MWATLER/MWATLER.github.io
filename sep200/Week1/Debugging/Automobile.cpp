// Automobile.cpp - Implementation of the Automobile class
//
// 12-Mar-19  M. Watler         Created.
//
#include "Automobile.h"

using namespace std;

Automobile::Automobile(string _make, string _model, string _colour, int _year)
{
	make = _make;
	model = _model;
	colour = _colour;
	year = _year;
	fuelInTank = 0;
}

void Automobile::setFuelEfficiency(double _efficiency)
{
	fuelEfficiency = _efficiency;
}

void Automobile::emptyFuel(void)
{
	fuelInTank = 0;
}

void Automobile::addFuel(double _liters)
{
	fuelInTank += _liters;
	if (fuelInTank > 50) {
		fuelInTank = 50;//Cap at 50 liters
#ifdef DEBUG
		const int BUFSIZE = 256;
		char message[BUFSIZE];
		sprintf_s(message, BUFSIZE, "The %s %d %s %s is full of gas. Discarding the rest...\n", colour.c_str(), year, make.c_str(), model.c_str());
		Log(1, message);
#endif
	}
}

void Automobile::drive(double _distance)
{
	//liters consumed = liters/100km divide by 100km to get liters/km
	//                  then multiply that by the distance in km
	double fuelConsumed = fuelEfficiency / 100 * _distance;
	fuelInTank -= fuelConsumed;
	if (fuelInTank < 0) {
		fuelInTank = 0;
		const int BUFSIZE = 256;
		char message[BUFSIZE];
		sprintf_s(message, BUFSIZE, "The %s %d %s %s has no gas left in the tank\n", colour.c_str(), year, make.c_str(), model.c_str());
#ifdef DEBUG
		Log(2, message);
#endif
	}
}

void Automobile::displayReport()
{
	cout << "The " << colour << " " << year << " " << make << " " << model << " has " << fuelInTank << " left in the tank" << endl;
}

