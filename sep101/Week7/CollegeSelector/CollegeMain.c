//CollegeMain.c - the main function for a college

#include <stdio.h>
#include "College.h"

#define NUM_COLLEGES 4

int main() {
	int ret = 0;
	/*
	struct College {
		char name[MAX_STR];
		char address[MAX_STR];
		double tuition;
		double employerSatisfaction;
		double tuitionToRatingRatio;
		int ranking;
	};
	*/

	struct College college[NUM_COLLEGES] = { 0 };
	for (int i = 0; i < NUM_COLLEGES && ret==0; ++i) {
		printf("\nEnter the name for college %d: ", i+1);
		scanf_s("%[^\n]s", college[i].name, MAX_STR);
		utilClearInputBuffer();
		printf("Enter the address for %s: ", college[i].name);
		scanf_s("%[^\n]s", college[i].address, MAX_STR);
		printf("Enter the tuition for %s: ", college[i].name);
		scanf_s("%lf", &college[i].tuition);
		printf("Enter the employer satisfaction/10 for %s: ", college[i].name);
		scanf_s("%lf", &college[i].employerSatisfaction);
		ret = CalculateSatisfactionToTuitionRatio(&college[i]);
		if (ret != 0) printf("There is something wrong with the data for %s. Aborting...\n", college[i].name);
		utilClearInputBuffer();
	}

	if (ret == 0) {
		//Get the ranking for each college.
		//This can be done by assuming the rank is one, then incrementing rank whenever another college has a better employerSatisfaction
		for (int i = 0; i < NUM_COLLEGES; ++i) {
			college[i].ranking = 1;
			for (int j = 0; j < NUM_COLLEGES; ++j) {
				if (i != j) {
					if (college[i].satisfactionToTuitionRatio < college[j].satisfactionToTuitionRatio)
						++college[i].ranking;
				}
			}
		}

		//print out the information for each college
		for (int i = 0; i < NUM_COLLEGES; ++i) {
			PrintReport(college[i]);
		}
	}

	return ret;
}