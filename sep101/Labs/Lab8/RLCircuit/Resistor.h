//Resistor.h - class declaration for the modelling of a resistor

#ifndef _RESISTOR_H_
#define _RESISTOR_H_

#include <iostream>

class Resistor {
	std::string name;
	double resistance;
public:
	//Constructors take the same name as the class itself, and there is no return type
	Resistor();//default constructor
	//You can overload functions, in that you can have two more more functions with
	//the same name, but different lists of parameters
	Resistor(std::string, double);//a constructor with parameters
	bool SetName(std::string);
	bool SetResistance(double);
	double GetVoltage(double _current);//V = I*R
};

#endif// _RESISTOR_H_
