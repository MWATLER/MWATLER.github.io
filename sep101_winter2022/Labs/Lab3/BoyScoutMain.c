//BoyScoutMain.c - main program for boy scouts

#include <stdio.h>
#include "BoyScout.h"

int main() {
	const int SIZE = 5;
/*	struct BoyScout {
		char name[MAX_STR];
		int age;
		int number;
	};*/
	struct BoyScout boyScout[] = {
		{"Billy Blackledge", 12, 1000123},//index 0
		{"Carla Dixon", 6, 1000124},//index 1
		{"Bashab Patel", 13, 1000125},//index 2
		{"Erin Mark", 10, 1000126},//index 3
		{"Mulopo Mbape", 11, 1000127},//index 4
	};

	int number;
	printf("Enter the number of someone to remove: ");
	scanf_s("%d", &number);
	int found = 0;//the found flag
	for (int i = 0; i < SIZE && found == 0; ++i) {
		if (boyScout[i].number == number) {
			found = 1;
			boyScout[i].number = 0;//number 0 indicates removal, will invalidate an entire row in the array
		}
	}

	printf("\n");
	for (int i = 0; i < SIZE; ++i) {
		if (boyScout[i].number != 0) {//print out the valid boy scouts
			printf("%s %d %d\n", boyScout[i].name, boyScout[i].age, boyScout[i].number);
		}
	}

	printf("\n");
	printf("Enter someone new\n");
	found = 0;//look for an empty spot in the array
	for (int i = 0; i < SIZE && found == 0; ++i) {
		if (boyScout[i].number == 0) {
			found = 1;
			printf("name: ");
			scanf_s("%s", boyScout[i].name, MAX_STR);//can only scan one string, not two
			printf("age: ");
			scanf_s("%d", &boyScout[i].age);
			printf("number: ");
			scanf_s("%d", &boyScout[i].number);
		}
	}

	for (int i = 0; i < SIZE; ++i) {
		if (boyScout[i].number != 0) {//print out the valid boy scouts
			printf("%s %d %d\n", boyScout[i].name, boyScout[i].age, boyScout[i].number);
		}
	}

	return 0;
}
