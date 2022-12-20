//Component.h - abstract base class for electronic components

//
// 19-May-22  M. Watler         Created.
// 27-May-22  M. Watler         Added graphical display.

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <iostream>

class Component {
protected:
	float Red;
	float Green;
	float Blue;
	std::string name;
public:
	virtual std::string GetName() const = 0;
	virtual void Update() = 0;
	virtual double GetVoltage(double _current, double timestep)=0;
	virtual void Display() = 0;
};

#endif// _COMPONENT_H_