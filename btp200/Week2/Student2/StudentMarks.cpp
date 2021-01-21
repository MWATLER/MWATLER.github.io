//StudentMarks.cpp - main program for student information

#include "Student.h"

int main(void) {
	const int NO_STUDENTS = 3;
	//Not needed:
	//Student student1;
	//Student student2;
	//Student student3;

	Student* pStudent[NO_STUDENTS];
//	for (int i = 0; i < NO_STUDENTS; ++i) {
//		pStudent[i] = new Student();
//	}
	pStudent[0] = new Student();
	pStudent[1] = new Student();
	pStudent[2] = new Student();

	for (int i = 0; i < NO_STUDENTS; ++i) {
		pStudent[i]->enterInformation();
		pStudent[i]->average();
		pStudent[i]->displayInformation();
	}

	for (int i = 0; i < NO_STUDENTS; ++i) {
		delete pStudent[i];
		pStudent[i] = nullptr;//optional
	}
//	if (pStudent[0] == nullptr) {
		//if this is true, I know that pStudent is no longer
		//pointing to something in memory
//	}
	//Structured programming - one entry spot, one exit spot, so cleanup
	//                         can occur before you return from a function
	return 0;
}