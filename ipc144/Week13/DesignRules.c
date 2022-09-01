//DesignRules.c - Some code to demonstrate design rules

//General comments should be at the top
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXSIZE 5//Define should be in capitals

int main(void)
{
	int ans;
	int size;//The variable name should not differ in case only to another variable name
	int numbers[MAXSIZE];
	int runningTotal;
	int i;
	int retVal = 0;

	do {
		printf("Math features: 1. Calculate the average of up to %d integers\n", MAXSIZE);
		printf("               2. Calculate the square\n");
		printf("Choose a feature: ");
		scanf("%d%*c", &ans);
	} while (ans != 1 && ans != 2);
	printf("\n");

	if (ans == 1) {
		do {
			printf("How many numbers: ");
			scanf("%d%*c", &size);
		} while (size < 0 || size > MAXSIZE);

		runningTotal = 0;
		for (i = 0; i < size; ++i) {//Indent code inside a for-loop
			printf("Enter number %d: ", i+1);
			scanf("%d%*c", &numbers[i]);
			runningTotal += numbers[i];
		}
		printf("\n");
		printf("The average is %.2f\n", (float)runningTotal/size);
		retVal = 0;//Do not return here
	}
	else if (ans == 2) {
		printf("Feature unavailable.\n");
		retVal = -1;//Do not return here
	}

	return retVal;//Return here
}