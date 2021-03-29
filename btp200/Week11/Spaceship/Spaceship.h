//Spaceship.h - parent class for a spaceships

#ifndef _SPACESHIP_H_
#define _SPACESHIP_H_

struct Weapons {
	int numTorpedos;
	int numLaserCannons;
};

struct Payload {
	double massPassengers;
	double massPayload;
};

class Spaceship {
	char* name;
protected:
	const double speedOfLight = 299792458.0;//299,792,458 m/s
	char* GetName() const;
public:
	Spaceship();
	Spaceship(const char* _name);
	Spaceship& operator=(const Spaceship& rhs);
	void SetName(const char* _name);
	//Every function that we call from a derived class has to be declared here!
	virtual bool ChangeSpeed(double _speed) { return false; };
	virtual void Travel(double _time) {};
	virtual bool FireTorpedos(int _num) { return false; };
	virtual bool FireLaserCannons(double _time) { return false; };
	virtual void PrintReport() {};
	virtual ~Spaceship();
};

#endif// _SPACESHIP_H_