//EuropeanAuto.h - class declaration for a european car

#ifndef _EUROPEANAUTO_H_
#define _EUROPEANAUTO_H_

#include "iAutomobile.h"

class EuropeanAuto : public iAutomobile {
	std::string make;
	int year;
	bool isStandard;
	double LPer100K;
	double fuel;
public:
	bool SetInformation();
	bool AddFuel(double _fuel);
	bool Travel(double _distance);
	double GetFuel();
	void PrintReport();
};

#endif// _EUROPEANAUTO_H_