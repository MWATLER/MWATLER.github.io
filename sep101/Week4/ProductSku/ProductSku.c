// ProductSku.c : Demo program to show structures
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#include <stdio.h>
#include "product.h"

int main(void)
{
	int i;
//	struct Product {
//		int sku;//barcode
//		double price;
//	};
	struct Product product[] = {
//{product[0].sku, product[0].price}, {product[1].sku, product[1].price},
	 {2156, 2.34}, {4633, 7.89},
	 {3122, 6.56}, {5611, 9.32} };
	double runningTotal = 0;
	double average;
	const int n = 4;

	printf("  SKU Price\n");
	for (i = 0; i < n; i++) {
		printf("%5d $%.2lf\n", product[i].sku, product[i].price);
		runningTotal += product[i].price;
	}
	printf("\n");
	printf("Let's change product 2:\n");//2nd product, index 1
	printf("Enter the new sku: ");
	scanf_s("%d", &product[1].sku);
	printf("Enter the new price: $");
	scanf_s("%lf", &product[1].price);

	printf("\n");
	printf("New SKU Price\n");
	for (i = 0; i < n; i++) {
		printf("%5d $%.2lf\n",
			product[i].sku, product[i].price);
		runningTotal += product[i].price;
	}

	average = runningTotal / n;
	printf("The average price is %.2lf\n", average);

	for (i = 0; i < n; ++i) {
		printf("RAM address of product[%d]:%p\n",
			i, (void*)& product[i]);
	}

	return 0;
}