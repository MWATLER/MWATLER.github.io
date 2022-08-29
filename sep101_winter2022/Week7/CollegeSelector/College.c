//College.c - function definitions for a College

#include <stdio.h>
#include "College.h"

int CalculateSatisfactionToTuitionRatio(struct College* college) {
	int retVal = 0;
	if (college->employerSatisfaction <= 0 || college->employerSatisfaction > 10 || college->tuition <= 0) retVal = -1;
	else college->satisfactionToTuitionRatio = college->employerSatisfaction / college->tuition;
	return retVal;
}

void DetermineRanking(struct College* college) {
	//Get the ranking for each college.
	//This can be done by assuming the rank is one, then incrementing rank whenever another college has a better employerSatisfaction
	for (int i = 0; i < NUM_COLLEGES; ++i) {
		college[i].ranking = 1;
		for (int j = 0; j < NUM_COLLEGES; ++j) {
			if (i != j) {//don't compare to yourself
				if (college[i].satisfactionToTuitionRatio < college[j].satisfactionToTuitionRatio)
					++college[i].ranking;
			}
		}
	}
}

void PrintReport(struct College college) {
	printf("%s is located at %s.\n", college.name, college.address);
	printf("It has an annual tuition of $%.2lf and a employer satisfaction of %.3lf/10.\n", 
		college.tuition, college.employerSatisfaction);
	printf("Based on its tuition and employer satisfaction, this college is ranked #%d on the list of colleges.\n\n", 
		college.ranking);
}

void utilClearInputBuffer() {
	while (getchar() != '\n');
}