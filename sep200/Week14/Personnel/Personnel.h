//Personnel.h - class declaration for the Personnel base class

#ifndef _PERSONNEL_H_
#define _PERSONNEL_H_

#include <iostream>
#include <vector>
#include "Vehicle.h"

class Personnel {
public:
	enum class Role {
		Student,
		Faculty
	};
private:
	std::string name;
	Personnel::Role role;
	std::string address;
	int SenecaNumber;
	std::vector<Vehicle> vehicles;
public:
	Personnel(std::string _name, Personnel::Role _role, std::string _address, int number);
	virtual std::string GetInfo() const;
	std::string GetName() const;
	virtual double GetSalary() const;
	virtual double GetAverage() const;
	virtual std::vector<int> GetMarks() const;
	std::vector<Vehicle> GetCars() const;
};

#endif// _PERSONNEL_H_
