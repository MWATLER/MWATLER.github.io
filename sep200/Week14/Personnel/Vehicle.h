//Vehicle.h - class declaration for a vehicle

#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <iostream>

class Vehicle {
	std::string make;
	int year;
	int currentYear;
public:
	Vehicle(std::string _make, int _year, int _currYear);
	std::string GetMake() const;
	int GetAge() const;
};

#endif// _VEHICLE_H_
