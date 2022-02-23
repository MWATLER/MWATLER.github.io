//BookstoreMain.c - main function for the bookstore

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Bookstore.h"

int main() {
	int retVal = 0;
	char fileName[MAX_STR];
	struct Bookstore bookstore;

	printf("Enter the filename for the bookstore database: ");
	scanf("%s", fileName);

	retVal = GetInformationFromFile(&bookstore, fileName);//bookstore is passed by address
	if (retVal == 0) {
		double worth = CalculateNetWorth(bookstore);//bookstore is passed by value
		double profit = CalculateProfits(bookstore);//bookstore is passed by value
		double profitBooks = CalculateProfitsByBooks(bookstore.book);//bookstore is passed by value
		double profitDVDs = CalculateProfitsByDVDs(bookstore.dvd);//bookstore is passed by value

		printf("\n");
		printf("The %s book store at %s has the following items:\n", bookstore.name, bookstore.address);
		for (int i = 0; i < NUM_BOOKS; ++i) {
			printf("The book %s written by %s was purchased for $%.2lf and sells for $%.2lf\n", 
				bookstore.book[i].name, bookstore.book[i].author, bookstore.book[i].purchasePrice, bookstore.book[i].salePrice);
		}
		for (int i = 0; i < NUM_DVDS; ++i) {
			printf("The DVD %s created by %s was purchased for $%.2lf and sells for $%.2lf\n",
				bookstore.dvd[i].name, bookstore.dvd[i].artist, bookstore.dvd[i].purchasePrice, bookstore.dvd[i].salePrice);
		}
		printf("\n");
		printf("The net worth of this bookstore is $%.2lf\n", worth);
		printf("The net profit of this bookstore is $%.2lf\n", profit);
		printf("Profits by book are $%.2lf\n", profitBooks);
		printf("Profits by DVD are $%.2lf\n", profitDVDs);

		char itemName[MAX_STR];
		printf("\n");
		printf("Enter the name of an item which price you'd like to change: ");
		utilClearInputBuffer();
		scanf("%[^\n]s", itemName);

		int ret = ChangePriceOfItem(&bookstore, itemName);//bookstore is passed by address
		if (ret == 0) {
			printf("\n");
			printf("The %s book store now has the following items:\n", bookstore.name);
			for (int i = 0; i < NUM_BOOKS; ++i) {
				printf("The book %s written by %s was purchased for $%.2lf and sells for $%.2lf\n",
					bookstore.book[i].name, bookstore.book[i].author, bookstore.book[i].purchasePrice, bookstore.book[i].salePrice);
			}
			for (int i = 0; i < NUM_DVDS; ++i) {
				printf("The DVD %s created by %s was purchased for $%.2lf and sells for $%.2lf\n",
					bookstore.dvd[i].name, bookstore.dvd[i].artist, bookstore.dvd[i].purchasePrice, bookstore.dvd[i].salePrice);
			}
		}
		else {
			printf("The item %s was not found.\n", itemName);
		}
	}
	else {
		printf("The bookstore database file %s was not found!\n", fileName);
	}

	return retVal;
}