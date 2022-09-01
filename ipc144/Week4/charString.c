//charString.c - demonstrates character strings
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char c;//Contains one character
	char name[11];//Contains ten characters plus NULL terminator 
	printf("Enter your name: ");
//	scanf("%s", &name[0]);//address of the first element in the array
	scanf("%s", name);//name is the address of the beginning of the array
	printf("Your name is %s\n", name);

	int i;
	for (i = 0; i < 11; ++i) {
		printf("name[%d] %c %d\n", i, name[i], name[i]);
	}
	
	return 0;
}
