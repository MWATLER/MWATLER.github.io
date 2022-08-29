//InfoMain.c - main program for student and teacher information

#include "Student.h"
#include "Teacher.h"
#include "Common.h"

int main() {
	int retVal = 0;
	struct StudentInfo student1 = { 0 };
	struct TeacherInfo teacher1 = { 0 };

	retVal=GetStudentInfo(&student1);
	if (retVal == 0) {
		retVal = GetTeacherInfo(&teacher1);
	}

	if (retVal == 0) {
		printf("%s is %d years old.\n", student1.name, student1.age);
		printf("%s earns $%.2lf per year.\n", teacher1.name, teacher1.salary);
	}
	else {
		PrintError();
	}

	return retVal;
}