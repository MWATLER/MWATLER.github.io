// MarksArray.cpp : A simple program to calculate average mark with arrays
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_MARKS 6

int main()
{
	int mark[NUM_MARKS] = { 0 };
	char name[20];//A string of characters
	int runningTotal = 0;
	int invalidEntry;
	int highestMark = 0;
	int indexHighestMark = 0;
	float average;

	printf("Enter your name: ");
	scanf("%s", name);
	for (int i = 0; i < NUM_MARKS; ++i)
	{
		do {
			printf("Enter the mark for course %d: ", i + 1);
			scanf("%d", &mark[i]);//if i=0, scan to mark[0]
			if (mark[i] < 0 || mark[i]>100) {
				invalidEntry = 1;
				printf("Invalid entry. Try again...\n");
			} else {
				invalidEntry = 0;
			}
		} while (invalidEntry == 1);
		runningTotal = runningTotal + mark[i];
		if (mark[i] > highestMark) {
			highestMark = mark[i];
			indexHighestMark = i;
		}
	}
	average = (float)runningTotal / NUM_MARKS;
	printf("%s your marks are:\n", name);
	for (int i = 0; i < NUM_MARKS; ++i) {
		printf("course %d mark:%d\n", i + 1, mark[i]);
		if (indexHighestMark == i)
			printf("--This course had the highest mark--\n");
	}
	printf("\nCourse %d had the highest mark which was %d\n",
		indexHighestMark + 1, mark[indexHighestMark]);
	printf("Your average mark was %.2f\n", average);

	return 0;
}
