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
	bool PurchaseStocks(double cash);
	bool SellStocks(double cash);
	std::string GetName() const;
	double GetValue() const;
	double GetStocks() const;
	double GetCash() const;
	const InvestmentAccount& operator+=(double);//add cash
	const InvestmentAccount& operator-=(double);//withdraw cash
};

#endif//_INVESTMENT_ACCOUNT_H