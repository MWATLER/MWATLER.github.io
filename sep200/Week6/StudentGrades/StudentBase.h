//StudentBase.h - base class for students
//
// 07-Jun-22  M. Watler         Created

#ifndef _STUDENTBASE_H_
#define _STUDENTBASE_H_

#include <iostream>

//Put everything common between the two types of students here
template<class T>
class StudentBase {
	std::string name;
	int numMarks;
	T* marks;
	T average;
	double scholarship;
	void utilInit() {
		marks = nullptr;
		numMarks = 0;
		scholarship = 0.0;
	}
public:
	//Everything different about the two types of students are determined in their derived classes
	virtual void DetermineAverage() {};
	virtual void DetermineScholarship() {};
	StudentBase() {
		name = "";
		utilInit();
	}
	StudentBase(std::string _name) {
		name = _name;
		utilInit();
	}
	T* GetMarks() const {
		return marks;
	}
	int GetNumMarks() const {
		return numMarks;
	}
	void SetMarks(int num, T* _marks) {
		numMarks = num;
		delete[] marks;
		marks = new T[numMarks];
		for (int i = 0; i < numMarks; ++i) {
			marks[i] = _marks[i];
		}
	}
	std::string GetName() const {
		return name;
	}
	void SetName(std::string _name) {
		name = _name;
	}
	T GetAverage() const {
		return average;
	}
	void SetAverage(T _average) {
		average = _average;
	}
	double GetScholarship() const {
		return scholarship;
	}
	void SetScholarship(double amount) {
		scholarship = amount;
	}
	virtual ~StudentBase() {
		delete[] marks;
	}
};

#endif// _STUDENTBASE_H_