//Student.h - class declaration for student marks

#include <iostream>

/* This is what we had for the C language */
/*
#define BUF_LEN 64
#define MAX_MARKS 6

#include <stdbool.h>

struct Student {
	char name[BUF_LEN];
	int year;
	int mark[MAX_MARKS];
	int numMarks;
	double average;
};

double CalculateAveragePassByValue(struct Student student);
bool CalculateAveragePassByAddress(struct Student *student);
bool CalculateAverages(struct Student *student, int length);
*/

/* This is what we have for C++ */
#define MAX_MARKS 6

class Student {
	std::string name;
	int year;
	int mark[MAX_MARKS];
	int numMarks;
	double average;
public:
	//Setter functions, values can be validated before setting
	bool SetName(std::string);
	bool SetYear(int);
	bool SetMarks(int*, int);//will set numMarks and will set the array mark[]
	//Getter functions, a value is returned without being changed. To enforce this, we declare these functions as const.
	std::string GetName() const;
	double GetAverage() const;
	//These have access to all the private variables inside class Student
	void CalculateAverage();
	void PrintReport();
};
