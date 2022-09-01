// Arrays.c : A simple program to demonstrate arrays
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#include <stdio.h>
#define NUM 3

int main(void)
{
	double price1 = 10.60;
	double price2 = 23.45;
	double price3 = 5.89;
	double average;

	printf(" Item     Price\n");
	printf("    1%10.2lf\n", price1);
	printf("    2%10.2lf\n", price2);
	printf("    3%10.2lf\n", price3);
	average = (price1 + price2 + price3) / NUM;
	printf("Average is %.2lf\n", average);

	double price[NUM] = { 10.60, 23.45, 115.89 };
	double total = 0;
	for (int i = 0; i < NUM; ++i) {
		printf("    %d%8.2lf\n", i + 1, price[i]);
		total += price[i];
	}
	printf("Average is %.2lf\n", total/NUM);

	return 0;
}
