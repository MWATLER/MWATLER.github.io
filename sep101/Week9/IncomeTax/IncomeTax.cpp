//IncomeTax.cpp - function definitions for the person class

#include "IncomeTax.h"

using namespace std;

string Person::GetName() const {
	return name;
}

bool Person::SetName(std::string _name) {
	bool ret = true;
	if (_name.size() == 0) {//validation
		ret = false;
	}
	else {
		name = _name;
	}
	return ret;
}

bool Person::SetSin(int _sin) {
	bool ret = true;
	if (_sin < 100000000 || sin > 999999999) {//validation
		ret = false;
	}
	else {
		sin = _sin;
	}
	return ret;
}

bool Person::SetAnnualIncome(float _income) {
	bool ret = true;
	if (_income < 0) {//validation
		ret = false;
	}
	else {
		annualIncome = _income;
	}
	return ret;
}

bool Person::SetDonations(float _donations) {
	bool ret = true;
	if (_donations < 0) {//validation
		ret = false;
	}
	else {
		donations = _donations;
	}
	return ret;
}

bool Person::SetDependencies(int _depend) {
	bool ret = true;
	if (_depend < 0) {//validation
		ret = false;
	}
	else {
		dependencies = _depend;
	}
	return ret;
}

bool Person::SetRrspContributions(float _contrib) {
	bool ret = true;
	if (_contrib < 0) {//validation
		ret = false;
	}
	else {
		rrspContribution = _contrib;
	}
	return ret;
}
//The C way:
/*void CalculateDeductible(struct Person* person) {
	person->deductibles = person->donations;
	person->deductibles += (float)1000.0 * person->dependencies;
	person->deductibles += (float)0.22 * person->rrspContribution;
}*/
//The C++ way:
void Person::CalculateDeductible() {//cannot be a const function because we are
	deductibles = donations;        //making changes to the variable "deductibles"
	deductibles += (float)1000.0 * dependencies;
	deductibles += (float)0.22 * rrspContribution;
}
void Person::CalculateIncomeTax() {
	float incomeAfterDeductibles = annualIncome - deductibles;
	if (incomeAfterDeductibles > 100000.0) {
		incomeTax = (float)0.45 * incomeAfterDeductibles;
	}
	else if (incomeAfterDeductibles > 50000.00) {
		incomeTax = (float)0.35 * incomeAfterDeductibles;
	}
	else if (incomeAfterDeductibles > 25000.00) {
		incomeTax = (float)0.25 * incomeAfterDeductibles;
	}
	else {
		incomeTax = (float)0.0;
	}
}

void Person::PrintReport() {
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << name << " with social insurance number " << sin << " has an annual income of $" << annualIncome << endl;
	cout << name << " has deductibles worth $" << deductibles << " and will have to pay $" << incomeTax << " of income tax." << endl;
}