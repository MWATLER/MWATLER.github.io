//ThisExercise2.cpp - Exercise some of the features of the this pointer

#include<iostream>
#include "Account.h"

using namespace std;

int main(void) {
	Account *acct1 = new Account("Michael Barakat", 26);
	acct1->SetUsername("mbarakat");
	acct1->SetPassword();
	acct1->showUsernamePassword();
//	int strength = GetStrength(*acct1);
//	cout << "This account has a password strength of " << strength << endl;

	Account acct2;
	acct1->CopyAccount(acct2);
	acct2.showUsernamePassword();
//	strength = GetStrength(acct2);
//	cout << "This account has a password strength of " << strength << endl;

	acct1->destroy();

	return 0;
}