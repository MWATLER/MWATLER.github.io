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
	account += cash;//taking advantage of the overloaded operator += for InvestmentAccount
}

void BankManager::RemoveCash(InvestmentAccount& account, double cash) {
	account -= cash;
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

bool operator==(const InvestmentAccount& lhs, const InvestmentAccount& rhs) {
	bool ret = true;
	if (lhs.GetName() != rhs.GetName()) ret = false;
	return ret;
}