//Vehicle.h - class declaration for an vehicle

#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <iostream>

class Vehicle {
public:
	enum class Err_Status {
		Err_Success,
		//TODO: Complete for out of fuel, fuel overflow, and incorrect mode
	};
	//TODO: Add function interfaces for travel, add fuel, get fuel and get cost.
	//      Travel takes distance as an argument and returns an error status
	//      AddFuel takes amount as an argument and returns an error status
	//      GetFuel simply returns the amount of fuel left in the tank
	//      GetCost simply returns the accumulated cost of all fuel purchases
};

#endif// _VEHICLE_H_