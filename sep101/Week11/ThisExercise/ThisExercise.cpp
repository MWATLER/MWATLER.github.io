//ThisExercise.cpp - Exercise some of the features of the this pointer

#include<iostream>
#include "Account.h"

using namespace std;

int main(void) {
	Account acct1("Michael Barakat", 26);//acct1 is the current object
	                                     //The "this" pointer inside Account will point to acct1
	acct1.SetUsername("mbarakat").GeneratePassword();//this is called chaining
	//Chaining is not usually done in C++, but it is often done in scripting languages like JavaScript
	//The above breaks down as follows:
	//acct1.SetUsername("mbarakat");
	//SetUsername() returns a reference to the current object (or the address of the current object)
	//which sets us up for the second function call in the chain.
	//acct1.GeneratePassword()

	//If we did the above in two steps, it would look like
//	acct1.SetUsername("mbarakat");
//	acct1.GeneratePassword();
	   
	acct1.showUsernamePassword();
//	acct1.destroy();

	return 0;
}//acct1 is now out of scope, it will be deleted