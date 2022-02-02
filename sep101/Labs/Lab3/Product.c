//Product.c - A simple program to demonstrate structures

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#include <stdio.h>//<...> include from the system C library
#include "Product.h"//"..." include from my own custom library
#define NUM 4

int main(void)
{
	int i;
/*	struct ProductInfo {//we are creating a new type called "struct ProductInfo"
		char product[BUFLEN];
		int sku;
		double price;
	};*/
	struct ProductInfo prod[NUM] = {
		{"Chocolate", 2156, 2.34},//index 0
	    {"Chips", 4633, 4.99},//index 1
	    {"Soda", 3122, 2.50},//index 2
	    {"Peanuts", 5611, 6.99}//index 3
	};

	printf("i    Product  SKU  Price\n");
	for (i = 0; i < NUM; i++) {
		printf("%d %10s %5d $%.2lf\n", i, prod[i].product, prod[i].sku, prod[i].price);
	}

	// change the price of one of the prod's
	int barcode;
	int index = 0;//index into the ProductInfo array
	int found = 0;//a found flag
	printf("Enter the sku of a product whose price you wish to change: ");
	scanf_s("%d", &barcode);
	if (barcode < 0) printf("Invalid barcode\n");
	else {
		for (int i = 0; i < NUM && found==0; ++i) {
			if (barcode == prod[i].sku) {//look for the sku that matches the barcode
				found = 1;
				index = i;
			}
		}
	}
	if (found == 1) {
		double newPrice = 0.0;
		printf("You have chosen the %s\n", prod[index].product);
		printf("What is the new price? $");
		scanf_s("%lf", &newPrice);
		if (newPrice < 0) printf("Invalid price!\n");
		else prod[index].price = newPrice;
	}

	printf("\n\n");
	printf("i    Product  SKU  Price\n");
	for (i = 0; i < NUM; i++) {
		printf("%d %10s %5d $%.2lf\n", i, prod[i].product, prod[i].sku, prod[i].price);
	}
	return 0;
}
