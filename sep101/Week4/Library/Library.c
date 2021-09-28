//Library.c - source code for our library

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#include <stdio.h>
#include "Biblio.h"
#define NUM_BOOKS 500

int main(void)
{
	struct Book books[NUM_BOOKS];

	for (int i = 0; i < NUM_BOOKS; ++i) {
		printf("RAM address of books[%d]:%p\n",
			i, (void*)& books[i]);
	}

	return 0;
}