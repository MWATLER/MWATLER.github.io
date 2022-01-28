// CharArray.c : A simple program to demonstrate character arrays
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define NCHAR 17
#include <stdio.h>
#include <string.h>//strlen()

int main()
{
	char name[NCHAR + 1] = "My name is Arnold";//We need an extra character for the null terminator
	int len = strlen(name);//Gets the string length
	printf("The string has %d characters\n", len);
	printf("%s\n\n", name);
	for (int i = 0; i < NCHAR + 1; ++i) {
		printf("name[%2d]:%c %3d %3X\n", i, name[i], name[i], name[i]);
	}

	//	for (int i = 0; i < NCHAR + 1; ++i) name[i] = 0;//Clear out the memory

	printf("\nEnter your name: ");
	scanf_s("%s", name, NCHAR+1);
	len = strlen(name);
	printf("The string has %d characters\n", len);
	for (int i = 0; i < NCHAR + 1; ++i) {
		printf("name[%2d]:%c %3d %3x\n", i, name[i], name[i], name[i]);
	}
	/*
		printf("\n\n");
		for (int i = 0; i < NCHAR + 1; ++i) printf("%c", name[i]);
	*/
	return 0;
}
