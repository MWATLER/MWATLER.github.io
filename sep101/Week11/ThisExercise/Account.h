//Account.h - Header file for account information

#include<iostream>

class Account {
	std::string name;
	double age;
	std::string username;
	char* password;//we don't know the length of password at compile time

public:
	Account(std::string name, double age);
	Account &SetUsername(std::string username);
	void GeneratePassword(void);//generates a password based on the username
	void showUsernamePassword() const;
	void destroy();
	~Account();
};