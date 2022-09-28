//Student.c - main program for student information

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#include <stdio.h>
#include "StudentInfo.h"
#define NUM_STUDENTS 3

int main(void)
{
	struct StudentInfo student[NUM_STUDENTS];
//	struct StudentInfo {
//		char lastName[MAX_STR];
//		int studentId;
//		int marks[NUM_MARKS];
//		float average;
//		float scholarship;
//	};
	int runningTotal;

	int i;//control variable for the for-next loop
	for (i = 0; i < NUM_STUDENTS; ++i) {//for each student
		printf("Enter the student's last name: ");
		scanf_s("%s", student[i].lastName, MAX_STR);
		printf("Enter the student's id: ");
		scanf_s("%d", &student[i].studentId);
		int j;//control variable for the inside for-next loop
		runningTotal = 0;
		for (j = 0; j < NUM_MARKS; ++j) {//each mark for each student
			printf("Enter mark %d for %s: ", j + 1, student[i].lastName);
			scanf_s("%d", &student[i].marks[j]);//i - index into the student array,
			runningTotal += student[i].marks[j];//j - index into the marks array.
		}
		student[i].average = (float)runningTotal / NUM_MARKS;
		if (student[i].average >= 80) {
			student[i].scholarship = 5000.00;
		}
		else if (student[i].average >= 70) {
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
		printf("%-10s has an average of %.2f and a scholarship of $%.2f\n",//%-10s means left-justify the printout
			student[i].lastName, student[i].average, student[i].scholarship);
	}

	runningTotal = 0;
	for (i = 0; i < NUM_STUDENTS; ++i) {
		runningTotal += student[i].marks[2];//The third mark for each student
	}
	float ave = (float)runningTotal / NUM_STUDENTS;
	printf("\nThe average for class 3 is %.2f\n", ave);

	return 0;
}