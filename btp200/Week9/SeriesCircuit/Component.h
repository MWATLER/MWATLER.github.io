//Resistor.h - class declaration for a generic component
//
// 09-Mar-21  M. Watler         Created.

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <iostream>
using namespace std;

class Component {
	double voltage;
	double current;
public:
	Component() {
		voltage = 0.0;
		current = 0.0;
	}
	void SetCurrent(double _current) {//set to virtual
		current = _current;
	};
	double GetVoltage(void) {//set to virtual
		return voltage;
	}
	void PrintReport() {//set to virtual
		cout << "Component voltage:" << voltage << endl;
	}
	~Component() {};
};

#endif//_COMPONENT_H_