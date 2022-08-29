//Teacher.c - main code for a teacher

#include "Common.h"
#include "Teacher.h"

int GetTeacherInfo(struct TeacherInfo* teacher) {
	printf("Enter the name: ");
	scanf_s("%s", teacher->name, MAX_STR);
	printf("Enter the salary: $");
	scanf_s("%lf", &teacher->salary);
	return 0;//assume no errors
}
