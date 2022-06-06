//StudentGrade.h
//
// 06-Jun-22  M. Watler         Created

#ifndef _STUDENTGRADE_H_
#define _STUDENTGRADE_H_

#include <iostream>
#include "StudentGradeAdapter.h"
#include "NumberStudent.h"
#include "LetterStudent.h"

template<typename T>
class StudentGrade : public StudentGradeAdapter {
	StudentBase<T>* student;
public:
	StudentGrade(GradeMode mode, std::string name) {
		if (mode == GradeMode::letterGrade)
			student = new LetterStudent<T>(name);
		else
			student = new NumberStudent<T>(name);
	}
	~StudentGrade() {
		delete student;
	}
	void run() {
			int num;
			T* mark;
			std::cout << "Enter the number of subjects for " << student->GetName() << " : ";
			std::cin >> num;
			mark = new T[num];
			for (int i = 0; i < num; ++i) {
				std::cout << "Enter mark " << (i + 1) << " for " << student->GetName() << " ";
				std::cin >> mark[i];
			}
			student->SetMarks(num, mark);
			student->DetermineAverage();
			student->DetermineScholarship();
			std::cout << student->GetName() << " has an average of " << student->GetAverage() << " and a scholarship of $" << student->GetScholarship() << std::endl << std::endl;
	}
};

StudentGradeAdapter* studentGrade() {
	std::string name;
	char grMode;
	std::cout << "What is the student's name? ";
	std::cin >> name;
	std::cout << "Will you enter marks as letters? [Y/N] ";
	std::cin >> grMode;

	StudentGradeAdapter* studentGr = nullptr;
	if (grMode == 'Y' || grMode == 'y') {
		studentGr = new StudentGrade<char>(GradeMode::letterGrade, name);//treat as a letter student
	}
	else {
		studentGr = new StudentGrade<double>(GradeMode::numberGrade, name);//treat as a number student
	}
	return studentGr;
}

#endif _STUDENTGRADE_H_