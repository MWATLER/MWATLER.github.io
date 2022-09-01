// GetLine.c : This file contains the 'main' function. Program execution begins and ends there.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// getline accepts a newline terminated
 // string s of up to max - 1 characters,
 // adds the null terminator and discards
 // the remaining characters in  the input
 // buffer including terminating character
 //
char *getline(char *s, int n)//char *s = firstName;
{                            //char *s = lastName;
	int i, c;
	int endLine = 0;
	for (i = 0;	endLine==0; i++) {
		c = getchar();
		if (i==(n-1) || c == (int)'\n') {//end of array OR carriage return
			endLine = 1;
			s[i] = '\0';
		}
		else {
			s[i] = c;
		}
	}
	//Clear out the input buffer
	while (n > 1 && c != EOF && c != (int)'\n') {
		c = getchar();
	}
	return c != EOF ? s : NULL;
}

int main(void)
{
	char first_name[11];
	char last_name[11];

	printf("First Name : ");
	getline(first_name, 11);
	printf("Last Name  : ");
	getline(last_name, 11);
	puts(first_name);
	puts(last_name);

	return 0;
}
