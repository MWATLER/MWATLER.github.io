//IncomeTax.h - header file for income taxes

#define MAX_STR 32

struct Person {
	char name[MAX_STR];
	int  sin;
	float annualIncome;
	float donations;
	int   dependencies;
	float rrspContribution;
	float deductibles;
	float incomeTax;
};

void utilClearInputBuffer();
void CalculateDeductible(struct Person* person);
void CalculateIncomeTax(struct Person* person);
/*We want to write software that will calculate your income tax based on your income 
and deductible expenses. We want to do this for three people.

Each person should enter his/her last name, social insurance number, annual income, 
and zero or more of the deductible expenses (charitable donations, number of children 
under 18, and RRSP contributions). From this data the income tax is calculated.*/