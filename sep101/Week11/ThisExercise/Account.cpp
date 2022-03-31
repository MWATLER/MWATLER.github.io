//Account.cpp - implementation of the Account class

#include "Account.h"

using namespace std;

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

Account &Account::SetUsername(std::string username) {
	if (username.size() > 0) {
		this->username = username;
	}
	return *this;
}

void Account::SetPassword(void) {
	int len = username.size();
	delete[] password;//delete password if it had been previously allocated
	password = new char[len+1];
//	strcpy(password, username.c_str());//if we simply wanted to copy username to password. The char array portion
	                                   //of a string can be accessed through the string's getter function c_str().
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
	delete this;//delete the current object. This will invoke the destructor of the current object
}

Account::~Account() {
	if (password != nullptr) {
		delete[] password;
		password = nullptr;
	}
}
