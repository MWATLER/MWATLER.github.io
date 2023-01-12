//EuropeanAuto.cpp - function definitions for a european car

#include "EuropeanAuto.h"

bool EuropeanAuto::SetInformation() {
	std::cout << "Enter the make: ";
	std::cin >> make;
	std::cout << "Enter the year: ";
	std::cin >> year;
	std::cout << "Is it a standard? [Y/N] ";
	std::string standard;
	std::cin >> standard;
	if (standard == "Y" || standard == "y") {
		isStandard = true;
	}
	else {
		isStandard = false;
	}
	std::cout << "Enter the fuel (litres): ";
	std::cin >> fuel;
	std::cout << "Enter the fuel consumption (L per 100km): ";
	std::cin >> LPer100K;
	std::cout << std::endl;
	return true;//TODO: Should validate each entry, return false if any are invalid
}

bool EuropeanAuto::AddFuel(double _fuel) {
	bool ret = true;
	const double litresPerGallon = 3.78541;
	const double MAX = 50.0;//Tank capacity of 50L
    
	//convert the fuel amount to litres
	_fuel *= litresPerGallon;

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

bool EuropeanAuto::Travel(double _distance) {
	bool ret = true;
	const double kmPerMile = 1.60934;

	//convert the distance to km
	_distance *= kmPerMile;

	double fuelConsumed = LPer100K * _distance / 100.0;
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

double EuropeanAuto::GetFuel() {
	return fuel;
}

void EuropeanAuto::PrintReport() {
	std::cout << "The " << year << " " << make << " has " << fuel << "L left in the tank." << std::endl;
	if (isStandard) {
		std::cout << "It has a standard transmission" << std::endl;
	}
	std::cout << std::endl;
}