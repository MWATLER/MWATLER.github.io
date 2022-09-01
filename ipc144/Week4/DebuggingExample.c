// DebuggingExample.c : A simple program to demonstrate debugging techniques
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	int runningTotal, value, count;

	runningTotal = 0;
	count = 0;
	do {
		printf("Enter a value (0 to stop) ");
		scanf("%d", &value);
		if (value < 0) {//Convert negative values to positive ones
			value = value * (-1);
			runningTotal += value;
			count++;
		}
		else if (value > 0) {
			runningTotal += value;
			count++;
		}
	} while (value != 0);
	if (count > 0) {
		printf("The average value is %.2lf\n",
			(double)runningTotal / count);
	}

	return 0;
 }