//Student.h - class declaration for a student

#include<iostream>

#ifndef _STUDENT_H_
#define _STUDENT_H_

class Student {
	std::string name;
	double* marks;
	int numMarks;
	double average;
	int rank;
public:
	Student();
	bool CalculateAverage();
	double GetAverage() const;
	void SetName(std::string);
	std::string GetName() const;
	void SetMarks(double*, int);
	double* GetMarks() const;
	int GetNumMarks() const;
	void IncrementRank();
	int GetRank() const;
	~Student();
};

#endif//_STUDENT_H_