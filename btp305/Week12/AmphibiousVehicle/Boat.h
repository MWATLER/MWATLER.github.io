//Boat.h - class declaration for an boat

#ifndef _BOAT_H_
#define _BOAT_H_

#include <iostream>
#include "Vehicle.h"

class Boat : public Vehicle {
	std::string name;
	double litresPerHour;
	double fuelInTank;
	double cost;
	const double speed = 20.0;//average cruising speed
	const double costPerLitre = 1.60;//$1.60 per litre of boat fuel
	const double tankCapacity = 150.0;
public:
	Boat(std::string _name, double efficiency, double fuel);
	Err_Status Travel(double distance);
	Err_Status AddFuel(double amount);
	double GetFuel() const;
	double GetCost() const;
};

#endif// _BOAT_H_
