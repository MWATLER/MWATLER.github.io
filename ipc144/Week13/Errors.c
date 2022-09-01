#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ReturnGrade(const double mark);

int main(void) {
	double markInPercent;
	do {
		printf("Enter your mark in percent (enter -1 to quit): ");
		scanf("%lf", markInPercent);
		if (markInPercent >= '0') {
			char grade[] = ReturnGrade(markInPercent);
			switch (grade) {
			case 'A':
				printf("You got an A. You win a scholarship of $5000\n");
			case 'B':
				printf("You got a B. You win a scholarship of $1000\n");
			case 'C':
			case 'D'://fall-through
				printf("You got a %c. You passed\n", grade);
				break;
			case 'F':
				printf("You have failed.\n");
			}
			printf("\n");
		}
	} while (markInPercent >= 0);
}

char ReturnGrade(const double mark) {
	char grade;
	mark += 2;//One lab was not fair, add 2 percent to each mark
	if (mark >= 80) grade = 'A';
	else if (mark >= 70) grade = 'B';
	else if (mark >= 60) grade = 'C';
	else if (mark >= 50) grade = 'D';
	else grade = 'F';

	return grade;
}

/* WORKING VERSION */
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char ReturnGrade(double mark);

int main(void) {
	double markInPercent;
	do {
		printf("Enter your mark in percent (enter -1 to quit): ");
		scanf("%lf", &markInPercent);
		if (markInPercent >= 0) {
			char grade = ReturnGrade(markInPercent);
			switch (grade) {
			case 'A':
				printf("You got an A. You win a scholarship of $5000\n");
				break;
			case 'B':
				printf("You got a B. You win a scholarship of $1000\n");
				break;
			case 'C':
			case 'D'://fall-through
				printf("You got a %c. You passed\n", grade);
				break;
			case 'F':
				printf("You have failed.\n");
			}
			printf("\n");
		}
	} while (markInPercent >= 0);
}

char ReturnGrade(double mark) {
	char grade;
	mark += 2;//One lab was not fair, add 2 percent to each mark
	if (mark >= 80) grade = 'A';
	else if (mark >= 70) grade = 'B';
	else if (mark >= 60) grade = 'C';
	else if (mark >= 50) grade = 'D';
	else grade = 'F';

	return grade;
}*/