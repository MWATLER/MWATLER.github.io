//Lab2Sample.c - sample code for lab 2

#include <stdio.h>

#define NUM 5//NUM is defined as a constant with value 5

int main() {
	int marks[NUM];//Example: 60, 56, 77, 92, 81
	int runningTotal = 0;
	const int LowestPossibleMark = 0;
	const int HighestPossibleMark = 100;
	int highestMark = LowestPossibleMark;
	int lowestMark = HighestPossibleMark;
	int indexHighestMark = 0;//should be 3
	int indexLowestMark = 0;//should be 1
	int validEntry = 0;//a flag variable, which makes the code more readable

	for (int i = 0; i < NUM; ++i) {//i=0,1,2,3,4
		do {//validate the mark
			printf("Enter mark %d: ", i + 1);
			//if i is 0, the user will see:
			//Enter mark 1:
			scanf_s("%d", &marks[i]);//if i=0, &marks[0]
			if (marks[i]<LowestPossibleMark ||
				marks[i]>HighestPossibleMark) {
				validEntry = 0;
				printf("Invalid entry: The marks have to be between 0 and 100\n");
			}
			else {
				validEntry = 1;
			}
		} while (validEntry == 0);

		//Example: 60, 56, 77, 92, 81
		runningTotal += marks[i];//to calculate the average
		if (marks[i] > highestMark) {//the highest mark
			highestMark = marks[i];
			indexHighestMark = i;//the index into the array that the highest mark occurs
		}
		if (marks[i] < lowestMark) {//the lowest mark
			lowestMark = marks[i];
			indexLowestMark = i;//the index into the array that the lowest mark occurs
		}
	}

//	float averageMark = runningTotal / NUM;//Both are integers, the compiler will throw away everything after the decimal place
	float averageMark = (float)runningTotal / NUM;//cast to a float to preserve everything after the decimal place

	printf("\n");
	printf("The average mark is %.2f.\n", averageMark);
	printf("The highest mark was %d and this was mark %d.\n",
		highestMark, indexHighestMark + 1);
	printf("The lowest mark was %d and this was mark %d.\n",
		lowestMark, indexLowestMark + 1);

	return 0;
}