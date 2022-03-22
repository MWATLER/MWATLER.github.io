//Inductor.h - class declaration for modelling an inductor

#ifndef _INDUCTOR_H_
#define _INDUCTOR_H_

#include <iostream>

class Inductor {
	std::string name;
	double inductance;
	double current;
public:
	Inductor();
	Inductor(std::string, double);
	bool SetName(std::string);
	bool SetInductance(double);
	double GetVoltage(double _current, double timestep);//L di/dt
};

#endif
