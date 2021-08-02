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
