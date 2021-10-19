//CollegeMain.c - the main function for a college

#include <stdio.h>
#include "College.h"

#define NUM_COLLEGES 5

int main() {
	struct College college[NUM_COLLEGES] = { 0 };

	int ret = 0;

	for (int i = 0; i < NUM_COLLEGES && ret==0; ++i) {
		printf("\nEnter the name for the college: ");
		scanf_s("%[^\n]s", college[i].name, MAX_STR);
		printf("Enter the address for %s: ", college[i].name);
		utilClearInputBuffer();
		scanf_s("%[^\n]s", college[i].address, MAX_STR);
		printf("Enter the tuition for %s: ", college[i].name);
		scanf_s("%lf", &college[i].tuition);
		printf("Enter the employer satisfaction ratio (0-10) for %s: ", college[i].name);
		scanf_s("%lf", &college[i].employerSatisfaction);
		ret = CalculateSatisfactionToTuitionRatio(&college[i]);
		if (ret != 0) printf("Invalid data for %s. Aborting...\n", college[i].name);
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
		for (int i = 0; i < NUM_COLLEGES; ++i) {
			PrintReport(college[i]);
		}
	}

	return ret;
}