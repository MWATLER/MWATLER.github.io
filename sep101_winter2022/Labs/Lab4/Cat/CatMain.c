//CatMain.c - main function for the cat

#include <stdio.h>
#include "Cat.h"
/*
struct CatToy {
	char name[MAX_STR];
	char colour[MAX_STR];
	double cost;
};
struct Cat {
	char name[MAX_STR];
	int age;
	struct CatToy toy[MAX_TOYS];
	int numToys;
};*/
int main() {
	struct Cat theCat;
	InitializeInfo(&theCat);//the address of theCat is passed through

	//Enter info for the cat
	printf("Enter the cat's name: ");
	scanf_s("%s", theCat.name, MAX_STR);
	printf("Enter the cat's age: ");
	scanf_s("%d", &theCat.age);
	printf("How many toys does this cat have? (max 3) ");
	scanf_s("%d", &theCat.numToys);
	for (int i = 0; i < theCat.numToys; ++i) {//Enter info for all cat toys
		printf("Enter the toy's name: ");
		scanf_s("%s", theCat.toy[i].name, MAX_STR);
		printf("Enter the toy's colour: ");
		scanf_s("%s", theCat.toy[i].colour, MAX_STR);
		printf("Enter the toy's cost: $");
		scanf_s("%lf", &theCat.toy[i].cost);
	}

	double theAverage = 0.0;
	int ret = GetAverageCostPerToy(theCat.toy, theCat.numToys, &theAverage);
//  int GetAverageCostPerToy(struct CatToy cattoy[], int len, double* average);
	PrintInfo(theCat);//is the address of theCat passed through, or just its values?
//  void PrintInfo(struct Cat cat);

	if (ret == 0) {
		printf("The average cost of the toys is $%.2lf\n", theAverage);
	}
	else {
		printf("Unable to calculate the average\n");
	}

	return 0;
}
