//RealEstateMain.c - main program for real estate companies

// 02-Mar-21  M. Watler         Created

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main(void) {
    //Read the data for all companies from a file
	char address[255];
	int rooms;
	int bathrooms;
	double purchasePrice;
	double monthlyRent;
	double monthlyUtilities;
	double monthlyCondoFees;
	double monthlyPropertyTax;

	//Retrieve data for apartments
	FILE* fp = fopen("Apartments.txt", "r");
	for (int i = 0; i < 5; ++i) {
		fscanf(fp, "%[^\n]s", address);
		fscanf(fp, "%d", &rooms);
		fscanf(fp, "%d", &bathrooms);
		fscanf(fp, "%lf", &purchasePrice);
		fscanf(fp, "%lf", &monthlyRent);
		fscanf(fp, "%lf", &monthlyCondoFees);
		while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
	}
	fclose(fp);

	//Retrieve data for townhouses
	fp = fopen("Townhouses.txt", "r");
	for (int i = 0; i < 5; ++i) {
		fscanf(fp, "%[^\n]s", address);
		fscanf(fp, "%d", &rooms);
		fscanf(fp, "%d", &bathrooms);
		fscanf(fp, "%lf", &purchasePrice);
		fscanf(fp, "%lf", &monthlyRent);
		fscanf(fp, "%lf", &monthlyUtilities);
		fscanf(fp, "%lf", &monthlyCondoFees);
		fscanf(fp, "%lf", &monthlyPropertyTax);
		while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
	}
	fclose(fp);

	//Retrieve data for semi-detached houses
	fp = fopen("SemiDetachedHouses.txt", "r");
	for (int i = 0; i < 5; ++i) {
		fscanf(fp, "%[^\n]s", address);
		fscanf(fp, "%d", &rooms);
		fscanf(fp, "%d", &bathrooms);
		fscanf(fp, "%lf", &purchasePrice);
		fscanf(fp, "%lf", &monthlyRent);
		fscanf(fp, "%lf", &monthlyUtilities);
		fscanf(fp, "%lf", &monthlyPropertyTax);
		while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
	}
	fclose(fp);

	return 0;
}