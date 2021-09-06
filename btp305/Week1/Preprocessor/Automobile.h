// Automobile.h - Header file for the Automobile class
//
// 12-Mar-19  M. Watler         Created.
//

#ifndef _AUTOMOBILE_H_
#define _AUTOMOBILE_H_

#define DEBUG
#define LVL 2
#define Log(lvl, msg) if(lvl>=LVL) std::cout<<__FILE__<<":"<<__func__<<":"<<__LINE__<<":"<<msg<<std::endl;

#include <iostream>

class Automobile {
private:
	std::string make;
	std::string model;
	std::string colour;
	int year;
	double fuelEfficiency;
	double fuelInTank;

public:
	Automobile(std::string _make, std::string _model, std::string _colour, int _year);
	void setFuelEfficiency(double _efficiency);
	void emptyFuel(void);
	void addFuel(double _liters);
	void drive(double _distance);
	void displayReport();
};

#endif// _AUTOMOBILE_H_
