//College.c - function definitions for a College

#include "College.h"

int CalculateSatisfactionToTuitionRatio(struct College* college) {//pass by address
	int retVal = 0;
	//employer satisfaction should be between 0 and 10
	//tuition should be positive
	if (college->employerSatisfaction < 0 ||
		college->employerSatisfaction>10 ||
		college->tuition <= 0) {
		retVal = -1;
	}
	else {
		college->satisfactionToTuitionRatio = college->employerSatisfaction / college->tuition;
	}
	return retVal;
}

void PrintReport(struct College college) {
	printf("%s is located at %s.\n", college.name, college.address);
	printf("It has an annual tuition of $%.2lf and an employer satisfaction of %.3lf\n",
		college.tuition, college.employerSatisfaction);
	printf("and an employer satisfaction to tuition ratio of %.6lf.\n", college.satisfactionToTuitionRatio);
	printf("Based on its tuition and employer satisfaction, this college is ranked #%d on the list of colleges.\n\n",
		college.ranking);
}

void utilClearInputBuffer() {
	while (getchar() != '\n');
}