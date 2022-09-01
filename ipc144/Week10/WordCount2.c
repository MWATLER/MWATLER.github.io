// WordCount2.c : This file contains the 'main' function. Program execution begins and ends there.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const char filename[] = "GroceryListCSV.txt";
const char filenameStats[] = "GroceryListStats.txt";
int main()
{
	int err = 0;
	int charCount = 0;
	int stringCount = 0;
	int newlineCount = 0;
	FILE* fp = fopen(filename, "r");
	FILE* fps = fopen(filenameStats, "w");
	if (fp == NULL || fps==NULL) {
		if (fp != NULL) fclose(fp);
		if (fps != NULL) fclose(fps);
		err = -1;
	}
	else {
		int c;
		do {
			c = fgetc(fp);
			++charCount;
			if (c == ',' || c == ':') ++stringCount;
			if (c == '\n' || c == ':') {
				++newlineCount;
				int rc = fprintf(fps, " - %d characters %d strings %d lines\n",
					charCount, stringCount, newlineCount);
			}
			else {
				fputc(c, fps);
			}
		} while (c != ':');

		printf("The file %s has %d characters, %d strings, and %d lines\n",
			filename, charCount, stringCount, newlineCount);

		fclose(fp);
		fclose(fps);
	}
	return err;
}
