//AmphibiousVehicle.h - class declaration for an amphibious vehicle

#ifndef _AMPHIBIOUSVEHICLE_H_
#define _AMPHIBIOUSVEHICLE_H_

#include <iostream>
#include "Boat.h"
#include "Automobile.h"

class AmphibiousVehicle:public Boat, public Automobile {
	std::string name;
	unsigned short mode;
public:
	//state variables, which are used to enable certain functionalities and disable others
	static const int VEHICLE_NONE = 0x00;
	static const int VEHICLE_AUTOMOBILE = 0x01;
	static const int VEHICLE_BOAT = 0x02;

	AmphibiousVehicle(std::string _name);
	Err_Status Travel(double distance);//pure virtual inside of Vehicle
	Err_Status AddFuel(double amount);//pure virtual inside of Vehicle
	std::string GetName() const;
	double GetFuel() const;//pure virtual inside of Vehicle
	double GetCost() const;//pure virtual inside of Vehicle
	Err_Status UnsetMode(unsigned short _mode);
	Err_Status SetMode(unsigned short _mode);
};

#endif// _AMPHIBIOUSVEHICLE_H_