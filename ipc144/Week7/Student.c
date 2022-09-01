//Student.c - main program for student information
//            This program demonstrates memory allocation when the number
//            of students is not known until run-time.
//            It also demonstrates an initialization block within a for-loop
//            and a completion block within a for-loop. This is good structured
//            programming, where the loop has one entry-point and one exit-point.
//            We are always guaranteed that the memory created in the initialization
//            block will be deleted in the completion block

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "StudentInfo.h"

int main(void)
{
	int isInitialized = 0;//Initialization flag
	int isDone = 0;//Completion flag
	struct StudentInfo* student=NULL;//pointer to an array of students
	int i;//control variable for the for-loop
	int runningTotal;//To calculate the average
	int numStudents;//To calculate the average

	printf("Enter the number of students: ");
	scanf("%d", &numStudents);
	printf("\n");
	for (i = 0; i < numStudents; ++i) {//for each student
		if (isInitialized == 0) {//Initialization block
			//Allocate memory for the given number of students
            //This is how you create an array when you don't know how big it is until runtime.
			student = (struct StudentInfo *)malloc(numStudents * sizeof(struct StudentInfo));
			isInitialized = 1;
		}
		printf("Enter the student's last name (enter 0 to quit prematurely): ");
		scanf("%s", student[i].lastName);
		if (student[i].lastName[0] == '0') {
			isDone = 1;//End prematurely
			numStudents = i;//Note the actual number of students
		}
		else {
			printf("Enter the student's id: ");
			scanf("%d", &student[i].studentId);
			int j;//control variable for the inside for-next loop
			runningTotal = 0;
			for (j = 0; j < NUM_MARKS; ++j) {//each mark for each student
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
			if (i == (numStudents - 1)) isDone = 1;//This was the last student
		}
		if (isDone==1) {//Completion block
			printf("\n");
			printf("Here is the list of students, their averages and scholarships\n");
			for (i = 0; i < numStudents; ++i) {
				printf("%-10s has an average of %.2f and a scholarship of $%.2f\n",
					student[i].lastName, student[i].average, student[i].scholarship);
			}
			free(student);
		}
	}

	return 0;
}