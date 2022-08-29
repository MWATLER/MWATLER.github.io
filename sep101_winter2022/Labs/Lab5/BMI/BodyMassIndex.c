//BodyMassIndex.c - function definitions for body mass index

#include "BodyMassIndex.h"
/*
#define MAX_STR 32
#define NUM_PATIENTS 3

struct Person {
	char name[MAX_STR];
	int OHIP;
	double height;//cm's
	double weight;//kg's
	double BMI;
	char weightCategory[MAX_STR];
};

struct HealthCareProvider {
	char name[MAX_STR];
	struct Person patient[NUM_PATIENTS];
};
*/
double CalculateBMI(struct Person* person) {
	person->BMI = person->weight / (person->height * person->height);
	return person->BMI;
}

char* DetermineWeightCategory(struct Person* person) {//assumes BMI is known
	const double UNDERWEIGHT = 18.5;
	const double NORMALWEIGHT = 24.9;
	const double OVERWEIGHT = 29.9;
	if (person->BMI < UNDERWEIGHT) {
		strcpy(person->weightCategory, "Underweight");
	}
	else if (person->BMI < NORMALWEIGHT) {
		strcpy(person->weightCategory, "Normalweight");
	}
	else if (person->BMI < OVERWEIGHT) {
		strcpy(person->weightCategory, "Overweight");
	}
	else {
		strcpy(person->weightCategory, "Obese");
	}

	return person->weightCategory;
}

double CalculateAverageBMI(struct HealthCareProvider provider) {//assumes BMI's are known
	double runningTotal = 0.0;
	for (int i = 0; i < NUM_PATIENTS; ++i) {
		runningTotal += provider.patient[i].BMI;
	}
	return runningTotal / NUM_PATIENTS;
}