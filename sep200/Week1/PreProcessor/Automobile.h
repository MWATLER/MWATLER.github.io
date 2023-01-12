// Automobile.h - Header file for the Automobile class
//
// 12-Mar-19  M. Watler         Created.
//

#ifndef _AUTOMOBILE_H_
#define _AUTOMOBILE_H_

#include <iostream>

#define DEBUG

enum class Log_Lvl {
	LOG_INFO=0,//0 by default
	LOG_WARNING,//1
	LOG_ERROR,//2
	LOG_CRITICAL//3
};

extern Log_Lvl LVL;//visible to all code that includes Automobile.h
#define Log(lvl, msg) if(lvl>=LVL) if(lvl==Log_Lvl::LOG_INFO) std::cout <<"LOG_INFO: "<< __FILE__ << ":" << __func__ << ":" << __LINE__ << ":" << msg << std::endl;\
                                   else if (lvl == Log_Lvl::LOG_WARNING) std::cout << "LOG_WARNING: " << __FILE__ << ":" << __func__ << ":" << __LINE__ << ":" << msg << std::endl;\
                                   else if (lvl == Log_Lvl::LOG_ERROR) std::cout << "LOG_ERROR: " << __FILE__ << ":" << __func__ << ":" << __LINE__ << ":" << msg << std::endl;\
                                   else if (lvl == Log_Lvl::LOG_CRITICAL) std::cout << "LOG_CRITICAL: " << __FILE__ << ":" << __func__ << ":" << __LINE__ << ":" << msg << std::endl;

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
