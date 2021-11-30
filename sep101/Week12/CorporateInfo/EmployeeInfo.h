//EmployeeInfo.h - structure declaration for employee information

#define BUFSIZE 255

struct EmployeeInfo {
	char name[BUFSIZE];
	char position[BUFSIZE];
	double salary;
	double age;
};