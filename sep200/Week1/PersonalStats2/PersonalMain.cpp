// PersonalMain.cpp - main program for personal statistics

#include <iostream>
#include "Insurance.h"
#include "Pension.h"

using namespace std;

int age;

int main() {
	cout << "Please enter your age: ";
	cin >> age;
	double monthlyInsurance = CalculateInsurance();
	double monthlyPension = CalculatePension();

	cout << "Your monthly insurance is $" << monthlyInsurance << " and your monthly pension is $" << monthlyPension << endl;

	return 0;
}
