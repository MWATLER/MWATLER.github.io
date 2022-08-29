// DebuggingExample.c : A simple program to demonstrate debugging techniques
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#include<stdio.h>

int main(void)
{   //Add breakpoints in this code to trace the
	//values of value, count, and runningTotal
	//inside the do-while loop. Trace their values
	//at the end of the program as well.

	//Draw and fill a walkthrough table as well
	//for value, count, and runningTotal for a
	//sample run. Compare with the values traced
	//by the breakpoints in this code.
	int runningTotal, value, count;

	runningTotal = 0;
	count = 0;
	do {
		printf("Enter a value (0 to stop) ");
		scanf_s("%d", &value);
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