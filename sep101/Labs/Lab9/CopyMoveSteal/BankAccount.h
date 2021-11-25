//BankAccount.h - class declaration for a bank account

#ifndef _BANKACCOUNT_H_
#define _BANKACCOUNT_H_

#include <iostream>

class BankAccount {
	std::string name;
	int socialInsNumber;
	double balance;
	const double BALANCE_LIMIT = -200.00;
public:
	BankAccount(std::string name, int sin, double balance);
	double AddMoney(double amount);
	double WithdrawMoney(double amount);
	void CopyAccount(const BankAccount& account);//copy from account to the current object (*this)
	void MoveAccount(BankAccount& account);//move from account to the current object (*this)
	//This means, empty everything in the current object, copy from account to the current object,
	//then empty everything in account
	void StealAccount(BankAccount& account);//add the balance of account to the balance of the 
	//current object (*this), then zero the balance of account
	void PrintReport();
};

#endif// _BANKACCOUNT_H_
