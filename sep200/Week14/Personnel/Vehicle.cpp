//Vehicle.cpp - function definitions for a vehicle

#include "Vehicle.h"

Vehicle::Vehicle(std::string _make, int _year, int _currYear) {
	make = _make;
	year = _year;
	currentYear = _currYear;
}

std::string Vehicle::GetMake() const {
	return make;
}

int Vehicle::GetAge() const {
	return currentYear - year;
}
