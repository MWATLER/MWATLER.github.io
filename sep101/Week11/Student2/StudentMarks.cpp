//StudentMarks.cpp - main program for student information

#include "Student.h"

int main(void) {
	const int NO_STUDENTS = 3;

	Student* pStudent[NO_STUDENTS];
	//Allocating memory for three students
	pStudent[0] = new Student();//object1
	pStudent[1] = new Student();//object2
	pStudent[2] = new Student();//object3

	for (int i = 0; i < NO_STUDENTS; ++i) {
		pStudent[i]->enterInformation();
		pStudent[i]->average();
		pStudent[i]->displayInformation();
	}

	//Deallocating memory for three students
	for (int i = 0; i < NO_STUDENTS; ++i) {
		delete pStudent[i];
		pStudent[i] = nullptr;
	}

	return 0;
}