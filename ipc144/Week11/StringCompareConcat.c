// StringCompareConcat.c : This file contains the 'main' function. Program execution begins and ends there.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char cell1[] = "4161112222";
	char cell2[] = "4162223333";

	int ret = strcmp(cell1, cell2);

	if (ret < 0) {
		printf("Cell1 %s is lexographically less than cell2 %s\n", cell1, cell2);
	}
	else if (ret == 0) {
		printf("Cell1 %s is lexographically equal to cell2 %s\n", cell1, cell2);
	}
	if (ret > 0) {
		printf("Cell1 %s is lexographically greater than cell2 %s\n", cell1, cell2);
	}

	printf("\nEnter 'c' to continue:");
	while (getchar() != 'c');

	int isValid = 1;

	do {
		printf("Enter cell1 (-1 to quit) : ");
		scanf("%10s", cell1);
		if (strcmp(cell1, "-1") == 0) {
			isValid = 0;
			printf("DONE\n");
		}
		else {
			printf("Enter cell2: ");
		    scanf("%10s", cell2);
			ret = strcmp(cell1, cell2);

			if (ret < 0) {
				printf("Cell1 %s is lexographically less than cell2 %s\n", cell1, cell2);
			}
			else if (ret == 0) {
				printf("Cell1 %s is lexographically equal to cell2 %s\n", cell1, cell2);
			}
			if (ret > 0) {
				printf("Cell1 %s is lexographically greater than cell2 %s\n", cell1, cell2);
			}
		}

	} while (isValid == 1);

	printf("\n");

	char firstName[21];
	char lastName[11];

	printf("Enter your first name: ");
	scanf("%10s", firstName);
	printf("Enter your last name: ");
	scanf("%10s", lastName);
	strcat(firstName, " ");
	strcat(firstName, lastName);

	printf("Your full name is %s\n", firstName);

	return 0;
}
