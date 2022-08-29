//Resistor.cpp - function definitions for the resistor class

#include "Resistor.h"

Resistor::Resistor() {//default constructor
	name = "";
	resistance = 0.0;
}

//from main: Resistor R1("R1", 100.0);//100 ohms
//           Resistor R2("R2", 50.0);//50 ohms
Resistor::Resistor(std::string _name, double _resistance) {//a second constructor, taking two parameters
	name = _name;
	resistance = _resistance;
}

bool Resistor::SetName(std::string _name) {
	bool retVal = true;
	if (name != "") name = _name;
	else retVal = false;
	return retVal;
}

bool Resistor::SetResistance(double _resistance) {
	bool retVal = true;
	if (resistance > 0) resistance = _resistance;
	else retVal = false;
	return retVal;
}

double Resistor::GetVoltage(double current) {
	return current * resistance;//V = IR
}