//InvestmentAccount.cpp - function definitions for an investment account

#include <iostream>
#include "BankManager.h"
#include "InvestmentAccount.h"

using namespace std;

InvestmentAccount::InvestmentAccount() {

}

InvestmentAccount::InvestmentAccount(std::string name, double cash) {

}

bool InvestmentAccount::PurchaseStocks(double amount) {
	bool success = true;
	if (this->cash < amount) {
		success = false;
	}
	else {
		this->cash -= amount;
		stocks += amount;
	}

	return success;
}

bool InvestmentAccount::SellStocks(double amount) {
	bool success = true;
	if (stocks < amount) {
		success = false;
	}
	else {
		this->cash += amount;
		stocks -= amount;
	}
	return success;
}

std::string InvestmentAccount::GetName() const {

}

double InvestmentAccount::GetValue() const {

}

double InvestmentAccount::GetStocks() const {

}

double InvestmentAccount::GetCash() const {

}

//Implement the overload of the += operator
//This should add cash to the investment account
//If the amount to be added is negative, print out the error message "Invalid transaction"
//Do not forget the function prototype in the header file InvestmentAccount.h



//Implement the overload of the -= operator
//This should withdraw cash from the investment account
//If the amount to be withdrawn is negative, print out the error message "Invalid transaction"
//If there isn't enough cash in the account, print out the error message "Not enough funds"
//Do not forget the function prototype in the header file InvestmentAccount.h


InvestmentAccount::~InvestmentAccount() {//wipe out all information

}
