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

template<typename T> bool SetInformation(T car) {
	return car->SetInformation();
}

template<typename T> bool AddFuel(T car, double _fuel) {
	return car->AddFuel(_fuel);
}

template<typename T> bool Travel(T car, double _distance) {
	return car->Travel(_distance);
}

template<typename T> void PrintReport(T car) {
	car->PrintReport();
}

iAutomobile* CreateAutomobile();

#endif// _IAUTOMOBILE_H_
