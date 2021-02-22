//InvestmentAccount.cpp - function definitions for an investment account

#include <iostream>
#include "BankManager.h"
#include "InvestmentAccount.h"

using namespace std;

InvestmentAccount::InvestmentAccount() {
	cash = 0;
	stocks = 0;
	name = "";
}

InvestmentAccount::InvestmentAccount(std::string name, double cash) {
	this->cash = cash;
	stocks = 0;
	this->name = name;
}

bool InvestmentAccount::PurchaseStocks(double cash) {
	bool success = true;
	if (this->cash < cash) {
		success = false;
	}
	else {
		this->cash -= cash;
		stocks += cash;
	}

	return success;
}

bool InvestmentAccount::SellStocks(double cash) {
	bool success = true;
	if (stocks < cash) {
		success = false;
	}
	else {
		this->cash += cash;
		stocks -= cash;
	}
	return success;
}

std::string InvestmentAccount::GetName() const {
	return name;
}

double InvestmentAccount::GetValue() const {
	return cash + stocks;
}

double InvestmentAccount::GetStocks() const {
	return stocks;
}

double InvestmentAccount::GetCash() const {
	return cash;
}

const InvestmentAccount& InvestmentAccount::operator+=(double cash) {//add cash
	if (cash > 0) {
		this->cash += cash;
	}
	else {
		cout << "Invalid transaction" << endl;
	}
	return *this;
}

const InvestmentAccount& InvestmentAccount::operator-=(double cash) {//withdraw cash
	if (cash < 0) {
		cout << "Invalid transaction" << endl;
	}
	else if (cash > this->cash) {
		cout << "Not enough funds" << endl;
	}
	else {
		this->cash -= cash;
	}
	return *this;
}

InvestmentAccount::~InvestmentAccount() {//wipe out all information
	name = "";
	cash = 0.0;
	stocks = 0.0;
}
