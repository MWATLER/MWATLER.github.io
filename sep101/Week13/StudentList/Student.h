//Student.h - class declaration for a student

#include<iostream>

#ifndef _STUDENT_H_
#define _STUDENT_H_

class Student {
	std::string name;
	double* marks;//Dynamic memory allocation. We don't know how many subjects the student
	              //has taken until we run the program. We allocate memory once we know.
	int numMarks;
	double average;
	int rank;
public:
	Student();
	bool CalculateAverage();
	double GetAverage() const {
		return average;
	}
	void SetName(std::string name) {
		this->name = name;
	}
	std::string GetName() const {//this function is not allowed to change anything inside the class
		return name;
	}
	void SetMarks(double*, int);
	double* GetMarks() const;
	int GetNumMarks() const;
	void IncrementRank();
	int GetRank() const;
	~Student();
};

#endif//_STUDENT_H_