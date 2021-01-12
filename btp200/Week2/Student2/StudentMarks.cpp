//StudentMarks.cpp - main program for student information

#include "Student.h"

int main(void) {
	const int NO_STUDENTS = 3;

	Student* pStudent[NO_STUDENTS];
	pStudent[0] = new Student();
	pStudent[1] = new Student();
	pStudent[2] = new Student();

	for (int i = 0; i < NO_STUDENTS; ++i) {
		pStudent[i]->enterInformation();
		pStudent[i]->average();
		pStudent[i]->displayInformation();
	}

	for (int i = 0; i < NO_STUDENTS; ++i) delete pStudent[i];

	return 0;
}