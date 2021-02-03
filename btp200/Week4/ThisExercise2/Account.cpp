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

void Account::SetUsername(std::string username) {
	if (username.size() > 0) {
		this->username = username;
	}
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

void Account::GetPassword(char *password) const {
	strcpy(password, this->password);
}


void Account::showUsernamePassword() const {
	cout << "The username for " << name << " is " << username << endl;
	cout << "The password is " << password << endl;
}

void Account::CopyAccount(Account& acct) {//acct = acct2
	acct.name = this->name;//acct2.name = acct1->name
	acct.age = this->age;//acct2.age = acct1->age
	acct.username = this->username;//acct2.username = acct1->username
	acct.password = new char[strlen(this->password) + 1];
	strcpy(acct.password, this->password);
	//strcpy(acct2.password, acct1->password);
}


void Account::destroy() {
	if (password != nullptr) {//clean up
		delete password;
		password = nullptr;
	}
	delete this;//An object of type Account now destroys itself
}

Account::~Account() {
	if (password != nullptr) {
		delete password;
		password = nullptr;
	}
}

/*int GetStrength(Account acct) {
	int strength = 0;
	char password[64];
	acct.GetPassword(password);
	int len = strlen(password);
	for (int i = 0; i < len; ++i) {
		if (isalnum(password[i])) {
			strength += 1;
		}
		else {
			strength += 2;
		}
	}
	return strength;
}*/
