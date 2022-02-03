//LetterStudent.h - class declaration for a letter student

#ifndef _LETTERSTUDENT_H_
#define _LETTERSTUDENT_H_

#include <iostream>
#include "Student.h"

class LetterStudent : public Student {
	char GetLetterGrade(double mark) const;
public:
	LetterStudent(std::string _name, int _number, int* _marks, int _numMarks);
	char GetAverage() const;
	void display(std::ostream& os) const;
	~LetterStudent();
};

std::ostream& operator<<(std::ostream& os, LetterStudent& student);

#endif// _LETTERSTUDENT_H_