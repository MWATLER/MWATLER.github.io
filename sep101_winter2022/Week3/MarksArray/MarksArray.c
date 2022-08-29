// MarksArray.c : A simple program to calculate average mark with arrays
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM_MARKS 6
#define BUF_LEN 20

int main()
{
	int mark[NUM_MARKS] = { 0 };//initializing my array to 0
	char name[BUF_LEN];//A string of characters
	int runningTotal = 0;//for calculating averages
	int invalidEntry;//invalid entry flag
	int highestMark = 0;//the highest mark
	int indexHighestMark = 0;//index into the array for the highest mark
	float average;

	printf("Enter your name: ");
	scanf_s("%s", name, BUF_LEN);
	for (int i = 0; i < NUM_MARKS; ++i)
	{
		do {
			printf("Enter the mark for course %d: ", i + 1);
			scanf_s("%d", &mark[i]);//if i=0, scan to mark[0]
			if (mark[i] < 0 || mark[i]>100) {
				invalidEntry = 1;
				printf("Invalid entry. Try again...\n");
			}
			else {
				invalidEntry = 0;
			}
		} while (invalidEntry == 1);
		runningTotal = runningTotal + mark[i];
		if (mark[i] > highestMark) {
			highestMark = mark[i];
			indexHighestMark = i;
		}
	}//i only increments here
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
