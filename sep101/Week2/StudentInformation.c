// StudentInformation.c - a program to store student information
//
#define _CRT_SECURE_NO_WARNINGS//get rid of compiler warnings regarding scanf()
#include <stdio.h>

int main(void)
{
	//"Watler": lastName[0]='W'
	//          lastName[1]='a'
	//          lastName[2]='t'
	//          lastName[3]='l'
	//          lastName[4]='e'
	//          lastName[5]='r'
	//          lastName[6]='\0'
	int studentId;
	char lastName[30];//up to 29 characters, plus the null terminator \0
	float mark1;
	float mark2;
	float mark3;

	printf("Enter the student's last name: ");
	scanf("%s", lastName);//lastName is the address of the top of the array
	                      //lastName by itself is already an address
	                      //If I wanted to change just the first
	                      //character in lastName, then scanf becomes
	                      //scanf("%c", &lastName[0]);
	printf("Enter the student's id number: ");
	scanf("%d", &studentId);
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
	scanf_s("%d", &studentId);
	printf("Enter the student's first mark: ");
	scanf_s("%f", &mark1);
	printf("Enter the student's second mark: ");
	scanf_s("%f", &mark2);
	printf("Enter the student's third mark: ");
	scanf_s("%f", &mark3);
*/
	printf("The student %s with id %d has marks of %f, %f, and %f\n",
		lastName, studentId, mark1, mark2, mark3);

	return 0;
}