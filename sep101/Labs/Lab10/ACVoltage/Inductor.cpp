//Inductor.cpp - function definitions for the inductor class

#include "Inductor.h"

Inductor::Inductor(double _inductance) {
	inductance = _inductance;
	current = 0.0;
}

double Inductor::GetCurrent(double voltage, double timeStep) {
	current += voltage * timeStep / inductance;
	return current;
}