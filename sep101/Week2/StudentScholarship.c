// StudentScholarship.c - a program to store student information, calculate the student's average mark,
//                        convert each mark into a letter grade, and express the average mark as a letter grade.
//                        The program will also determine whether the student receives a scholarship, and if so, how much.
//
#include <stdio.h>

int main(void)
{
	int student_id;
	char lastName[30];
	float mark1;
	float mark2;
	float mark3;
	char letterGrade1;
	char letterGrade2;
	char letterGrade3;
	double runningTotal = 0;
	double averageMark;
	int numMarks = 3;
	char letterAverage;
	float scholarship;

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

	if (averageMark >= 80) letterAverage = 'A';
	else if (averageMark >= 70) letterAverage = 'B';
	else if (averageMark >= 60) letterAverage = 'C';
	else if (averageMark >= 50) letterAverage = 'D';
	else                  letterAverage = 'F';

	printf("The student %s with id %d has marks of %c, %c, and %c.\n",
		lastName, student_id, letterGrade1, letterGrade2, letterGrade3);
	if (letterAverage == 'A') {
		printf("%s is an A student.\n\n", lastName);
	}
	else {
		printf("%s is a %c student.\n\n", lastName, letterAverage);
	}
	
	switch (letterAverage) {//We have a specific letter average
		                    //It could be 'A', 'B', 'C', 'D', or 'F'
	case 'A'://The case for an A student
		scholarship = 5000.00;
		break;//Don't forget the break
		//There are cases where you want to fall through from
		//one case to another. In such an instance, add a comment:
		//fall-through
	case 'B'://The case for a B student
		scholarship = 2000.00;
		break;
	case 'C'://The case for a C student
		scholarship = 500.00;
		break;
	default://All other cases are handled here
		scholarship = 0.0;
	}

	if (scholarship > 0) {
		printf("%s wins a scholarship of %f.\n", lastName, scholarship);
	}
	else {
		printf("%s does not receive a scholarship.\n", lastName);
	}


	return 0;
}