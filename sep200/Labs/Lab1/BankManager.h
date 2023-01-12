//BankManager.h - class declaration for a bank manager

#ifndef _BANK_MANAGER_H
#define _BANK_MANAGER_H
#include <iostream>
#include "InvestmentAccount.h"

class BankManager {
	std::string name;
	int branchNumber;
	int employeeNumber;
public:
	BankManager();
	BankManager(std::string name, int branch, int employee);
	~BankManager();
	void OverrideName(InvestmentAccount& account, std::string name);
	void AddCash(InvestmentAccount& account, double cash);
	void RemoveCash(InvestmentAccount& account, double cash);
	std::ostream& PrintReport(InvestmentAccount& account) const;
};

#endif//_BANK_MANAGER_H