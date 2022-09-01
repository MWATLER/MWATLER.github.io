// WordCount.c : This file contains the 'main' function. Program execution begins and ends there.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const char filename[] = "GroceryList.txt";
int main()
{
	int err = 0;
	int charCount = 0;
	int stringCount = 0;
	int newlineCount = 0;
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		err = -1;
	}
	else {
		int c;
		char str[30];
		do {
			c = fgetc(fp);
			++charCount;
			if (c == '\n') ++newlineCount;
		} while (feof(fp) == 0);
		rewind(fp);
		int rc;
		do {
			rc = fscanf(fp, "%s", str);
			if (rc > 0) ++stringCount;
		} while (rc > 0);

		printf("The file %s has %d characters, %d strings, and %d lines\n",
			filename, charCount, stringCount, newlineCount);

		fclose(fp);
	}
	return err;
}
