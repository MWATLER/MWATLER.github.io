//Plane.cpp - function definitions for a plane

#include "Plane.h"

using namespace std;

double Plane::GetRange() {
	return fuel * fuelEfficiency;//L x km/L
}

Plane::Plane() {
	name = nullptr;
	numPilots = 0;
	fuel = 0;
}

Plane::Plane(std::string* _name, int num, double _fuel) {
	if (num > 0) {
		name = new std::string[num];
		for (int i = 0; i < num; ++i) {
			name[i] = _name[i];
		}
	}
	else {
		name = nullptr;
	}
	numPilots = num;
	fuel = _fuel;
}

void Plane::SetName(std::string* name, int num) {
	numPilots = num;
	if (num > 0) {
		if (this->name != nullptr) {
			delete[] this->name;
		}
		this->name = new std::string[num];
		for (int i = 0; i < num; ++i) {
			this->name[i] = name[i];
		}
	}
}

void Plane::AddFuel(double _fuel) {
	fuel += _fuel;
	if (fuel > fuelCapacity) fuel = fuelCapacity;
}

bool Plane::Travel(double km) {
	bool ret = true;
	double range = GetRange();
	if (range < km) {
		ret = false;
	}
	else {
		fuel -= km / fuelEfficiency;
	}
	return ret;
}

void Plane::Report() {
	cout << "The plane has pilot(s) ";
	for (int i = 0; i < numPilots; ++i) {
		cout << name[i] << " ";
	}
	cout << ". It has " << fuel << "L of fuel left in the tank." << endl << endl;
}


Plane::~Plane() {
	if (name != nullptr) {
		delete[] name;
		name = nullptr;
	}
}
