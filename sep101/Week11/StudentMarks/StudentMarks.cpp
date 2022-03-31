//StudentMarks.cpp - main program for student information

#include "Student.h"

int main(void) {
	const int NO_STUDENTS = 3;
	Student student1;
	Student student2;
	Student student3;

	Student* pStudent[NO_STUDENTS];
	pStudent[0] = &student1;
	pStudent[1] = &student2;
	pStudent[2] = &student3;

	for (int i = 0; i < NO_STUDENTS; ++i) {
		pStudent[i]->enterInformation();
		pStudent[i]->average();
		pStudent[i]->displayInformation();
	}

	return 0;
}