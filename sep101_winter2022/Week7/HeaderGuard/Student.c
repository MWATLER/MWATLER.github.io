//Student.c - main code for a student

#include "Common.h"
#include "Student.h"

int GetStudentInfo(struct StudentInfo* student) {
	printf("Enter the name: ");
	scanf_s("%s", student->name, MAX_STR);
	printf("Enter the age: ");
	scanf_s("%d", &student->age);
	return 0;//assume no errors
}
