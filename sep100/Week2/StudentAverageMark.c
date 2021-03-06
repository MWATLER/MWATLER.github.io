// StudentAverageMark.c - a program to store student information and 
//                        calculate the student's average mark.
//
#define _CRT_SECURE_NO_WARNINGS//get rid of compiler warning regarding scanf()
#include <stdio.h>

int main(void)
{
	int student_id;
	char lastName[30];
	float mark1;
	float mark2;
	float mark3;
	double runningTotal = 0;
	double averageMark;
	int numMarks = 3;

	printf("Enter the student's last name: ");
	scanf("%s", lastName);
	printf("Enter the student's id number: ");
	scanf("%d", &student_id);
	printf("Enter the student's first mark: ");
	scanf("%f", &mark1);
	runningTotal += mark1;
	printf("Enter the student's second mark: ");
	scanf("%f", &mark2);
	runningTotal += mark2;
	printf("Enter the student's third mark: ");
	scanf("%f", &mark3);
	runningTotal += mark3;
	averageMark = runningTotal / numMarks;

	printf("The student %s with id %d has marks of %f, %f, and %f\n", lastName, student_id, mark1, mark2, mark3);
	printf("%s has an average mark of %lf\n", lastName, averageMark);

	return 0;
}