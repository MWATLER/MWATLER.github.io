//Bookstore.h - structure declarations for a bookstore

#ifndef _BOOKSTORE_H_
#define _BOOKSTORE_H_

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

void utilClearFileInputBuffer(FILE *filePointer);
void utilClearInputBuffer();
int GetInformationFromFile(struct Bookstore* bookstore, char fileName[]);
double CalculateNetWorth(struct Bookstore bookstore);
double CalculateProfits(struct Bookstore bookstore);
double CalculateProfitsByBooks(struct Book book[]);
double CalculateProfitsByDVDs(struct DVD dvd[]);
int ChangePriceOfItem(struct Bookstore* bookstore, char itemName[]);

#endif// _BOOKSTORE_H_
