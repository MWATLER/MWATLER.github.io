//Starship.h - class declaration for a starship

#ifndef _STARSHIP_H_
#define _STARSHIP_H_

#include "Spaceship.h"

class Starship : public Spaceship {
	double speed;
	double distance;
	double fuel;
	int numPayload;
	int numWeapons;
	Payload* payload;
	Weapons* weapons;
	double GetMass();
public:
	Starship();
	Starship(const char* _name, int _numPayload, int _numWeapons);
	Starship(const Starship& st);
	Starship& operator=(const Starship& rhs);
	void SetName(const char* _name);
	bool ChangeSpeed(double _speed);
	void Travel(double _time);
	bool FireTorpedos(int _num);
	bool FireLaserCannons(double _time);
	void PrintReport();
	~Starship();
};

#endif// _STARSHIP_H_
