//Inductor.cpp - function definitions for the inductor class

#include "Inductor.h"

Inductor::Inductor() {
	name = "";
	inductance = 0.0;
	current = 0.0;
}

//From main: Inductor L1("L1", 0.01);//0.01 Henries
Inductor::Inductor(std::string _name, double _inductance) {
	name = _name;
	inductance = _inductance;
	current = 0.0;
}

bool Inductor::SetName(std::string _name) {
	bool retVal = true;
	if (name != "") name = _name;
	else retVal = false;
	return retVal;
}

bool Inductor::SetInductance(double _inductance) {
	bool retVal = true;
	if (inductance > 0) inductance = _inductance;
	else retVal = false;
	return retVal;
}

double Inductor::GetVoltage(double newCurrent, double timestep) {
	double voltage = inductance * (newCurrent - current) / timestep;//V = L di/dt
	current = newCurrent;
	return voltage;
}