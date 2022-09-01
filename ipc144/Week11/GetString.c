// GetString.c : This file contains the 'main' function. Program execution begins and ends there.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define LEN 21
#define MAX 255
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char fullName[LEN];

	printf("Enter your full name: ");
	gets_s(fullName, LEN);
	printf("Your full name is %s\n", fullName);
	printf("\nEnter 'c' to continue\n");
	while (getchar() != 'c');
	while (getchar() != '\n' );

	printf("Enter your full name: ");
//	memset(fullName, 0, LEN);
	fgets(fullName, LEN, stdin);
	printf("Your full name is %s\n", fullName);
	printf("\nEnter 'c' to continue\n");
	while (getchar() != 'c');

	FILE *fp = fopen("sample.txt", "r");
	if (fp != NULL) {
		char text[MAX];
		char *ret;
		do {
			ret = fgets(text, MAX, fp);
//			printf("%s\n", text);//fgets() also gets the carriage return at the end of each line
			printf("%s", text);
		} while (ret != NULL);
		fclose(fp);
	}
	printf("\nEnter 'c' to continue\n");

	return 0;
}
