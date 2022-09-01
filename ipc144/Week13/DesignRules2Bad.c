//DesignRules2Bad.c - A second set of code to demonstrate design rules

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DesignRules2Bad.h"

int main(void)
{
	struct College college[5];
	//See http://www.tcu.gov.on.ca/pepg/audiences/colleges/colindicator.html
	FILE* fp = fopen("CollegeInfo.txt", "r");
	if (fp == NULL) {
		printf("No colleges to analyze.\n");
		return -1;
	}
	for (int i = 0; i < 5; ++i) {
		fscanf(fp, "%s %lf %lf", college[i].name, &college[i].tuition, &college[i].empsat);
	}

	int index = CollegeSat(college, 5);
	if (index == -1)
		printf("Error in the College information.\n");
	else {
		printf("The college with the best employer satisfaction to tuition ration is %s with an employer satisfaction of %.2lf and a tuition of %.2lf\n", college[index].name, college[index].empsat, college[index].tuition);
	}

	fclose(fp);
	return 0;
}


int CollegeSat(struct College coll[], int size)
{
	int indexbest = -1;
	double bestdeal = 0;

	for (int i = 0; i < size; ++i) {
		if (coll[i].empsat > 0 && coll[i].tuition > 0) {
			double deal = coll[i].empsat / coll[i].tuition;
			if (deal > bestdeal)
				indexbest = i;
		}
	}

	return indexbest;
}
