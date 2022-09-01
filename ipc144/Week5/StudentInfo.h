//StudentInfo.h - declarations for student information

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define MAX_STR 32
#define NUM_MARKS 4

struct StudentInfo {//declares a type of struct StudentInfo 
	char lastName[MAX_STR];
	int studentId;
	int marks[NUM_MARKS];
	float average;
	float scholarship;
};