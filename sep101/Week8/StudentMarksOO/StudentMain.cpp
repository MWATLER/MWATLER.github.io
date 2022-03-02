//StudentMain.c - main function for student marks

#define _CRT_SECURE_NO_WARNINGS
#define NUM_STUDENTS 3
#include <stdio.h>
#include "Student.h"

int main(void) {
	int retVal = 0;
	Student student[NUM_STUDENTS];

	//gather information
	for (int i = 0; i < NUM_STUDENTS && retVal==0; ++i) {
		printf("Student's name: ");
		scanf("%[^\n]s", student[i].name);
		printf("Student's year: ");
		scanf("%d", &student[i].year);
		printf("Number of courses: ");
		scanf("%d", &student[i].numMarks);
		for (int j = 0; j < student[i].numMarks; ++j) {
			printf("Enter the mark for course %d : ", j+1);
			scanf("%d", &student[i].mark[j]);
		}
		printf("\n");
		while (getchar() != '\n');//clear the input buffer
		if (!student[i].CalculateAverage()) retVal = -1;
	}

	if (retVal == 0) {
		for (int i = 0; i < NUM_STUDENTS; ++i) {
			printf("The average for %s in year %d is %.2lf\n", student[i].name, student[i].year, student[i].average);
		}
		double average = CalculateOverallAverage(student, NUM_STUDENTS);
		printf("\nThe overall average for all students is %.2lf\n", average);
	}

	return retVal;
}
