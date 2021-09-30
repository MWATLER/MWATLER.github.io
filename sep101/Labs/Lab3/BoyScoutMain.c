//BoyScoutMain.c - main program for boy scouts

#include <stdio.h>//standard C library, this is why we use <   >
#include "BoyScout.h"//my header file, I use "" for a relative path to the file

int main() {
	const int SIZE = 5;
	struct BoyScout boyScout[] = {
    	{"Billy Blackledge", 12, 1000123},
	    {"Carla Dixon", 6, 1000124},
    	{"Bashab Patel", 13, 1000125},
    	{"Erin Mark", 10, 1000126},
    	{"Mulopo Mbape", 11, 1000127}
	};

	int number;
	printf("Enter the number of someone to remove: ");
	scanf_s("%d", &number);
	int found = 0;
	for (int i = 0; i < SIZE && found==0; ++i) {
		if (boyScout[i].number == number) {
			found = 1;
			boyScout[i].number = 0;
		}
	}
	if (found == 0) {
		printf("Boyscout with number %d not found!\n", number);
	}
	printf("\n");

	for (int i = 0; i < SIZE; ++i) {
		//Print valid boyscouts only
		if (boyScout[i].number!=0) {
			printf("%s %d %d\n", 
				boyScout[i].name, boyScout[i].age, boyScout[i].number);
		}
	}
	printf("\n");

	printf("Enter someone new: ");
	found = 0;
	for (int i = 0; i < SIZE && found == 0; ++i) {
		if (boyScout[i].number == 0) {
			found = 1;
			printf("Name: ");
			scanf_s("%s", boyScout[i].name, MAX_STR);
			printf("Age: ");
			scanf_s("%d", &boyScout[i].age);
			printf("Number: ");
			scanf_s("%d", &boyScout[i].number);
		}
	}
	if (found == 0) {
		printf("No space in the array for the new boyscout!\n");
	}

	for (int i = 0; i < SIZE; ++i) {
		//Print valid boyscouts only
		if (boyScout[i].number != 0) {
			printf("%s %d %d\n",
				boyScout[i].name, boyScout[i].age, boyScout[i].number);
		}
	}
	   	  
	return 0;
}