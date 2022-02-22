//Bookstore.c - functions for the bookstore

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>//strcmp
#include "Bookstore.h"
/*
#define NUM_BOOKS 4
#define NUM_DVDS 5
#define MAX_STR 64
struct Book {
	char name[MAX_STR];
	char author[MAX_STR];
	double purchasePrice;
	double salePrice;
};

struct DVD {
	char name[MAX_STR];
	char artist[MAX_STR];
	double purchasePrice;
	double salePrice;
};

struct Bookstore {
	char name[MAX_STR];
	char address[MAX_STR];
	struct Book book[NUM_BOOKS];
	struct DVD dvd[NUM_DVDS];
};
*/
void utilClearFileInputBuffer(FILE* filePointer) {
	char c;
	do {
		c = fgetc(filePointer);//gets one character from the file input buffer
	} while (c != '\n' );
}

void utilClearInputBuffer() {
	char c;
	do {
		c = getchar();//gets one character from the input buffer
	} while (c != '\n');
}

int GetInformationFromFile(struct Bookstore* bookstore, char fileName[]) {
	int retVal = 0;
	FILE* fp = fopen(fileName, "r");
	if (fp != NULL) {
		//read bookstore information
		fscanf(fp, "%[^\n]s", bookstore->name);
		utilClearFileInputBuffer(fp);
		fscanf(fp, "%[^\n]s", bookstore->address);

		//read the books
		for (int i = 0; i < NUM_BOOKS; ++i) {
			utilClearFileInputBuffer(fp);
			fscanf(fp, "%[^\n]s", bookstore->book[i].name);
			utilClearFileInputBuffer(fp);
			fscanf(fp, "%[^\n]s", bookstore->book[i].author);
			fscanf(fp, "%lf", &bookstore->book[i].purchasePrice);
			fscanf(fp, "%lf", &bookstore->book[i].salePrice);
		}
		//read the DVDs
		for (int i = 0; i < NUM_DVDS; ++i) {
			utilClearFileInputBuffer(fp);
			fscanf(fp, "%[^\n]s", bookstore->dvd[i].name);
			utilClearFileInputBuffer(fp);
			fscanf(fp, "%[^\n]s", bookstore->dvd[i].artist);
			fscanf(fp, "%lf", &bookstore->dvd[i].purchasePrice);
			fscanf(fp, "%lf", &bookstore->dvd[i].salePrice);
		}
	}
	else {
		retVal = -1;
	}
	return retVal;
}

double CalculateNetWorth(struct Bookstore bookstore) {
	double netWorth = 0.0;
	for (int i = 0; i < NUM_BOOKS; ++i) {
		netWorth += bookstore.book[i].salePrice;
	}
	for (int i = 0; i < NUM_DVDS; ++i) {
		netWorth += bookstore.dvd[i].salePrice;
	}
	return netWorth;
}

double CalculateProfits(struct Bookstore bookstore) {
	double profits = 0.0;
	//could call CalculateProfitsByBooks instead
	for (int i = 0; i < NUM_BOOKS; ++i) {
		profits += bookstore.book[i].salePrice - bookstore.book[i].purchasePrice;
	}
	//could call CalculateProfitsByDVDs instead
	for (int i = 0; i < NUM_DVDS; ++i) {
		profits += bookstore.dvd[i].salePrice - bookstore.dvd[i].purchasePrice;
	}
	return profits;
}

double CalculateProfitsByBooks(struct Book book[]) {
	double profits = 0.0;
	for (int i = 0; i < NUM_BOOKS; ++i) {
		profits += book[i].salePrice - book[i].purchasePrice;
	}
	return profits;
}

double CalculateProfitsByDVDs(struct DVD dvd[]) {
	double profits = 0.0;
	for (int i = 0; i < NUM_DVDS; ++i) {
		profits += dvd[i].salePrice - dvd[i].purchasePrice;
	}
	return profits;
}

int ChangePriceOfItem(struct Bookstore* bookstore, char itemName[]) {
	int retVal = 0;
	int found = 0;
	for (int i = 0; i < NUM_BOOKS && found == 0; ++i) {
		if (strcmp(itemName, bookstore->book[i].name) == 0) {
			found = 1;
			printf("%s is a book. Enter the new price for %s: $", bookstore->book[i].name, bookstore->book[i].name);
			scanf("%lf", &bookstore->book[i].salePrice);
		}
	}
	for (int i = 0; i < NUM_DVDS && found == 0; ++i) {
		if (strcmp(itemName, bookstore->dvd[i].name) == 0) {
			found = 1;
			printf("%s is a DVD. Enter the new price for %s: $", bookstore->dvd[i].name, bookstore->dvd[i].name);
			scanf("%lf", &bookstore->dvd[i].salePrice);
		}
	}

	if (found == 0) retVal = -1;
	return retVal;
}