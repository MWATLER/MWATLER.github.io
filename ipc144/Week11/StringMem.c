// StringMem.c : This file contains the 'main' function. Program execution begins and ends there.
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
	char lastName1[STRINGLENGTH];
	char lastName2[STRINGLENGTH];

	printf("Enter the first last name: ");
	scanf("%15s", lastName1);
	printf("Enter the second last name: ");
	scanf("%15s", lastName2);

	printf("The address of lastName1 is 0x%p\n", lastName1);
	printf("The address of lastName2 is 0x%p\n", lastName2);

	int len1 = strlen(lastName1);
	int len2 = strlen(lastName2);
	printf("\n");
	printf("The length of string 1 is %d\n", len1);
	printf("The length of string 2 is %d\n", len2);
	printf("\n");
	for (int i = 0; i <= len1; ++i) {
		printf("address:0x%p  value:0x%x,%c\n",
			&lastName1[i], lastName1[i], lastName1[i]);
	}
	for (int i = 0; i <= len2; ++i) {
		printf("address:0x%p  value:0x%x,%c\n",
			(lastName2 + i), *(lastName2 + i), *(lastName2 + i));
	}

	printf("Press 'c' to continue: ");
	while(getchar()!='c');

	strcpy(lastName2, lastName1);
	printf("\n");
	printf("lastName1:\n");
	for (int i = 0; i < STRINGLENGTH; ++i) {
		printf("address:0x%p  value:0x%x,%c\n",
			(lastName1 + i), *(lastName1 + i), *(lastName1 + i));
	}
	printf("lastName2:\n");
	for (int i = 0; i < STRINGLENGTH; ++i) {
		printf("address:0x%p  value:0x%x,%c\n",
			(lastName2 + i), *(lastName2 + i), *(lastName2 + i));
	}



	return 0;
}
