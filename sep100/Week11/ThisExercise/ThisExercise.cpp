//ThisExercise.cpp - Exercise some of the features of the this pointer

#include<iostream>
#include "Account.h"

using namespace std;

int main(void) {
	Account acct1("Michael Barakat", 26);
	acct1.SetUsername("mbarakat").SetPassword();
	acct1.showUsernamePassword();
//	acct1.destroy();

	return 0;
}