//ThisExercise2.cpp - Exercise some of the features of the this pointer

#include<iostream>
#include "Account.h"

using namespace std;

int main(void) {
	Account *acct1 = new Account("Michael Barakat", 26);
	acct1->SetUsername("mbarakat").SetPassword();
	acct1->showUsernamePassword();

	Account acct2;
	acct1->CopyToAccount(acct2);
	acct2.showUsernamePassword();

	acct1->destroy();

	return 0;
}