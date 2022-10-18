//Student.h - structure declaration and function prototypes for student marks

#define BUF_LEN 64
#define MAX_MARKS 6

#include <stdbool.h>//bool

struct Student {
	char name[BUF_LEN];
	int year;
	int mark[MAX_MARKS];
	int numMarks;
	double average;
};

double CalculateAveragePassByValue(const struct Student* student);//effectively pass by value, faster than pass by value
bool CalculateAveragePassByAddress(struct Student *student);//preferred
bool CalculateAverages(struct Student *student, int length, double* average);
