#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int factorial(int, double*);
int main() {
	int num;
	double res;
	printf("Enter a number : ");
	scanf("%d", &num);
	int retVal = factorial(num, &res);
	if (retVal == 0) {
		printf("The factorial of %d is %.2lf\n", num, res);
	}
	return 0;
}
int factorial(int number, double* result) {
	*result = 1;
	for (int i = 1; i <= number; ++i) {
		*result = *result * (double)i;
	}
	return 0;
}