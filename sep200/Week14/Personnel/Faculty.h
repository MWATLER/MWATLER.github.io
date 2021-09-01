//Faculty.h - class declaration for the Faculty class

#ifndef _FACULTY_H_
#define _FACULTY_H_

#include <iostream>
#include "Personnel.h"

class Faculty : public Personnel {
	double salary;
public:
	Faculty(std::string _name, Personnel::Role _role, std::string _address, int number);
	std::string GetInfo() const;
	double GetSalary() const;
	double GetAverage() const;
	std::vector<int> GetMarks() const;
};

#endif// _FACULTY_H_
