//College.h - declarations for a College

#ifndef _COLLEGE_H_
#define _COLLEGE_H_

#define NUM_COLLEGES 4
#define MAX_STR 64

struct College {
	char name[MAX_STR];
	char address[MAX_STR];
	double tuition;
	double employerSatisfaction;
	double satisfactionToTuitionRatio;
	int ranking;
};

void utilClearInputBuffer();
int CalculateSatisfactionToTuitionRatio(struct College* college);
void DetermineRanking(struct College* college);
void PrintReport(struct College college);

#endif//_COLLEGE_H