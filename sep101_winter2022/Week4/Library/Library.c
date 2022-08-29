//Library.c - source code for our library

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#include <stdio.h>//system header file, in <...>
#include "Biblio.h"//my header file, in quotes
#define NUM_BOOKS 500

int main(void)
{
	struct Book books[NUM_BOOKS];//142 bytes x 500 = 71000 bytes
/*	#define MAX_STR 42
    struct Book {//142 bytes
		char author[MAX_STR];//42 bytes
		char title[MAX_STR];//42 bytes
		int year;//8 bytes
		int barcode;//8 bytes
		char category[MAX_STR];//42 bytes
	};*/

	for (int i = 0; i < NUM_BOOKS; ++i) {
		printf("RAM address of books[%d]:%p\n",
			i, (void*)& books[i]);
	}

	return 0;
}