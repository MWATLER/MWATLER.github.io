//AmericanAuto.cpp - function definitions for a american car

#include "AmericanAuto.h"

bool AmericanAuto::SetInformation() {
	std::cout << "Enter the make: ";
	std::cin >> make;
	std::cout << "Enter the year: ";
	std::cin >> year;
	std::cout << "Enter the fuel (gallons): ";
	std::cin >> fuel;
	std::cout << "Enter the fuel consumption (mpg): ";
	std::cin >> milesPerGal;
	std::cout << std::endl;
	return true;//TODO: Should validate each entry, return false if any are invalid
}

bool AmericanAuto::AddFuel(double _fuel) {
	bool ret = true;
	const double MAX = 15.0;//Tank capacity of 15 gallons
	if (_fuel < 0) {
		ret = false;
		std::cout << "ERROR: Cannot add negative fuel to the " << make << "." << std::endl << std::endl;
	}
	else if ((fuel + _fuel) > MAX) {
		ret = false;
		std::cout << "ERROR: Tank capacity exceeded for the " << make << "." << std::endl << std::endl;
		fuel = MAX;
	}
	else {
		fuel += _fuel;
	}
	return ret;
}

bool AmericanAuto::Travel(double _distance) {
	bool ret = true;
	double fuelConsumed = _distance / milesPerGal;
	if (fuelConsumed > fuel) {
		ret = false;
		std::cout << "ERROR: The " << make << " does not have enough gas in the tank." << std::endl << std::endl;
		fuel = 0.0;
	}
	else {
		fuel -= fuelConsumed;
	}
	return false;
}

double AmericanAuto::GetFuel() {
	return fuel;
}

void AmericanAuto::PrintReport() {
	std::cout << "The " << year << " " << make << " has " << fuel << " gallons left in the tank." << std::endl << std::endl;
}