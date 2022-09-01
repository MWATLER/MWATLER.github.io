// Functions.c : Functions to manipulate currency
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY
//
// 31-Oct-2018  M Watler: Created.
// 29-Oct-2019  M Watler: Added personal information to header comments.
// 29-Oct-2019  M Watler: Added validation of account balance and expense item.

#define _CRT_SECURE_NO_WARNINGS
#include "finance.h"
#include <stdio.h>

int main()
{
	struct Currency account = { 0,0 };
	struct Currency expense = { 0,0 };
	do {
		printf("Enter your account balance, dollars: ");
		scanf("%d", &account.dollars);
		if (account.dollars < 0) printf("Invalid amount\n");
	} while (account.dollars < 0);
	do {
		printf("Enter your account balance, cents: ");
		scanf("%d", &account.cents);
		if (account.cents < 0) printf("Invalid amount\n");
	} while (account.cents < 0);
	printf("\n");

	do {
		printf("Enter the expense item, dollars: ");
		scanf("%d", &expense.dollars);
		if (expense.dollars < 0) printf("Invalid amount\n");
	} while (expense.dollars < 0);
	do {
		printf("Enter the expense item, cents: ");
		scanf("%d", &expense.cents);
		if (expense.cents < 0) printf("Invalid amount\n");
	} while (expense.cents < 0);
	printf("\n");
	//	In AccountExpenser: struct Currency *curr = &account;//pass by address, changing
	//                      struct Currency  cost = expense; //pass by value, not changing
	int ret = AccountExpenser(&account, expense);
	if (ret == 0) {
		printf("Your account balance is now $%d.%02d\n",
			account.dollars, account.cents);
	}
	else {
		printf("Could not expense this item - not enough funds!\n");
	}
	//Apply an exchange rate
	double exchangeRate = 1.20;
	// In ExchangeRate: struct Currency *curr = &account;//pass by address, changing
	//                  double rate = exchangeRate;//pass by value, not changing
	ret = ExchangeRate(&account, exchangeRate);
	if (ret == 0) {
		printf("After applying the exchange rate, your account balance is now $%d.%02d\n",
			account.dollars, account.cents);
	}
	else {
		printf("Could not apply exchange rate - not enough funds!\n");
	}
	return 0;
}

// AccountExpenser - subtracts the cost of an item from the current account balance
// IN - curr: address of the Currency account
//      cost: data values of the expense
//OUT - error status (0: OK, -1: out of funds)
//
// 31-Oct-2018  M Watler: Created.
int AccountExpenser(struct Currency* curr, struct Currency cost) {
	//struct Currency *curr = &account;
	//struct Currency  cost = expense;
	int retVal;
	if (curr->dollars < cost.dollars) {
		retVal = -1;
	}
	else if (curr->dollars == cost.dollars &&
		curr->cents < cost.cents) {
		retVal = -1;
	}
	else {//Example: curr = $500.00, cost = $129.99
		curr->dollars = curr->dollars - cost.dollars;//500-129=371
//		curr->dollars -= cost.dollars;//500-129=371
		curr->cents = curr->cents - cost.cents;//0-99=-99
		while (curr->cents < 0) {
			curr->cents += 100;//cents becomes 1
			--curr->dollars;//dollars becomes 370
		}
		retVal = 0;
	}
	return retVal;
}

// ExchangeRate - applies an exchange rate to the current account
// IN - curr: address of the Currency account
//      rate: the exchange rate
//OUT - error status (0: OK, -1: out of funds)
//
// 31-Oct-2018  M Watler: Created.
// 29-Oct-2019  M Watler: Modified the calculation of dollars and cents.
int ExchangeRate(struct Currency* curr, double rate) {
	//struct Currency *curr = &account;
	//double rate = exchangeRate;
	int retVal = 0;
	int cents = 100 * curr->dollars + curr->cents;
	cents = cents * rate;//Example: $500 with rate of 1.2
						 //         cents = 50000 * 1.2 = 60000
	if (cents < 0) {
		retVal = -1;
	}
	else {
		curr->dollars = (int)cents / 100;
		curr->cents = (int)(cents - curr->dollars * 100);
	}
	return retVal;
}
