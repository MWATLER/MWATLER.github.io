// StudentInformation.c - a program to store student information
//
#define _CRT_SECURE_NO_WARNINGS//get rid of compiler warnings regarding scanf()
#include <stdio.h>

int main(void)
{
	int student_id;
	char lastName[30];//an array of 30 characters to store the last name.
	float mark1;
	float mark2;
	float mark3;

	printf("Enter the student's last name: ");
	scanf("%s", lastName);//no apersand necessary, because the name of the array is the address
	                      //lastName by itself is actually an address
	printf("Enter the student's id number: ");
	scanf("%d", &student_id);
	printf("Enter the student's first mark: ");
	scanf("%f", &mark1);
	printf("Enter the student's second mark: ");
	scanf("%f", &mark2);
	printf("Enter the student's third mark: ");
	scanf("%f", &mark3);

/* scanf_s() is now the preferable way to scan data from the keyboard */
/*	printf("Enter the student's last name: ");
	scanf_s("%s", lastName, 30);
	printf("Enter the student's id number: ");
	scanf_s("%d", &student_id);
	printf("Enter the student's first mark: ");
	scanf_s("%f", &mark1);
	printf("Enter the student's second mark: ");
	scanf_s("%f", &mark2);
	printf("Enter the student's third mark: ");
	scanf_s("%f", &mark3);
*/
	printf("The student %s with id %d has marks of %f, %f, and %f\n", 
		lastName, student_id, mark1, mark2, mark3);

	return 0;
}