// ProcessTime.c : This file contains the 'main' function. Program execution begins and ends there.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITER 400

int main(void)
{
	double x;
	int i, j, k;
	time_t t0, t1;
	clock_t c0, c1;//typedef long clock_t

	x = 1;
	t0 = time(NULL);
	c0 = clock();
	for (i = 0; i < NUM_ITER; i++) {
		for (j = 0; j < NUM_ITER; j++) {
			for (k = 0; k < NUM_ITER; k++) {
				x = x * 1.0000000001;
			}
		}
	}
	t1 = time(NULL);
	c1 = clock();
	printf("Elapsed time is %.1lf secs\n",
		difftime(t1, t0));
	printf("Process time is %.3lf secs\n",
		(double)(c1 - c0) / CLOCKS_PER_SEC);
	//	printf("Value of x is %.10lf\n", x);

	printf("\n\nRandom Number Generator\n\n");
	printf("Enter the lower and upper limits: ");
	int upperLimit;
	int lowerLimit;
	scanf("%d %d", &lowerLimit, &upperLimit);
	srand(time(NULL));
	for (i = 0; i < 10; ++i) {
		int num = rand();
		int numWithLimit = lowerLimit + num % (upperLimit - lowerLimit);
		printf("num:%5d numWithLimit:%d\n", num, numWithLimit);
	}

	return 0;
}