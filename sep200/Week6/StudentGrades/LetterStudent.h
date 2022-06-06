//LetterStudent.h - class declaration for a letter student
//
// 07-Jun-22  M. Watler         Created

#ifndef _LETTERSTUDENT_H_
#define _LETTERSTUDENT_H_

#include "StudentBase.h"

template<class T>
class LetterStudent : public StudentBase<T> {
public:
	LetterStudent() {};
	LetterStudent(std::string _name) :StudentBase<T>(_name) {};
	void DetermineAverage() {
		double runningTotal = 0.0;
		T* mark = StudentBase<T>::GetMarks();
		int num = StudentBase<T>::GetNumMarks();
		for (int i = 0; i < num; ++i) {
			if (mark[i] == 'A') runningTotal += 4.0;
			else if (mark[i] == 'B') runningTotal += 3.0;
			else if (mark[i] == 'C') runningTotal += 2.0;
			else if (mark[i] == 'D') runningTotal += 1.0;
			else runningTotal += 0.0;
		}
		double ave = runningTotal / num;
		T letterAverage;
		if (ave >= 3.5) letterAverage = 'A';
		else if (ave >= 2.5) letterAverage = 'B';
		else if (ave >= 1.5) letterAverage = 'C';
		else if (ave >= 0.5) letterAverage = 'D';
		else letterAverage = 'F';
		StudentBase<T>::SetAverage(letterAverage);
	}
	void DetermineScholarship() {
		double funds;
		T ave = StudentBase<T>::GetAverage();
		if (ave == 'A') funds = 5000.0;
		else if (ave == 'B') funds = 1000.0;
		else funds = 0.0;
		StudentBase<T>::SetScholarship(funds);
	}
};

#endif// _LETTERSTUDENT_H_