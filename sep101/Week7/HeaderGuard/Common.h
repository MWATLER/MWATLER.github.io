//Common.h - common defines and structures
//         - demonstrates the usefulness of a header guard

#ifndef _COMMON_H_  //If the variable _COMMON_H_ does not exist  //_FILENAMEINCAPITALS_H_
#define _COMMON_H_  //Make the variable _COMMON_H_ exist

#include <stdio.h>
#define MAX_STR 64

struct StudentInfo {
	char name[MAX_STR];
	int age;
};

struct TeacherInfo {
	char name[MAX_STR];
	double salary;
};

void PrintError();
#endif// _COMMON_H_ //End of the #ifndef block
