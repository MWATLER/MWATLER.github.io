//IncomeTax.h - class declaration for income taxes

/* This is what we had for the C programming language */
/*
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
*/

/* This is the same applying classes. We put the functions that act on
   the structure person inside the class. */

//#define MAX_STR 32//No longer needed
#include <iostream>

class Person {
	//private: by default
	std::string name;
	int  sin;
	float annualIncome;
	float donations;
	int   dependencies;
	float rrspContribution;
	float deductibles;
	float incomeTax;
public:
	//Since the variables are private, we need "setter" functions to set their values.
	//This allows us to validate the entered values before setting them.
	bool SetName(std::string _name);
	bool SetSin(int _sin);
	bool SetAnnualIncome(float _income);
	bool SetDonations(float _donations);
	bool SetDependencies(int _depend);
	bool SetRrspContributions(float _contrib);
    //The following functions used to take struct Person as an argument
	//Since they are now all part of the same class, these functions
	//have direct access to the variables of class Person
	void CalculateDeductible();
	void CalculateIncomeTax();
	//This function also has access to all the variables of class Person
	void PrintReport();
};

//void utilClearInputBuffer();//No longer needed
