// ChangeCase.cpp : Source code for changing the case of all letters in a file
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main()
{
	int err = 0;
	char c;
	FILE* fpr = fopen("parrot.txt", "r");
	FILE* fpw = fopen("parrotLower.txt", "w");
	if (fpr == NULL) {
		printf("Cannot open parrot.txt.\n");
		err = -1;
	}
	if (fpw == NULL) {
		printf("Cannot open parrotLower.txt.\n");
		err = -1;
	}
	if (fpr != NULL && fpw != NULL) {
		do {
			c = fgetc(fpr);
			c = tolower(c);
//			fputc(c, fpw);
			if (feof(fpr) == 0) fputc(c, fpw);
		} while (feof(fpr) == 0);
	}
	if (fpr != NULL) fclose(fpr);
	if (fpw != NULL) fclose(fpw);
	return err;
}