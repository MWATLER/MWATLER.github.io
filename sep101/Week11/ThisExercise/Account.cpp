//Account.cpp - implementation of the Account class

#include "Account.h"

using namespace std;

Account::Account(std::string name, double age) {
	this->name = "";//acct1.name
	this->age = 0.0;//acct1.age, etc...
	this->username = "";
	this->password = nullptr;
	if (name.size() > 0) {
		this->name = name;
	} 
	if (age > 0) {
		this->age = age;
	}
}

Account &Account::SetUsername(std::string username) {
	if (username.size() > 0) {
		this->username = username;
	}
	return *this;//effectively returning a reference to acct1
}

void Account::SetPassword(void) {
	int len = username.size();
	if (password != nullptr) delete[] password;//If there already is a password, destroy it, then allocate
	                                           //new memory for the new password
	password = new char[len+1];//As soon as you allocate, you must deallocate (usually in the destructor)
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


void Account::destroy() {
	if (password != nullptr) {
		delete[] password;
		password = nullptr;
	}
	delete this;
}

Account::~Account() {
	if (password != nullptr) {
		delete[] password;
		password = nullptr;
	}
}
