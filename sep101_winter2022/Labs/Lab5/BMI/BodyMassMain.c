//BodyMassMain.c - main program for the body mass index

#include <stdio.h>
#include "BodyMassIndex.h"
#include "Utilities.h"

int main() {
	struct HealthCareProvider provider;

	printf("Enter the name of the health care provider: ");
	scanf_s("%[^\n]s", provider.name, MAX_STR);//I want to scan an entire line
	for (int i = 0; i < NUM_PATIENTS; ++i) {
		printf("Enter the name for patient %d: ", i+1);
		utilClearInputBuffer();//clear out the carriage return of the previous scanf. This is necessary when scanning strings
		scanf_s("%[^\n]s", provider.patient[i].name, MAX_STR);//I want to scan an entire line

		printf("Enter the OHIP number for patient %d: ", i + 1);
		scanf_s("%d", &provider.patient[i].OHIP);

		printf("Enter the height (m) of patient %d: ", i + 1);
		scanf_s("%lf", &provider.patient[i].height);

		printf("Enter the weight (kg) of patient %d: ", i + 1);
		scanf_s("%lf", &provider.patient[i].weight);

		CalculateBMI(&provider.patient[i]);
		DetermineWeightCategory(&provider.patient[i]);
		printf("\n");
	}

	//Print a report
	printf("The %s health care provider has the following patients:\n", provider.name);
	for (int i=0; i < NUM_PATIENTS; ++i) {
		printf("%s has a BMI of %lf and is %s\n", 
			provider.patient[i].name, provider.patient[i].BMI, provider.patient[i].weightCategory);
	}
	printf("The average BMI of all three patients is %lf\n", CalculateAverageBMI(provider));

	return 0;
}