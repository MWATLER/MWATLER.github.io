//Evaluation.c - Midterm review on evaluation

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	const double e = 2.71828;
	printf("The constant e is %d %.2lf\n", (int)e, e);

	const int x = 16;
	const int y = 5;
	printf("x/y is %d\n", x / y);

	const int z = 16;
	const int w = 4;
	printf("z/w is %.3f\n", (float)z / w);

	int num1 = 92, num2 = 94;
	int result = (num2 < num1) ? (num2 - num1) * 3 : (num2 - num1) * 2;
	printf("result is: %d\n", result);

	int num3 = 2, num4 = 4;
	int res = (num4 > num3) ? num4 - num3 * 3 : num4 - num3 * 2;
	printf("res is: %d\n", res);

	const char college[] = "Seneca College";
	printf("%c%c%c\n", college[3], college[4], college[5]);

	return 0;
}