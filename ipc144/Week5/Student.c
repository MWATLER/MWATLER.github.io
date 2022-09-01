//Student.c - main program for student information

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "StudentInfo.h"
#define NUM_STUDENTS 3

int main(void)
{
	struct StudentInfo student[NUM_STUDENTS];//defines an array of type struct StudentInfo
	int runningTotal;

	int i;//control variable for the for-next loop
	for (i = 0; i < NUM_STUDENTS; ++i) {//Loop through all students
		printf("Enter the student's last name: ");
		scanf("%s", student[i].lastName);
		printf("Enter the student's id: ");
		scanf("%d", &student[i].studentId);
		int j;//control variable for the inside for-next loop
		runningTotal = 0;
		for (j = 0; j < NUM_MARKS; ++j) {//Loop through all marks of one student
			printf("Enter mark %d for %s: ", j + 1, student[i].lastName);
			scanf("%d", &student[i].marks[j]);
			runningTotal += student[i].marks[j];
		}
		student[i].average = (float)runningTotal / NUM_MARKS;
		if (student[i].average > 80) {
			student[i].scholarship = 5000.00;
		}
		else if (student[i].average > 70) {
			student[i].scholarship = 2500.00;
		}
		else {
			student[i].scholarship = 0.00;
		}
		printf("\n");
	}

	printf("\n");
	printf("Here is the list of students, their averages and scholarships\n");
	for (i = 0; i < NUM_STUDENTS; ++i) {
		printf("%-10s has an average of %.2f and a scholarship of $%.2f\n", student[i].lastName, student[i].average, student[i].scholarship);
	}

	return 0;
}