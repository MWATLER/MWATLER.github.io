//BankAccount.h - class declaration for a bank account

#ifndef _BANKACCOUNT_H_
#define _BANKACCOUNT_H_

#include <iostream>

class BankAccount {
	std::string name;
	int socialInsNumber;
	double balance;
	const double BALANCE_LIMIT = 200.00;
public:
	BankAccount(std::string name, int sin, double balance);
	double AddMoney(double amount);
	double WithdrawMoney(double amount);
	void CopyAccount(const BankAccount& account);
	void MoveAccount(BankAccount& account);
	void StealAccount(BankAccount& account);
	void PrintReport();
};

#endif// _BANKACCOUNT_H_
