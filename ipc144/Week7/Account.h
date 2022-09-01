//Account.h - header file for accounting application

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY
#define INTEREST_RATE 0.05f//Annual interest rate of 5%

struct Account {
	char name[33];//32 characters plus the NULL character
	int number;
	float balance;
};

//NOTE: "struct Account" has to be declared before the function declarations,
//      otherwise the function declarations would not know what "struct Account" is
int Deposit(struct Account* acc, float amount);
int Withdraw(struct Account* acc, float amount);
int AccumulateInterest(struct Account* acc, int years);