//ThisExercise.cpp - Exercise some of the features of the this pointer

#include<iostream>
#include "Account.h"

using namespace std;

int main(void) {
	Account acct1("Michael Barakat", 26);
	acct1.SetUsername("mbarakat").SetPassword();
	//acct1.SetUsername("mbarakat") returns acct1
	//SetPassword() is therefore called as acct1.SetPassword()
	//I can chain related functions to each other using this strategy.
	//Chaining functions is very common in JavaScript but not common in C++.
	acct1.showUsernamePassword();
//	acct1.destroy();

	return 0;
}
