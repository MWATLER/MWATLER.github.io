//Inductor.cpp - function definitions for the inductor class

#include "Inductor.h"

Inductor::Inductor() {
	name = "";
	inductance = 0.0;
	current = 0.0;
}

Inductor::Inductor(std::string name, double inductance) {
	this->name = name;
	this->inductance = inductance;
	this->current = 0.0;
}

bool Inductor::SetName(std::string name) {
	bool retVal = true;
	if (name != "") this->name = name;
	else retVal = false;
	return retVal;
}

bool Inductor::SetInductance(double inductance) {
	bool retVal = true;
	if (inductance > 0)this->inductance = inductance;
	else retVal = false;
	return retVal;
}

double Inductor::GetVoltage(double newCurrent, double timestep) {
	double voltage = inductance * (newCurrent - current) / timestep;//V = L di/dt
	current = newCurrent;
	return voltage;
}