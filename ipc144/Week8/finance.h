// finance.h - header file for currency manipulations
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY

// 31-Oct-2018  M Watler: Created.
// 29-Oct-2019  M Watler: Added personal information to header comments.

//Variable prototypes
struct Currency {
	int dollars;
	int cents;
};

//Function prototypes
int AccountExpenser(struct Currency* curr, struct Currency cost);
int ExchangeRate(struct Currency* curr, double rate);

