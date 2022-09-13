// StudentLetterGrade.c - a program to store student information, calculate the student's average mark,
//                        convert each mark into a letter grade, and express the average mark as a letter grade.
//
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
	const int numMarks = 3;
	char letterGrade1;
	char letterGrade2;
	char letterGrade3;
	char letterAverage;

	printf("Enter the student's last name: ");
	scanf_s("%s", lastName, 30);
	printf("Enter the student's id number: ");
	scanf_s("%d", &student_id);
	printf("Enter the student's first mark: ");
	scanf_s("%f", &mark1);
	runningTotal += mark1;
	printf("Enter the student's second mark: ");
	scanf_s("%f", &mark2);
	runningTotal += mark2;
	printf("Enter the student's third mark: ");
	scanf_s("%f", &mark3);
	runningTotal += mark3;
	averageMark = runningTotal / numMarks;

	printf("The student %s with id %d has marks of %f, %f, and %f\n", 
		lastName, student_id, mark1, mark2, mark3);
	printf("%s has an average mark of %lf\n", lastName, averageMark);

	if (mark1 >= 80) letterGrade1 = 'A';
	else if (mark1 >= 70) letterGrade1 = 'B';
	else if (mark1 >= 60) letterGrade1 = 'C';
	else if (mark1 >= 50) letterGrade1 = 'D';
	else                  letterGrade1 = 'F';

	if (mark2 >= 80) letterGrade2 = 'A';
	else if (mark2 >= 70) letterGrade2 = 'B';
	else if (mark2 >= 60) letterGrade2 = 'C';
	else if (mark2 >= 50) letterGrade2 = 'D';
	else                  letterGrade2 = 'F';

	if (mark3 >= 80) letterGrade3 = 'A';
	else if (mark3 >= 70) letterGrade3 = 'B';
	else if (mark3 >= 60) letterGrade3 = 'C';
	else if (mark3 >= 50) letterGrade3 = 'D';
	else                  letterGrade3 = 'F';

	if (averageMark >= 80) {
		letterAverage = 'A';
	}
	else if (averageMark >= 70) {
		letterAverage = 'B';
	}
	else if (averageMark >= 60) {
		letterAverage = 'C';
	}
	else if (averageMark >= 50) {
		letterAverage = 'D';
	}
	else {
		letterAverage = 'F';
	}
	printf("The student %s with id %d has marks of %c, %c, and %c.\n",
		lastName, student_id, letterGrade1, letterGrade2, letterGrade3);
	printf("%s is a %c student.\n", lastName, letterAverage);

	return 0;
}