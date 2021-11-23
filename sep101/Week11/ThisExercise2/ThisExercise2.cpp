//ThisExercise2.cpp - Exercise some of the features of the this pointer

#include<iostream>
#include "Account.h"

using namespace std;

int main(void) {
	Account *acct1 = new Account("Michael Barakat", 26);
	acct1->SetUsername("mbarakat").SetPassword();//chain the functions together, not typically done in C++ 
	                                             //but typically done in scripting languages such as JavaScript
	acct1->showUsernamePassword();

	Account acct2;
	acct1->CopyAccount(acct2);//acct1 is the current object
	acct2.showUsernamePassword();

	acct1->destroy();

//	acct1->showUsernamePassword();//should crash the program, because acct1 no longer exists
//	delete acct1;//acct1 already deleted

	return 0;//acct2 will be deleted at the end of the main() function
}