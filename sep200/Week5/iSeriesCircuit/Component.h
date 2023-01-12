//Component.h - class declaration for a generic component
//
// 09-Mar-21  M. Watler         Created.

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <iostream>
#include "iComponent.h"

class Component : public iComponent{//is-a relationship
	double voltage;//has-a relationship
	double current;//has-a relationship
public:
	Component() {
		voltage = 0.0;
		current = 0.0;
	}
	virtual void SetCurrent(double _current) {
		current = _current;
	};
	virtual double GetVoltage(void) {
		return voltage;
	}
	virtual void PrintReport() {
		std::cout << "Component voltage:" << voltage << std::endl;
	}
	virtual ~Component() {
		std::cout << "Component::~Component()" << std::endl; 
	}
};

iComponent* CreateComponent();

#endif//_COMPONENT_H_