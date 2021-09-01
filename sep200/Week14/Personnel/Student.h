//Student.h - class declaration for the Student class

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <vector>
#include "Personnel.h"

class Student : public Personnel{
	std::vector<int> marks;
public:
	Student(std::string _name, Personnel::Role _role, std::string _address, int number);
	std::string GetInfo() const;
	double GetSalary() const;
	double GetAverage() const;
	std::vector<int> GetMarks() const;
};

#endif// _STUDENT_H_
