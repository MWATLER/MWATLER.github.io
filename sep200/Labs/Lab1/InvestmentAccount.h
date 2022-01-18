//InvestmentAccount.h - class declaration for an investment account

#ifndef _INVESTMENT_ACCOUNT_H
#define _INVESTMENT_ACCOUNT_H
#include <iostream>
#include "BankManager.h"

class InvestmentAccount {
	double cash;
	double stocks;
	std::string name;

public:
	friend class BankManager;
	InvestmentAccount();
	InvestmentAccount(std::string name, double cash);
	~InvestmentAccount();//wipe out all information
	bool PurchaseStocks(double amount);//stocks+=amount; this->cash-=amount;
	bool SellStocks(double amount);//stocks-=amount;cash+=amount
	std::string GetName() const;
	double GetValue() const;//cash+stocks;
	double GetStocks() const;//stocks
	double GetCash() const;//cash
};

#endif//_INVESTMENT_ACCOUNT_H