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

void Account::CopyAccount(Account& acct) {
	acct.name = this->name;
	acct.age = this->age;
	acct.username = this->username;
	acct.password = new char[strlen(this->password) + 1];
	strcpy(acct.password, this->password);
}


void Account::destroy() {
	if (password != nullptr) {
		delete password;
		password = nullptr;
	}
	delete this;
}

Account::~Account() {
	if (password != nullptr) {
		delete password;
		password = nullptr;
	}
}
