// AverageMark.c : Three ways to calculate the average mark using loops.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//01234567890

#define _CRT_SECURE_NO_WARNINGS//Ignore warnings due to scanf()
#include <stdio.h>

int main()
{
	float mark;
	float runningTotal;
	int count;

	// The do-while loop
	runningTotal = 0;
	count = 0;
	do {//NOTE: do-while loops run at least once
		printf("Enter your mark: ");
		scanf("%f", &mark);
		runningTotal += mark;
		++count;
	} while (count < 3);//Test at the end
	float average = runningTotal / count;
	printf("do-while: Your average is %.1f%%\n\n",//%% prints out %
		average);

	// The while loop
	runningTotal = 0;
	count = 0;
	while (count < 3) {//Test at the beginning
		printf("Enter your mark: ");
		scanf("%f", &mark);
		//Curve all marks upwards by 10%
		mark = mark + mark * 0.10f;//Or mark += mark * .10
		if (mark > 100) {//mark cannot exceed 100%
			printf("Capping your mark at 100%%\n");
			mark = 100;
		}
		runningTotal += mark;
		++count;
	}
	printf("while: Your average is %.1f%%\n\n", runningTotal / count);

	//The following for-next loop is equivalent to the while loop above
	runningTotal = 0;
	for (count = 0; count < 3; ++count) {//Test at the beginning
		printf("Enter your mark: ");
		scanf("%f", &mark);
		//Curve all marks upwards by 10%
		mark = mark + mark * 0.10f;//Or mark += mark * .10
		if (mark > 100) {//mark cannot exceed 100%
			printf("Capping your mark at 100%%\n");
			mark = 100;
		}
		runningTotal += mark;
	}
	printf("for-next: Your average is %.1f%%\n\n",
		runningTotal / count);

	//This time validate the marks.
	runningTotal = 0;
	for (count = 0; count < 3; ++count) {//Test at the beginning
		do {//Validate the marks here
			printf("Enter your mark: ");
			scanf("%f", &mark);
			if (mark < 0 || mark>100) printf("Error: mark out of range.\n");
		} while (mark < 0 || mark>100);
		//Curve all marks upwards by 10%
		mark = mark + mark * 0.10f;//Or mark += mark * .10
		if (mark > 100) {//mark cannot exceed 100%
			printf("Capping your mark at 100%%\n");
			mark = 100;
		}
		runningTotal += mark;
	}
	printf("for-next: Your average is %.1f%%\n\n",
		runningTotal / count);

	return 0;
}
