//Resistor.h - class declaration for the modelling of a resistor

#ifndef _RESISTOR_H_
#define _RESISTOR_H_

#include <iostream>

class Resistor {
	std::string name;
	double resistance;
public:
	Resistor();
	Resistor(std::string, double);
	bool SetName(std::string);
	bool SetResistance(double);
	double GetVoltage(double _current);
};

#endif// _RESISTOR_H_
