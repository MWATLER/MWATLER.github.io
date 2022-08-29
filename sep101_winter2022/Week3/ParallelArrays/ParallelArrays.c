//ParallelArrays.c - A simple program to demonstrate parallel arrays

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#include <stdio.h>

int main(void)
{
	int i;
	char* product[] = { "Chocolate", "Chips", "Soda", "Peanuts" };
	int sku[] = { 2156, 4633, 3122, 5611 };//These arrays are dependent on each other
	double price[] = { 2.34, 4.99, 2.50, 6.99 };
	const int NUM = 4;

	printf("i    Product  SKU  Price\n");
	//	printf("i  SKU  Price\n");
	for (i = 0; i < NUM; i++) {
		printf("%d %10s %5d $%.2lf\n", 
			i, product[i], sku[i], price[i]);                                                                                
//		printf("%d %5d $%.2lf\n", i, sku[i], price[i]);
	}

	return 0;
}