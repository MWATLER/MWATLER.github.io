//iAutomobile.h - class declaration for an automobile

#ifndef _IAUTOMOBILE_H_
#define _IAUTOMOBILE_H_

#include <iostream>

class iAutomobile {
public:
	virtual bool SetInformation() = 0;
	virtual bool AddFuel(double _fuel) = 0;
	virtual bool Travel(double _distance) = 0;
	virtual void PrintReport() = 0;
};

iAutomobile* CreateAutomobile();

#endif// _IAUTOMOBILE_H_
