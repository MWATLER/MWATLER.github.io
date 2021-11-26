//Vehicle.h - class declaration for an vehicle

#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <iostream>

class Vehicle {
public:
	enum class Err_Status {
		Err_Success,
		Err_OutOfFuel,
		Err_FuelOverflow,
		Err_IncorrectMode
	};
	virtual Err_Status Travel(double distance) = 0;
	virtual Err_Status AddFuel(double amount) = 0;
	virtual double GetFuel() const = 0;
	virtual double GetCost() const = 0;
};

#endif// _VEHICLE_H_