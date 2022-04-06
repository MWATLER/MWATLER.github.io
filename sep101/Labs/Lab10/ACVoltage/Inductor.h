//Inductor.h - class declaration for the inductor

#ifndef _INDUCTOR_H_
#define _INDUCTOR_H_

class Inductor {
	double inductance;
	double current;
public:
	Inductor(double _inductance);
	double GetCurrent(double voltage, double timeStep);
};


#endif// _INDUCTOR_H_