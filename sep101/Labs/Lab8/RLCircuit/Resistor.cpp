//Resistor.cpp - function definitions for the resistor class

#include "Resistor.h"

Resistor::Resistor() {
	name = "";
	resistance = 0.0;
}

Resistor::Resistor(std::string name, double resistance) {
	this->name = name;
	this->resistance = resistance;
}

bool Resistor::SetName(std::string name) {
	bool retVal = true;
	if (name != "") this->name = name;
	else retVal = false;
	return retVal;
}

bool Resistor::SetResistance(double resistance) {
	bool retVal = true;
	if (resistance > 0)this->resistance = resistance;
	else retVal = false;
	return retVal;
}

double Resistor::GetVoltage(double current) {
	return current * resistance;//V = IR
}