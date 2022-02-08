//NumberStudent.h - class declaration for a number student

#ifndef _NUMBERSTUDENT_H_
#define _NUMBERSTUDENT_H_

#include <iostream>
#include "Student.h"

class NumberStudent : public Student {
	int GetNumberGrade(double mark) const;
	double GetAverage() const;
public:
	NumberStudent(std::string _name, int _number, const int* _marks, int _numMarks);
	void display(std::ostream& os) const;
	~NumberStudent();
};

std::ostream& operator<<(std::ostream& os, NumberStudent& student);

#endif// _NUMBERSTUDENT_H_