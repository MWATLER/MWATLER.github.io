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

Plane::Plane(std::string* name, int num, double fuel) {
	if (num > 0) {
		this->name = new std::string[num];
		for (int i = 0; i < num; ++i) {
			this->name[i] = name[i];
		}
	}
	else {
		this->name = nullptr;
	}
	this->numPilots = num;
	this->fuel = fuel;
}

void Plane::SetName(std::string* name, int num) {//an array of names, the array size is 'num'
	numPilots = num;
	if (num > 0) {
		delete[] this->name;
		this->name = new std::string[num];
		for (int i = 0; i < num; ++i) {
			this->name[i] = name[i];
		}
	}
}

void Plane::AddFuel(double fuel) {
	this->fuel += fuel;
	if (this->fuel > fuelCapacity) this->fuel = fuelCapacity;
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
	delete[] name;
	name = nullptr;
}
