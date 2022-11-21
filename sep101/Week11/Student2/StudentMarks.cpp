//StudentMarks.cpp - main program for student information

#include "Student.h"

int main(void) {
	const int NO_STUDENTS = 3;

	Student* pStudent[NO_STUDENTS];//this is an array of pointers. The pointers are
	                               //contiguous in memory, but what they point to are not
	pStudent[0] = new Student();
	pStudent[1] = new Student();
	pStudent[2] = new Student();

	for (int i = 0; i < NO_STUDENTS; ++i) {
		pStudent[i]->enterInformation();
		pStudent[i]->average();
		pStudent[i]->displayInformation();
	}

	for (int i = 0; i < NO_STUDENTS; ++i) {
		//delete them one by one, because the Student
		//objects are not contiguous in memory
		delete pStudent[i];
		pStudent[i] = nullptr;
	}
//	delete[] pStudent;//error, the array of pointers were statically allocated,
	                  //therefore will be deleted once the program has ended.

	return 0;
}