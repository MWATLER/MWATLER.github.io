//Account.h - Header file for account information

#include<iostream>

class Account {
	std::string name;
	double age;
	std::string username;
	char* password;

public:
	Account();
	Account(std::string name, double age);
	Account& SetUsername(std::string username);
	void GeneratePassword(void);
	void showUsernamePassword() const;
	void CopyToAccount(Account& acct);
	void destroy();
	~Account();
};