//LetterStudent.cpp - function definitions for a letter student

#include "LetterStudent.h"

using namespace std;

LetterStudent::LetterStudent(std::string _name, int _number, const int* _marks, int _numMarks) :
Student(_name, _number, _marks, _numMarks){

}

char LetterStudent::GetLetterGrade(const double mark) const {//private utility function
	char letterGrade;
	if (mark >= 80.0) letterGrade = 'A';
	else if (mark >= 70.0) letterGrade = 'B';
	else if (mark >= 60.0) letterGrade = 'C';
	else if (mark >= 50.0) letterGrade = 'D';
	else letterGrade = 'F';

	return letterGrade;
}

char LetterStudent::GetAverage() const {
	double average = Student::GetAverage();//get the average as a percentage
	char letterAverage = GetLetterGrade(average);

	return letterAverage;
}

void LetterStudent::display(std::ostream& os) const {
	int* marks = Student::GetMarks();
	int numMarks = Student::GetNumMarks();
	Student::display(os);
	os << "In terms of letter grades, the marks are:";
	for (int i = 0; i < numMarks; ++i) {
		char letterGrade = GetLetterGrade((double)marks[i]);
		os << " " << letterGrade;
	}
	os << endl;
	os << Student::GetName() << " is a(n) " << GetAverage() << " student." << endl;
}

LetterStudent::~LetterStudent() {

}

std::ostream& operator<<(std::ostream& os, LetterStudent& student) {
	student.display(os);
	return os;
}
