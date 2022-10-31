//Student.h - structure declaration and function prototypes for student marks

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
bool CalculateAveragePassByAddress(struct Student *student);//preferable
bool CalculateAverages(struct Student *student, int length);
