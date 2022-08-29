//CorporateInfo.h - header file for corporate information

#define NUM_EMPLOYEES 12
#define INVALID_VALUE -1
#define _CRT_SECURE_NO_WARNINGS

#define BUFSIZE 255

struct EmployeeInfo {
	char name[BUFSIZE];
	char position[BUFSIZE];
	double salary;
	double age;
};
/*
struct CorporateInfo {
	struct EmployeeInfo employee[NUM_EMPLOYEES];
	double averageSalary;
	double averageAge;
	double maximumSalary;//the maximum salary
	int indexMaximumSalary;//index to the Employee with the maximum salary
};

bool GetAverageSalary(struct CorporateInfo* corp);
bool GetAverageAge(struct CorporateInfo* corp);
bool GetMaximumSalary(struct CorporateInfo* corp);
*/
class CorporateInfo {
public:
	struct EmployeeInfo employee[NUM_EMPLOYEES];
	double averageSalary;
	double averageAge;
	double maximumSalary;//the maximum salary
	int indexMaximumSalary;//index to the Employee with the maximum salary
	bool GetAverageSalary();
	bool GetAverageAge();
	bool GetMaximumSalary();
};
