//Student.h - class declaration for a student

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>

class Student {
	//these are common to this class and all derived classes
	std::string name;
	int number;
	int* marks;
	int numMarks;
protected://for derived classes only
	std::string GetName() const;
	int* GetMarks() const;
	int GetNumMarks() const;
public:
	Student(std::string _name, int _number, const int* _marks, int _numMarks);
	double GetAverage() const;
	void display(std::ostream& os) const;
	~Student();
};

std::ostream& operator<<(std::ostream& os, Student& student);

#endif// _STUDENT_H_
