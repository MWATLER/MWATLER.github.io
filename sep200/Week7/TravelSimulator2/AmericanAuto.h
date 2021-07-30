//AmericanAuto.h - class declaration for a american car

#ifndef _AMERICANAUTO_H_
#define _AMERICANAUTO_H_

#include "iAutomobile.h"

class AmericanAuto : public iAutomobile {
	std::string make;
	int year;
	double milesPerGal;
	double fuel;
public:
	bool SetInformation();
	bool AddFuel(double _fuel);
	bool Travel(double _distance);
	double GetFuel();
	void PrintReport();
};

#endif// _AMERICANAUTO_H_