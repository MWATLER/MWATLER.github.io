// PutString.c : This file contains the 'main' function. Program execution begins and ends there.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	const char name[31] = "My name is Arnold";
	FILE *fp = fopen("arnold.txt", "w");

	puts(name);
	fputs(name, fp);
	fclose(fp);

	return 0;
}