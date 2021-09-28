//EmployeeInfo.h: header file to demonstrate structures

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY
#define MAX_STR 30

struct EmployeeInformation {
	char firstName[MAX_STR], lastName[MAX_STR];
	int age;
	float salary;//annual salary
	int yearEmployed;
	/*	char address[32];
		float bonuses;
		int homePhone;
		int employeeId;
		double incomeTaxCredits;*/
};