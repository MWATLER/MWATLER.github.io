//NumberStudent.h - class declaration for a number student
//
// 07-Jun-22  M. Watler         Created

#ifndef _NUMBERSTUDENT_H_
#define _NUMBERSTUDENT_H_

#include "StudentBase.h"

template<class T>
class NumberStudent : public StudentBase<T> {
public:
	NumberStudent() {};
	NumberStudent(std::string _name) :StudentBase<T>(_name) {};
	void DetermineAverage() {
		double runningTotal = 0;
		T* mark = StudentBase<T>::GetMarks();
		int num = StudentBase<T>::GetNumMarks();
		for (int i = 0; i < num; ++i) {
			runningTotal += mark[i];
		}
		StudentBase<T>::SetAverage(static_cast<T>(runningTotal / num));
	}
	void DetermineScholarship() {
		double funds;
		double ave = StudentBase<T>::GetAverage();
		if (ave >= 80) funds = 5000.0;
		else if (ave >= 70) funds = 1000.0;
		else funds = 0.0;
		StudentBase<T>::SetScholarship(funds);
	}
};

#endif// _NUMBERSTUDENT_H_