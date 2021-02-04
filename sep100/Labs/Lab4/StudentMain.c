//StudentMain.c - main function for student information

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "StudentInfo.h"

int main(void) {
	struct StudentInfo student;
	int numSubjects;

	InitializeInfo(&student);
	printf("Enter the student's last name: ");
	scanf("%s", student.lastName);
	printf("Enter the student's id: ");
	scanf("%d", &student.studentId);
	printf("Enter the number of subjects: ");
	scanf("%d", &numSubjects);
	for (int i = 0; i < numSubjects; ++i) {
		printf("Enter the name of subject %d: ", i+1);
		scanf("%s", student.subject[i].name);
		printf("Enter the mark for %s: ", student.subject[i].name);
		scanf("%d", &student.subject[i].mark);
	}
	float average = AverageMark(student.subject);
	int maxIndex = MaximumMark(student.subject);
	int minIndex = MinimumMark(student.subject);

	printf("\n");
	printf("%s with id %d has an average mark of %.2f.\n", student.lastName, student.studentId, average);
	printf("%s's highest mark was %d in %s.\n", student.lastName, student.subject[maxIndex].mark, student.subject[maxIndex].name);
	printf("%s's lowest mark was %d in %s.\n", student.lastName, student.subject[minIndex].mark, student.subject[minIndex].name);

	return 0;
}