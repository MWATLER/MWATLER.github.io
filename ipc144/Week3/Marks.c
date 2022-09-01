// Marks.c : This file contains the 'main' function. Program execution begins and ends there.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890

#define _CRT_SECURE_NO_WARNINGS//Get rid of warnings connected to scanf()
#include <stdio.h>

int main()
{
	//The following calculates your mark as a percent using double floating points
	double mark, totalMark, percent;//A variable to contain the mark, to contain full marks, and the percent
	printf("Enter your mark: ");
	scanf("%lf", &mark);
	printf("What was the test out of: ");
	scanf("%lf", &totalMark);
	percent = 100 * mark / totalMark;

	char letterGrade;//A variable to contain the letter grade
	if (percent >= 80) {
		letterGrade = 'A';
	}
	else if (percent >= 70 && percent < 80) {
		letterGrade = 'B';
	}
	else if (percent >= 60 && percent < 70) {
		letterGrade = 'C';
	}
	else if (percent >= 50 && percent < 60) {
		letterGrade = 'D';
	}
	else if (percent < 50) {
		letterGrade = 'F';
	}

	int honourStudent = percent >= 80 ? 1 : 0;//Is this student an honour student?
//	int honourStudent = letterGrade == 'A' ? 1 : 0;
	if(honourStudent == 1) printf("You are an honour student\n");

	printf("Your percent grade is %.2f and your letter grade is %c\n", percent, letterGrade);

	float scholarship;
	switch (letterGrade) {
	case 'A':
		scholarship = (7471.00+ 1450.00);//full tuition, books and supplies
		break;//Be sure to include break, otherwise the program
		      //will fall through to the next case!
	case 'B':
		scholarship = (7471.00 + 1450.00)/2.0;//half tuition, books and supplies
		break;
	case 'C':
		scholarship = 10.0;//5 coffees from Tim Hortons
		break;
	default:
		scholarship = 0.00;
	}

	if (scholarship > 0)
		printf("You have won a scholarship of $%.2f. Congratulations!\n",
			scholarship);
	return 0;
}