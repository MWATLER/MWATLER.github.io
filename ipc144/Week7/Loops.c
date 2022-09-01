//Loops.c - Midterm review on loops

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i = 0;
	while (i < 100) {
		printf("Hello\n");
		++i;
	}

	for (i = 0; i < 100; ++i) {
		printf("Hello\n");
	}

	for (i = 100; i > 0; --i) {
		printf("Hello\n");
	}

	i = 100;
	while (i > 0) {
		printf("Hello\n");
		--i;
	}

	return 0;
}