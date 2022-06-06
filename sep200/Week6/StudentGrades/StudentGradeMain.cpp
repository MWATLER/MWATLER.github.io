//StudentGradeMain.cpp - main program for student grades
//
// 07-Jun-22  M. Watler         Created

#include "StudentGrade.h"

int main() {
	StudentGradeAdapter* studGrade = studentGrade();//call the factory function
	studGrade->run();
	delete studGrade;
	return 0;
}