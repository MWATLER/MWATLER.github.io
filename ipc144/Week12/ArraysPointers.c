// ArraysPointers.c : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double calcAverage(const int *m, int num);
//double calcAverage(int m[], int num);
double calcAverageMask(const int m[], int num, const int mask[]);

int main()
{
	int num;
	int marks[5];
	printf("Enter the number of students: ");
	scanf("%d", &num);

	int *pNum = &num;//The address of num
	int *pMarks = marks;//marks is already an address
//	int *pMarks = &marks[0];//Address of the first value of marks
	++(*pNum);//effectively increments num

	printf("The address of num is %p and of pNum is %p\n", &num, pNum);
	printf("The address of marks is %p and of pMarks is %p\n", marks, pMarks);

	printf("The number of students is now %d\n\n", num);
	for (int i = 0; i < num; ++i) {
		printf("Enter mark %d: ", i+1);
		scanf("%d", &pMarks[i]);//&marks[0], &marks[1],...
//		scanf("%d", pMarks);
//   	++pMarks;//marks[1], marks[2], etc...
	}

	printf("The marks are: ");
	for (int i = 0; i < num; ++i) printf(" %d", marks[i]);
	printf("\n\n");
	double average = calcAverage(marks, num);//marks = &marks[0]
	printf("The average mark is %.2lf\n\n", average);

	int mask[5] = { 1, 0, 1, 1, 1 };
	average = calcAverageMask(marks, num, mask);
	printf("The masked average mark is %.2lf\n\n", average);
	return 0;
}

double calcAverage(const int *m, int num) {//int *m = &marks[0]
//double calcAverage(int m[], int num) {
	int runningTotal = 0;
	for (int i = 0; i < num; ++i) {
		runningTotal += m[i];
	}

	return (double)runningTotal / num;
}

double calcAverageMask(const int m[], int num, const int mask[]) {
	int runningTotal = 0;
	int count = 0;
	for (int i = 0; i < num; ++i) {
		if (mask[i] == 1) {//mask[1]=0
			runningTotal += m[i];
			++count;
		}
	}

	return (double)runningTotal / count;
}
