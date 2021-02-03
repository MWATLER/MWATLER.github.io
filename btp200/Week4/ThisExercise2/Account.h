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
	void SetUsername(std::string username);
	~Account();
	void SetPassword(void);
	void GetPassword(char* password) const;
	void showUsernamePassword() const;
	void CopyAccount(Account& acct);
	void destroy();
};


//int GetStrength(Account acct);