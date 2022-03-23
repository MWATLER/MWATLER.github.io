//Inductor.h - class declaration for modelling an inductor

#ifndef _INDUCTOR_H_
#define _INDUCTOR_H_

#include <iostream>

class Inductor {
	std::string name;
	double inductance;//magnetic inductance
	double current;//keep track of the current through the inductor
public:
	//two constructors
	Inductor();
	Inductor(std::string, double);//correct syntax. For a function prototype (or function declaration),
	                              //I only need to specify the types of the parameters. I do not have
	                              //to have parameter names as well.
	bool SetName(std::string);
	bool SetInductance(double);
	double GetVoltage(double _current, double timestep);//V = L di/dt
};

#endif
