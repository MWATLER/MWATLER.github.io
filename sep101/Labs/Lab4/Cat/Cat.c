//Cat.c - function definitions for a cat

#include <stdio.h>
#include "Cat.h"

void InitializeInfo(struct Cat* cat) {//InitializeInfo(&theCat);
	cat->name[0] = '\0';
	cat->age = 0;
	for (int i = 0; i < MAX_TOYS; ++i) {//initialize each of the cat toys
		cat->toy[i].name[0] = '\0';
		cat->toy[i].colour[0] = '\0';
		cat->toy[i].cost = 0.00;
	}
	cat->numToys = 0;
}

//struct Cat theCat;
//double theAverage;
//int ret=GetAverageCostPerCat(theCat.toy, theCat.numToys, &theAverage);
int GetAverageCostPerCat(struct CatToy cattoy[], int len, double* average) {
	int retVal = 0;//error status variable
	double runningTotal = 0.0;//used in calculating the average
	for (int i = 0; i < len && retVal==0; ++i) {
		if (cattoy[i].cost < 0) retVal = -1;
		else runningTotal += cattoy[i].cost;
	}
	if (retVal == 0) *average = runningTotal / len;

	return retVal;
}

void PrintInfo(struct Cat cat) {
	printf("\n%s is %d years old and has %d of toys. They are:\n",
		cat.name, cat.age, cat.numToys);
	for (int i = 0; i < cat.numToys; ++i) {
		printf("%s is %s and costs $%.2lf\n",
			cat.toy[i].name, cat.toy[i].colour, cat.toy[i].cost);
	}
}
