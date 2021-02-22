//InvestmentAccount.h - class declaration for an investment account

#ifndef _INVESTMENT_ACCOUNT_H
#define _INVESTMENT_ACCOUNT_H
#include <iostream>
#include "BankManager.h"

class InvestmentAccount {
	double cash;
	double stocks;
	std::string name;
	int* transactions;

public:
	friend class BankManager;
	InvestmentAccount();
	InvestmentAccount(std::string name, double cash);
	~InvestmentAccount();//wipe out all information
	bool PurchaseStocks(double amount);//stocks+=amount; this->cash-=amount;
	bool SellStocks(double amount);//stocks-=amount;cash+=amount
	std::string GetName() const;
	double GetValue() const;//cash+stocks;
	double GetStocks() const;
	double GetCash() const;
	const InvestmentAccount& operator+=(double);//add cash
	const InvestmentAccount& operator-=(double);//withdraw cash
	//int main() {
	//    InvestmentAccount acct(...);
	//    acct += 5000;
	//}
};

#endif//_INVESTMENT_ACCOUNT_H