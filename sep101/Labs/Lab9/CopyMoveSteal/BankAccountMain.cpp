//BankAccountMain.cpp - main function for the bank account

#include "BankAccount.h"

using namespace std;

int main() {
	BankAccount account1("Phil Collins",  1000123, 10000.00);
	BankAccount account2("Peter Gabriel", 1000124, 20000.00);
	BankAccount account3("Leslie Swift",  1000125, 30000.00);

	account1.PrintReport();
	account2.PrintReport();
	account3.PrintReport();
	cout << endl;

	account1.AddMoney(5000);
	account2.WithdrawMoney(2000);
	account3.WithdrawMoney(3000);

	account1.PrintReport();
	account2.PrintReport();
	account3.PrintReport();
	cout << endl;

	account1.CopyAccount(account2);

	account1.PrintReport();
	account2.PrintReport();
	account3.PrintReport();
	cout << endl;

	account2.MoveAccount(account3);

	account1.PrintReport();
	account2.PrintReport();
	account3.PrintReport();
	cout << endl;

	account1.StealAccount(account2);

	account1.PrintReport();
	account2.PrintReport();
	account3.PrintReport();
	cout << endl;

	return 0;
}