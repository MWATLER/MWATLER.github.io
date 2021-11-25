//BankAccount.cpp - function definitions for a bank account

#include "BankAccount.h"

using namespace std;

/*class BankAccount {
	std::string name;
	int socialInsNumber;
	double balance;
public:*/
BankAccount::BankAccount(std::string name, int sin, double balance) {
	//skip validation
	this->name = name;
	socialInsNumber = sin;
	this->balance = balance;
}

double BankAccount::AddMoney(double amount) {
	//skip validation
	balance += amount;
	return balance;
}

double BankAccount::WithdrawMoney(double amount) {
	//skip validation
	balance -= amount;
	if (balance < BALANCE_LIMIT)cout << "You are past your withdrawal limit!" << endl;
	else if (balance < 0) cout << "You are overdrawn" << endl;
	return balance;
}

void BankAccount::CopyAccount(const BankAccount& account) {//account1.CopyAccount(account2);
	                                                       //this refers to account1, account refers to account2
	if (this != &account) {//do not copy to yourself
		this->name = account.name;
		this->socialInsNumber = account.socialInsNumber;
		this->balance = account.balance;
	}
}

void BankAccount::MoveAccount(BankAccount& account) {//account2.MoveAccount(account3);
  												     //this refers to account2, account refers to account3
	if (this != &account) {//do not move to yourself
		//copy everything over
		this->name = account.name;
		this->socialInsNumber = account.socialInsNumber;
		this->balance = account.balance;
		//put account into an empty state
		account.name = "";
		account.socialInsNumber = 0;
		account.balance = 0.0;
	}
}

void BankAccount::StealAccount(BankAccount& account) {//account1.StealAccount(account2);
													  //this refers to account1, account refers to account2
	if (this != &account) {//do not steal from yourself
		//a good thief would check to see if the balance of his/her victim is positive. No one wants to steal debt
		if (account.balance > 0) {
			this->balance += account.balance;
			account.balance = 0.0;
		}
	}
}

void BankAccount::PrintReport() {
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << name << ", SIN: " << socialInsNumber << ", BALANCE: $" << balance << endl;
}
