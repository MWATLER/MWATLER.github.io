//IncomeTax.c - program for income taxes

#define _CRT_SECURE_NO_WARNINGS
#define NUM_CLIENTS 3
#include <stdio.h>
#include "IncomeTax.h"

int main(void) {
	struct Person person[NUM_CLIENTS];

    //Prompt for user input
	for (int i = 0; i < NUM_CLIENTS; ++i) {
		printf("\n");
		printf("Enter the name for person %d: ", i + 1);
		scanf("%[^\n]s", person[i].name);//scan to the end of the line
		while (getchar() != '\n');//get rid of extra characters in the input buffer
		printf("Enter %s's social insurance number: ", person[i].name);
		scanf("%d", &person[i].sin);
		printf("Enter %s's annual income: $", person[i].name);
		scanf("%f", &person[i].annualIncome);
		printf("Enter %s's charitable donations: $", person[i].name);
		scanf("%f", &person[i].donations);
		printf("Enter %s's dependencies (children under 18): ", person[i].name);
		scanf("%d", &person[i].dependencies);
		printf("Enter %s's RRSP contributions: $", person[i].name);
		scanf("%f", &person[i].rrspContribution);
		CalculateDeductible(&person[i]);
		CalculateIncomeTax(&person[i]);
		while (getchar() != '\n');//get rid of extra characters in the input buffer
	}

	//Print a report for all the clients
	for (int i = 0; i < NUM_CLIENTS; ++i) {
		printf("\n");
		printf("%s with social insurance number %9d has an annual income of $%.2f.\n", person[i].name, person[i].sin, person[i].annualIncome);
		printf("%s has deductibles worth $%.2f and will have to pay $%.2f of income tax.\n", person[i].name, person[i].deductibles, person[i].incomeTax);
	}

	return 0;
}

void CalculateDeductible(struct Person* person) {
	person->deductibles = person->donations;
	person->deductibles += (float)1000.0 * person->dependencies;
	person->deductibles += (float)0.22 * person->rrspContribution;
}

void CalculateIncomeTax(struct Person* person) {
	float incomeAfterDeductibles = person->annualIncome - person->deductibles;
	if (incomeAfterDeductibles > 100000.0) {
		person->incomeTax = (float)0.45 * incomeAfterDeductibles;
	}
	else if (incomeAfterDeductibles > 50000.00) {
		person->incomeTax = (float)0.35 * incomeAfterDeductibles;
	}
	else if (incomeAfterDeductibles > 25000.00) {
		person->incomeTax = (float)0.25 * incomeAfterDeductibles;
	}
	else {
		person->incomeTax = (float)0.0;
	}
}