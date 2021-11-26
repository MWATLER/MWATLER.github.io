//Automobile.h - class declaration for an automobile

#ifndef _AUTOMOBILE_H_
#define _AUTOMOBILE_H_

#include <iostream>
#include "Vehicle.h"

class Automobile : public Vehicle{
	std::string name;
	double fuelEfficiency;//L per 100km
	double fuelInTank;
	double cost;
	const double costPerLitre = 1.30;//$1.30 per litre of fuel
	const double tankCapacity = 50.0;
public:
	Automobile(std::string _name, double efficiency, double gas);
	Err_Status Travel(double distance);
	Err_Status AddFuel(double amount);
	double GetFuel() const;
	double GetCost() const;
};

#endif// _AUTOMOBILE_H_
