// CurrencyConverter2.c : This file contains the 'main' function. Program execution begins and ends there.
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
	char name[30];
	int barcode;
	double price;
	double exchangeRate;
	int rc;
	FILE* fpr = fopen("GroceryList.txt", "r");
	FILE* fpw = fopen("GroceryListUSA.txt", "w");
	if(fpr==NULL || fpw==NULL) {
		err = -1;
		if (fpr != NULL) fclose(fpr);
		if (fpw != NULL) fclose(fpw);
	}
	else {
		exchangeRate = 0.76;
		do {
			rc = fscanf(fpr, "%s %d %lf", name, &barcode, &price);
			if (rc == 3) fprintf(fpw, "%s %d %.2lf\n",
				name, barcode, price * exchangeRate);
		} while (rc == 3);
		fclose(fpw);

		fpw = fopen("GroceryListUK.txt", "w");
		if (fpw == NULL) {
			fclose(fpr);
			err = -1;
		}
		else {
			exchangeRate = 0.56;
			rewind(fpr);
			do {
				rc = fscanf(fpr, "%s %d %lf", name, &barcode, &price);
				if (rc == 3) fprintf(fpw, "%s %d %.2lf\n",
					name, barcode, price * exchangeRate);
			} while (rc == 3);
		}
	}
	if (fpr != NULL) fclose(fpr);
	if (fpw != NULL) fclose(fpw);
	return err;
}