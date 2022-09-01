//Account.c - source code for accounting application

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>//for Sleep()
#include "Account.h"

int main(void)
{
	struct Account account = { '\0', 0, 0.0 };//Initialize name, number and balance
	                       //NOTE: '\0' literally means 0, not the ascii value of 0
	//If struct Account consisted of 3 character arrays,
	//then account could have been initialized as:
	//struct Account account={{'\0'}};

	printf("The full name on the account: ");
	scanf(" %32[^\n]", account.name);//Accept a space to clear the scanf
	// buffer then accept 32 characters excluding the carriage-return.
	// This will leave the carriage-return in the scanf() buffer, so any
	// subsequent scanf() of strings or chars has to have a space before
	// the placeholder. For example:
	// scanf(" %32[^\n]", ...);
	// scanf(" %c", ...);
	printf("Enter the account number: ");
	scanf("%d", &account.number);
	printf("Enter the initial amount: ");
	scanf("%f", &account.balance);

	int action;
	int err;
	int years;
	float sum;
	do {
		Sleep(2000);//sleep for 2 seconds
		system("cls");//system command to clear the screen
		printf("%s your account %d has a balance of %.2f\n", account.name, account.number, account.balance);
		printf("\n");
		do {
			printf("Select one of the following:\n");
			printf("1. Deposit\n");
			printf("2. Withdraw\n");
			printf("3. Let sit for one or more years\n");
			printf("4. Quit\n");
			scanf("%d", &action);
			if (action < 1 || action>4) printf("Invalid entry, try again\n");
		} while (action < 1 || action>4);

		switch (action) {
		case 1://Deposit
			printf("How much would you like to deposit: ");
			scanf("%f", &sum);
			err = Deposit(&account, sum);//we want to change balance, so pass account by address
                                         //we don't want to change the sum, so pass sum by value
			if (err == 0) printf("%.2f deposited\n", sum);
			else printf("Unable to complete transaction\n");
			break;
		case 2://Withdraw
			printf("How much would you like to withdraw: ");
			scanf("%f", &sum);
			err = Withdraw(&account, sum);//we want to change balance, so pass account by address
                                          //we don't want to change the sum, so pass sum by value
			if (err == 0) printf("%.2f withdrawn\n", sum);
			else printf("Unable to complete transaction\n");
			break;
		case 3://Let sit for one or more years
			printf("How many years do you want your account to sit: ");
			scanf("%d", &years);
			err = AccumulateInterest(&account, years);//we want to change balance, so pass account by address
                                                      //we don't want to change the years, so pass years by value
			if (err == 0) printf("Your account will sit for %d year(s) at %.2f%% annual interest\n", years, 100.0*INTEREST_RATE);
		}
	} while (action != 4);

	printf("\n");
	printf("DONE\n");

	return 0;
}

//Deposit - adds money to an account
//Parameters: acc - pointer to the account
//            amount - the amount
//Returns: 0 - success
//        -1 - error
int Deposit(struct Account* acc, float amount)
{
	int retVal = 0;
	if (amount < 0) {//invalid value
		retVal = -1;
	}
	else {
		acc->balance += amount;
	}
	return retVal;
}

//Withdraw - removes money from an account
//Parameters: acc - pointer to the account
//            amount - the amount
//Returns: 0 - success
//        -1 - error
int Withdraw(struct Account* acc, float amount)
{
	int retVal = 0;
	if (amount < 0) {//invalid value
		retVal = -1;
	}
	else if (amount > acc->balance) {
		printf("Insufficient funds\n");
		retVal = -1;
	}
	else {
		acc->balance -= amount;
	}
	return retVal;
}

//AccumulateInterest - allows an account to accumulate interest
//Parameters: acc - pointer to the account
//            years - the number of years to accumulate interest
//Returns: 0 - success
//        -1 - error
int AccumulateInterest(struct Account* acc, int years)
{
	int retVal = 0;
	int i;
	if (years < 1) {//invalid value
		retVal = -1;
	}
	else if (acc->balance <= 0) {
		printf("You do not have anything in your account to accumulate interest on\n");
		retVal = -1;
	}
	else {
		for (i = 0; i < years; ++i) {
			acc->balance += acc->balance * INTEREST_RATE;
		}
	}
	return retVal;
}