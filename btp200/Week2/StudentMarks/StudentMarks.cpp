//StudentMarks.cpp - main program for student information

#include "Student.h"

int main(void) {
	const int NO_STUDENTS = 3;
	Student student1;
	Student student2;
	Student student3;

/*	student1.enterInformation();
	student1.average();
	student1.displayInformation();
	student2.enterInformation();
	student2.average();
	student2.displayInformation();
	student3.enterInformation();
	student3.average();
	student3.displayInformation();*/

	Student* pStudent[NO_STUDENTS];
/*	Student* pStudent0 = &student1;//pStudent0 is the same as pStudent[0]
	Student* pStudent1 = &student2;
	Student* pStudent2 = &student3;*/
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