//Cargo.h - class declaration for a cargo ship

#ifndef _CARGO_H_
#define _CARGO_H_

#include "Spaceship.h"

class Cargo : public Spaceship {
	double speed;
	double distance;
	double fuel;
	int numPayload;
	Payload* payload;
	double GetMass();
public:
	Cargo(const char* _name, int _numPayload);
	Cargo(const Cargo& cg);
	Cargo& operator=(const Cargo& rhs);
	bool ChangeSpeed(double _speed);
	void Travel(double _time);
	void PrintReport();
	~Cargo();
};

#endif// _CARGO_H_