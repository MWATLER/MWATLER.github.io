//Account.h - Header file for account information

#include<iostream>

class Account {
	std::string name;
	double age;
	std::string username;
	char* password;

public:
	Account(std::string name, double age);
	Account &SetUsername(std::string username);
	~Account();
	void SetPassword(void);
	void showUsernamePassword() const;
	void destroy();
};