//Warbird.h - class declaration for a warbird

#ifndef _WARBIRD_H_
#define _WARBIRD_H_

#include "Spaceship.h"

class Warbird : public Spaceship {
	double speed;
	double distance;
	double fuel;
	int numPayload;
	int numWeapons;
	Weapons* weapons;
	Payload* payload;
	double GetMass();
public:
	Warbird(const char* _name, int _numPayload, int _numWeapons);
	Warbird(const Warbird& wb);
	Warbird& operator=(const Warbird& rhs);
	bool ChangeSpeed(double _speed);
	void Travel(double _time);
	bool FireTorpedos(int _num);
	bool FireLaserCannons(double _time);
	void PrintReport();
	~Warbird();
};

#endif// _WARBIRD_H_