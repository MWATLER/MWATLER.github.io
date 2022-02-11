//Cat.c - function definitions for a cat

#include <stdio.h>
#include "Cat.h"
/*struct CatToy {
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
void InitializeInfo(struct Cat* cat) {//InitializeInfo(&theCat);
	                                //*cat in InitializeInfo points to the address of theCat in main()
	cat->name[0] = '\0';//empty string
	                    //cat is a pointer to struct Cat, we access the elements through the -> notation
	cat->age = 0;
	for (int i = 0; i < MAX_TOYS; ++i) {//initialize each of the cat toys
		cat->toy[i].name[0] = '\0';//empty string
		cat->toy[i].colour[0] = '\0';//empty string
		cat->toy[i].cost = 0.00;
	}
	cat->numToys = 0;
}

//struct Cat theCat;
//double theAverage;
//int ret=GetAverageCostPerToy(theCat.toy, theCat.numToys, &theAverage);
int GetAverageCostPerToy(const struct CatToy cattoy[], int len, double* average) {
	int retVal = 0;//error status variable
	double runningTotal = 0.0;//used in calculating the average
	for (int i = 0; i < len && retVal==0; ++i) {
		if (cattoy[i].cost < 0) retVal = -1;//validate the cost
		else runningTotal += cattoy[i].cost;
	}
	if (retVal == 0) *average = runningTotal / len;//whatever I do to *average in GetAverageCostPerToy
	                                               //I also do to theAverage in main.
	                                               //This is because *average points to the same address
	                                               //as theAverage
	return retVal;
}

//PrintInfo(theCat);
void PrintInfo(struct Cat cat) {//any changes to cat in PrintInfo will not affect theCat in main()
	printf("\n%s is %d years old and has %d of toys. They are:\n",
		cat.name, cat.age, cat.numToys);
	for (int i = 0; i < cat.numToys; ++i) {
		printf("%s is %s and costs $%.2lf\n",
			cat.toy[i].name, cat.toy[i].colour, cat.toy[i].cost);
	}
}
/*struct CatToy {
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