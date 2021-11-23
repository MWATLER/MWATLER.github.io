//Plane.h - class declaration for a plane

#include<iostream>

class Plane {
	std::string* name;//names of the pilots
	int numPilots;//the number of pilots
	double fuel;
	const double fuelCapacity = 3000;//300L
	const double fuelEfficiency = 2.0;//2km / L
	double GetRange();
public:
	Plane();
	Plane(std::string* _name, int num, double _fuel);
	void SetName(std::string* name, int num);
	void AddFuel(double _fuel);
	bool Travel(double km);
	void Report();
	~Plane();
};