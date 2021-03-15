//Resistor.cpp - function definitions for the resistor
//
// 15-Feb-21  M. Watler         Created.
#include "Resistor.h"

Resistor::Resistor() {
	resistance = 0.0;
	current = 0.0;
}

Resistor::Resistor(double _resistance) {
	resistance = _resistance;
	current = 0.0;
}

void Resistor::SetCurrent(double _current) {
	current = _current;
}

double Resistor::GetVoltage(void) {
	return resistance * current;
}

void Resistor::PrintReport() {
	cout << "Resistor voltage:" << GetVoltage() << endl;
}

Resistor::~Resistor() {
//Do nothing
}
