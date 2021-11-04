//Student.h - class declaration for a student

#include <iostream>

class Student {
	std::string name;
	double average;
public:
	Student(std::string _name, double ave);
	double GetAverage() const;
	void DisplayInfo()const;
};

bool compare(Student& student1, Student& student2);