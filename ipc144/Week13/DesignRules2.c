//DesignRules2.c - A second set of code to demonstrate design rules

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DesignRules2.h"

//Put defines below includes if you can
#define NUM_COLLEGES 5//Separate words with a _

int main(void)
{
	int retVal = 0;

	struct College college[NUM_COLLEGES];//Should not use a magic number
	//See http://www.tcu.gov.on.ca/pepg/audiences/colleges/colindicator.html
	FILE* fp = fopen("CollegeInfo.txt", "r");
	if (fp == NULL) {
		printf("No colleges to analyze.\n");
		retVal = -1;//Should not return in the middle of a function
	}
	else {
		for (int i = 0; i < NUM_COLLEGES; ++i) {//Should not use a magic number
			fscanf(fp, "%s %lf %lf",
				college[i].name, &college[i].tuition, &college[i].employerSatisfaction);//Shorten your lines
		}

		int index = BestDeal(college, NUM_COLLEGES);//Should not use a magic number
		if (-1 == index) {//Switch the comparison around, to avoid the mistake index = -1
			printf("Error in the College information.\n");
		}//Put braces around your if statement when there is an else or else-if
		else {
			printf("The college with the best employer satisfaction to tuition ration is\n");
			printf("%s with an employer satisfaction of %.2lf and a tuition of %.2lf\n",
				college[index].name, college[index].employerSatisfaction, college[index].tuition);//Shorten your lines
		}
		fclose(fp);
    }

	return retVal;
}


int BestDeal(struct College coll[], int size)
{
	int indexBest=-1;//Separate words with a case change
	double bestDeal = 0;//Separate words with a case change

	for (int i = 0; i < size; ++i) {
		if (coll[i].employerSatisfaction > 0 && coll[i].tuition > 0) {
			double deal = coll[i].employerSatisfaction / coll[i].tuition;
			if (deal > bestDeal) {//Either put braces around the if-block
				indexBest = i;
			}
//   		if (deal > bestDeal) indexBest = i;//Or put the one line of code on the same line as the if
		}
	}
	return indexBest;
}
