//Account.cpp - implementation of the Account class

#include "Account.h"

using namespace std;

Account::Account(std::string name, double age) {
	this->name = "";
	this->age = 0.0;
	this->username = "";
	this->password = nullptr;
	if (name.size() > 0) {
		this->name = name;//I have distinguished between name passed as a 
		                  //parameter and name that belongs to an object of 
		                  //the Account class
	} 
	if (age > 0) {
		this->age = age;
	}
}

Account::Account() {
	this->name = "";
	this->age = 0.0;
	this->username = "";
	this->password = nullptr;
}

Account &Account::SetUsername(std::string username) {
	if (username.size() > 0) {
		this->username = username;
	}
	return *this;//*this actually refers to acct1 in main()
}

void Account::SetPassword(void) {
	int len = username.size();
	password = new char[len+1];
	int i;
	for (i = 0; i < len; ++i) {
		password[i] = username.at(i) + 1;//C++ string type. at(i) is the same as [i]
		                                 //username.at(i) is similar to username[i]
	}
	password[i] = '\0';
}

void Account::showUsernamePassword() const {
	cout << "The username for " << name << " is " << username << endl;
	cout << "The password is " << password << endl;
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
