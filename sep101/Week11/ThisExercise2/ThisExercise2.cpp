//ThisExercise2.cpp - Exercise some of the features of the this pointer

#include<iostream>
#include "Account.h"

using namespace std;

int main(void) {
	Account *acct1 = new Account("Michael Barakat", 26);//we allocated memory for acct1
	acct1->SetUsername("mbarakat").GeneratePassword();//function chaining
	acct1->showUsernamePassword();

	Account acct2;//the operating system allocated memory for acct1
	acct1->CopyToAccount(acct2);
	acct2.showUsernamePassword();

	acct1->destroy();
//	delete acct1;

	return 0;
}