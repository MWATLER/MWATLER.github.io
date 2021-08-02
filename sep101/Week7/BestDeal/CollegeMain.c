//CollegeMain.c - main code to determine which college offers the best satisfaction to tuition ratio

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "CollegeInfo.h"

//Put defines below includes if you can
#define NUM_COLLEGES 3

int main(void)
{
	int retVal = 0;
	double satisfactionTuitionRatio = 0.0;
	double bestRatio = 0.0;
	int bestRatioIndex = 0;
	struct CollegeInfo college[NUM_COLLEGES] = { 0 };//Should not use a magic number

	for (int i = 0; i < NUM_COLLEGES; ++i) {
		printf("Enter the name of the College: ");
		scanf("%[^\n]s", college[i].name);//scan to the end of the line
		printf("Enter the annual tuition: ");
		scanf("%lf", &college[i].tuition);
		do {
			printf("Enter the employer satisfaction with graduates from this college (0.0-10.0): ");
			scanf("%lf", &college[i].employerSatisfaction);
		} while (college[i].employerSatisfaction < 0 || college[i].employerSatisfaction>10);
		while (getchar() != '\n');//clear the input buffer ('\n' still remains in the input buffer)

		bool ret = GetRatio(college[i], &satisfactionTuitionRatio);
		if (ret && satisfactionTuitionRatio > bestRatio) {
			bestRatio = satisfactionTuitionRatio;
			bestRatioIndex = i;
		}
		printf("\n");//put a line between each set of inputs
    }

	//Report the best college
	printf("The college with the best ratio is %s, with emloyer satisfaction of %lf and tuition of %lf\n",
		college[bestRatioIndex].name, college[bestRatioIndex].employerSatisfaction, college[bestRatioIndex].tuition);
	
	return retVal;
}


bool GetRatio(struct CollegeInfo coll, double* ratio) {
	bool retVal = true;
	*ratio = coll.employerSatisfaction / coll.tuition;
	if (*ratio < 0) retVal = false;
	return retVal;
}
