//Account.cpp - implementation of the Account class

#include "Account.h"

using namespace std;

Account::Account(std::string name, double age) {
	//One use of the "this" pointer is to differentiate between a class
	//variable and a parameter passed through the function
	this->name = "";
	this->age = 0.0;
	this->username = "";
	this->password = nullptr;//this->password is a pointer. We usually initialize pointers
	                         //to point to nullptr if they are not yet pointing to allocated memory
	if (name.size() > 0) {
		this->name = name;//assign the class variable "name" to the parameter "name"
	} 
	if (age > 0) {
		this->age = age;//assign the class variable "age" to the parameter "age"
	}
}

Account &Account::SetUsername(std::string username) {
	if (username.size() > 0) {
		this->username = username;
	}
	return *this;//returns a reference to the current object!!
}

void Account::GeneratePassword(void) {
	int len = username.size();
	delete[] password;//delete password if it had been previously allocated
	password = new char[len+1];//+1 for the null terminator
//	strcpy(password, username.c_str());//if we simply wanted to copy username to password. The char array portion
	                                   //of a string can be accessed through the string's getter function c_str().
	int i;
	for (i = 0; i < len; ++i) {
		password[i] = username.at(i) + 1;//If username is  "mbarakat"
		                                 //the password is "ncbsblbu"
	}
	password[i] = '\0';//don't forget to add the null terminator at the end
}

void Account::showUsernamePassword() const {
	cout << "The username for " << name << " is " << username << endl;
	cout << "The password is " << password << endl;
}


void Account::destroy() {
	delete this;//delete the current object. This will invoke the destructor of the current object
	//In this example, I was not the one to allocate memory therefore I cannot be the one to delete it
}

Account::~Account() {//The operating system is the one to delete the object
	if (password != nullptr) {
		delete[] password;
		password = nullptr;
	}
}
