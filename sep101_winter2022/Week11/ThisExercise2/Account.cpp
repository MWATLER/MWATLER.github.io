//Account.cpp - implementation of the Account class

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>//strlen()
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

void Account::GeneratePassword(void) {
	int len = username.size();
	delete[] password;//in case this function is called more than once
	password = new char[len + 1];
	int i;
	for (i = 0; i < len; ++i) {
		password[i] = username.at(i) + 1;
	}
	password[i] = '\0';//the null terminator
}

void Account::showUsernamePassword() const {
	cout << "The username for " << name << " is " << username << endl;
	cout << "The password is " << password << endl;
}

void Account::CopyToAccount(Account& acct) {//the current object is acct1, acct is acct2
	if (this != &acct) {//do not copy to yourself
		acct.name = this->name;//acct2.name = acct1.name
		acct.age = this->age;//acct2.age = acct1.age
		acct.username = this->username;//acct2.username = acct1.username
		delete[] acct.password;//delete the password if it was previously allocated
		acct.password = new char[strlen(this->password) + 1];//+1 for the null terminator
		strcpy(acct.password, this->password);
	}
}

void Account::destroy() {
	if (password != nullptr) {
		delete password;
		password = nullptr;
	}
	delete this;//will invoke the destructor
}

Account::~Account() {//For acct1, we allocated the memory for it, therefore we
	                 //can deallocate the memory it occupied
	if (password != nullptr) {
		delete password;
		password = nullptr;
	}
}
