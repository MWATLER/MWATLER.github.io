//Define.c - A simple program to demonstrate defines and input validation

//Miguel Watler
//miguel.watler@senecacollege.ca
//0123456789
//Section XXY

#define NUMS 5//Same as const int NUMS=5;
              //Note that defines are always in CAPITAL
#define _CRT_SECURE_NO_WARNINGS//Ignore warnings due to scanf()

#include <stdio.h>

int main(void)
{
	int runningTotal;//Used to calculate the average
	int count;
	int number;//The current number
	int isInvalid;//flag for invalid numbers

	runningTotal = 0;
	for (count = 0; count < NUMS; ++count) {
		do {//The validation loop
			printf("Enter a number between -100 and 100 (count=%d): ", count);
			scanf("%d", &number);
			isInvalid = (number < -100 || number>100);//Validate the entry
			if (isInvalid == 1) printf("ERROR: invalid number, enter again\n");
		} while (isInvalid == 1);//If the entry is invalid, prompt the user to enter a number again
		runningTotal += number;//Once the entry has been validated, add it to runningTotal
		//NOTE: The for-next loop increments count at the very end of the loop
	}
	printf("\nrunningTotal=%d count=%d\n", runningTotal, count);
	float average = (float)runningTotal / count;//Cast to float in order to retain the numbers after the decimal point
	printf("The average of %d numbers is %.2f\n", count, average);

	return 0;
}
