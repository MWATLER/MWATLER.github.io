// StringLimit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define STRINGLENGTH 16
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char fullName[STRINGLENGTH];

	printf("Enter the full name: ");
	scanf("%[^\n]", fullName);

	printf("The address of fullName is 0x%p\n", fullName);

	int len1 = strlen(fullName);
	printf("\n");
	printf("The length of fullName is %d\n", len1);
	printf("\n");
	for (int i = 0; i <= len1; ++i) {
//		printf("address:0x%p  value:0x%x,%c\n", (fullName + i), *(fullName + i), *(fullName + i));
		printf("address:0x%p  value:0x%x,%c\n",
			&fullName[i], fullName[i], fullName[i]);
	}

	printf("\nPress 'c' to continue: ");
	while (getchar() != 'c');

	memset(fullName, 0, STRINGLENGTH);
	printf("Enter the full name: ");
	scanf(" %15[^\n]", fullName);

	printf("The address of fullName is 0x%p\n", fullName);

	len1 = strlen(fullName);
	printf("\n");
	printf("The length of fullName is %d\n", len1);
	printf("\n");
	for (int i = 0; i < STRINGLENGTH; ++i) {
		printf("address:0x%p  value:0x%x,%c\n",
			(fullName + i), *(fullName + i), *(fullName + i));
	}

}
