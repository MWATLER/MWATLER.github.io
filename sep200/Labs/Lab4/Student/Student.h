//Student.h - class declaration for a student

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>

class Student {
	std::string name;
	int number;
	int* marks;
	int numMarks;
protected:
	std::string GetName() const;
	int* GetMarks() const;
	int GetNumMarks() const;
	double GetAverage() const;
public:
	Student(std::string _name, int _number, const int* _marks, int _numMarks);
	virtual void display(std::ostream& os) const;//might be overridden in the derived classes
	virtual ~Student();//need to invoke the destructors in the derived classes as well
};

std::ostream& operator<<(std::ostream& os, Student& student);

#endif// _STUDENT_H_
