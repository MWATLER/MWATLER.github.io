//Account.cpp - implementation of the Account class

#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"

using namespace std;

Account::Account() {
	this->name = "";
	this->age = 0.0;
	this->username = "";
	this->password = nullptr;
}

Account::Account(std::string name, double age) {
	this->name = "";
	this->age = 0.0;
	this->username = "";
	this->password = nullptr;
	if (name.size() > 0) {
		this->name = name;
	}
	if (age > 0) {
		this->age = age;
	}
}

Account& Account::SetUsername(std::string username) {
	if (username.size() > 0) {
		this->username = username;
	}
	return *this;
}

void Account::SetPassword(void) {
	int len = username.size();
	if (password != nullptr) delete[] password;
	password = new char[len + 1];
	int i;
	for (i = 0; i < len; ++i) {
		password[i] = username.at(i) + 1;
	}
	password[i] = '\0';
}

void Account::showUsernamePassword() const {
	cout << "The username for " << name << " is " << username << endl;
	cout << "The password is " << password << endl;
}

void Account::CopyAccount(Account& acct) {//*this points to acct1, acct is a reference to acct2
	//This function performs a "deep" copy of everything in acct1 to acct2
	acct.name = this->name;//acct2.name = acct1.name
	acct.age = this->age;
	acct.username = this->username;
//	acct.password = this->password;//This actually means that password for acct2 is pointing to the password of acct1
	acct.password = new char[strlen(this->password) + 1];//strlen() returns the length of a string (char array)
	                                                     //we need to add 1 to accommodate for the null terminator
	strcpy(acct.password, this->password);//copies the characters from this->password to acct.password
}

void Account::destroy() {
	if (password != nullptr) {//delete password only if it actually points to allocated memory
		delete[] password;
		password = nullptr;
	}
	delete this;//delete acct1 from inside the class
}

Account::~Account() {
	if (password != nullptr) {//if password has already been deallocated, it will not be deallocated a second time
		delete[] password;
		password = nullptr;
	}
}
