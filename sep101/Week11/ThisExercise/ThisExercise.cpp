//ThisExercise.cpp - Exercise some of the features of the this pointer

#include<iostream>
#include "Account.h"

using namespace std;

int main(void) {
	Account acct1("Michael Barakat", 26);//create an object called acct1 of type Account
	acct1.SetUsername("mbarakat").SetPassword();//SetUsername returns the current object
	                  //so SetPassword is actually called as follows: acct1.SetPassword()
	acct1.showUsernamePassword();
//	acct1.destroy();

	return 0;
}