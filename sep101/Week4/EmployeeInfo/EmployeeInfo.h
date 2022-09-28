//EmployeeInfo.h: header file to demonstrate structures

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define LEN 30

struct EmployeeInformation {
	char firstName[LEN], lastName[LEN];
	int age;
	float salary;//annual salary
	int yearEmployed;
/*	char address[LEN];
	float bonuses;
	int homePhone;
	int employeeId;
	double incomeTaxCredits;*/
};