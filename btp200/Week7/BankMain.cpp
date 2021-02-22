//BankMain.cpp - main function for the bank

#include <iostream>
#include "BankManager.h"
#include "InvestmentAccount.h"

using namespace std;

int main(void) {
	const int NUM = 3;
	BankManager manager("Perry Burns", 1000123, 827783);
	InvestmentAccount *client[NUM];
	client[0] = new InvestmentAccount("David Sands", 20000);
	client[1] = new InvestmentAccount("Kamla Patel", 30000);
	client[2] = new InvestmentAccount();

	client[0]->PurchaseStocks(18900);
	client[1]->PurchaseStocks(27880);
	manager.OverrideName(*client[2], "Wing Chung");
	manager.AddCash(*client[2], 50000);
	client[2]->PurchaseStocks(44678);

	for (int i = 0; i < NUM; ++i) {
		manager.PrintReport(*client[i]) << endl;
	}
	cout << endl;

	*client[0] += 5000;
	*client[1] -= 5000;
	*client[2] += 10000;

	for (int i = 0; i < NUM; ++i) {
		manager.PrintReport(*client[i]) << endl;
	}
	cout << endl;

	InvestmentAccount client3("Wing Chung", 33000);
	if (*client[0] == client3) {
		cout << "clients 0 and 3 are the same" << endl;
	}
	else if (*client[1] == client3) {
		cout << "clients 1 and 3 are the same" << endl;
	}
	else if (*client[2] == client3) {
		cout << "clients 2 and 3 are the same" << endl;
	}

	for (int i = 0; i < NUM; ++i) {
		delete client[i];
	}

	return 0;
}