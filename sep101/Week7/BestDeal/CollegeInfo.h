//CollegeInfo - structure declaration for a college

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY

#include <stdbool.h>
#define MAX_STR 256

struct CollegeInfo {
	char name[MAX_STR];
	double tuition;
	double employerSatisfaction;//Choose a variable name that represents what it is
};

bool GetRatio(struct CollegeInfo coll, double* ratio);//Choose a function name that represents what it does
