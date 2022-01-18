//BankManager.cpp - function definitions for a bank manager

#include <iostream>
#include "BankManager.h"
#include "InvestmentAccount.h"

using namespace std;

BankManager::BankManager() {
	name = "";
	branchNumber = 0;
	employeeNumber = 0;
}

BankManager::BankManager(std::string name, int branch, int employee) {
	this->name = name;
	branchNumber = branch;
	employeeNumber = employee;
}

void BankManager::OverrideName(InvestmentAccount& account, std::string name) {
	account.name = name;
}

void BankManager::AddCash(InvestmentAccount& account, double cash) {
	account += cash;//take advantage of the overloaded operator += for InvestmentAccount
}

void BankManager::RemoveCash(InvestmentAccount& account, double cash) {
	account -= cash;//take advantage of the overloaded operator -= for InvestmentAccount
}

std::ostream& BankManager::PrintReport(InvestmentAccount& account) const {
	cout << account.name << " has $" << account.stocks << " in stocks and $" << account.cash << " in cash.";
	return cout;
}

BankManager::~BankManager() {
	name = "";
	branchNumber = 0;
	employeeNumber = 0;
}

//Implement the overloading of the == operator
//where true is returned if the names of the investment accounts are the same, false otherwise
//Do not forget the function prototype in the header file BankManager.h