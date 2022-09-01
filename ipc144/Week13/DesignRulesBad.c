//DesignRulesBad.c - Some code to demonstrate design rules

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define Maxsize 5

int main(void)
{
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY
	int ans;
	int maxsize;
	int numbers[Maxsize];
	int runningTotal;
	int i;
	int retVal=0;

	do {
		printf("Math features: 1. Calculate the average of up to %d integers\n", Maxsize);
		printf("               2. Calculate the square\n");
		printf("Choose a feature: ");
		scanf("%d%*c", &ans);
	} while (ans != 1 && ans != 2);
	printf("\n");

	if (ans == 1) {
		do {
			printf("How many numbers: ");
			scanf("%d%*c", &maxsize);
		} while (maxsize < 0 || maxsize > Maxsize);

		runningTotal = 0;
		for (i = 0; i < maxsize; ++i) {
		printf("Enter number %d: ", i + 1);
		scanf("%d%*c", &numbers[i]);
		runningTotal += numbers[i];
		}
		printf("\n");
		printf("The average is %.2f\n", (float)runningTotal / maxsize);
		retVal = 0;
		return retVal;
	}
	else if (ans == 2) {
		printf("Feature unavailable.\n");
		retVal = -1;
		return retVal;
	}

	return retVal;
}
