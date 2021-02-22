//InvestmentAccount.cpp - function definitions for an investment account

#include <iostream>
#include "BankManager.h"
#include "InvestmentAccount.h"

using namespace std;

InvestmentAccount::InvestmentAccount() {
	cash = 0;
	stocks = 0;
	name = "";
	transactions = new int[20];
}

InvestmentAccount::InvestmentAccount(std::string name, double cash) {
	this->cash = cash;
	stocks = 0;
	this->name = name;
	transactions = new int[20];
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

const InvestmentAccount& InvestmentAccount::operator+=(double amount) {//add cash
	if (amount > 0) {
		this->cash += amount;
	}
	else {
		cout << "Invalid transaction" << endl;
	}
	return *this;
}

const InvestmentAccount& InvestmentAccount::operator-=(double amount) {//withdraw cash
	if (amount < 0) {
		cout << "Invalid transaction" << endl;
	}
	else if (amount > this->cash) {
		cout << "Not enough funds" << endl;
	}
	else {
		this->cash -= amount;
	}
	return *this;
}

InvestmentAccount::~InvestmentAccount() {//wipe out all information
	if (transactions != nullptr) {
		delete[] transactions;
		transactions = nullptr;
	}
	name = "";
	cash = 0.0;
	stocks = 0.0;
}
