// CurrencyConverter.c : This file contains the 'main' function. Program execution begins and ends there.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int err = 0;
	FILE* fpr = fopen("GroceryList.txt", "r");
	FILE* fpw = fopen("GroceryListUSA.txt", "w");
	char name[30];
	int barcode;
	double price;
	const double exchangeRate = 0.76;
	int rc = 0;
	if (fpr != NULL && fpw != NULL) {
		do {
			rc = fscanf(fpr, "%s %d %lf", name, &barcode, &price);
			if (rc == 3) {
				fprintf(fpw, "%s %d %.2lf\n",
					name, barcode, price * exchangeRate);
				fflush(fpw);//The output stream is buffered. Force it to flush with fflush().
			}
		} while (rc == 3);
	}
	else {
		err = -1;
	}
	if (fpr != NULL) fclose(fpr);
	if (fpw != NULL) fclose(fpw);
	return err;
}