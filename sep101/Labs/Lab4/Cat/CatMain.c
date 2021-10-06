//CatMain.c - main function for the cat

#include <stdio.h>
#include "Cat.h"

int main() {
	struct Cat cat;
	InitializeInfo(&cat);

	printf("Enter the cat's name: ");
	scanf_s("%s", cat.name, MAX_STR);
	printf("Enter the cat's age: ");
	scanf_s("%d", &cat.age);
	printf("How many toys does the cat have? (max 3): ");
	scanf_s("%d", &cat.numToys);
	for (int i = 0; i < cat.numToys; ++i) {
		printf("Enter the toy's name: ");
		scanf_s("%s", cat.toy[i].name, MAX_STR);
		printf("Enter the toy's colour: ");
		scanf_s("%s", cat.toy[i].colour, MAX_STR);
		printf("Enter the toy's cost: $");
		scanf_s("%lf", &cat.toy[i].cost);
	}

	double averageCost = 0.0;
	int ret = GetAverageCostPerCat(cat.toy, cat.numToys, &averageCost);
	PrintInfo(cat);
	printf("The average cost of the toys is $%.2lf\n", averageCost);

	return 0;
}
