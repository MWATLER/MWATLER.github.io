//BookMain.cpp - main function for Book

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//TODO: Add any other required header files
#include "Book.h"

int main(int argc, char* argv[]) {
	int retVal = 0;
	if (argc != 2) {
		printf("Usage: BookMain.exe  Book.txt");
		return -1;
	}
	FILE* fp = fopen(argv[1], "r");

	//TODO: Declare an array of NUM_BOOKS objects of type Book

	for (int i = 0; i < NUM_BOOKS; ++i) {
		char bookData[MAX_STREAM] = { 0 };
 		fscanf_s(fp, "%[^\n]s", bookData, MAX_STREAM);//Read an entire line from the file and store in bookData
		while (fgetc(fp) != '\n');//clear out the carriage return

		//NAME;AUTHOR;YEAR;PRICE;

		//TODO: Call the extraction function four times too extract the NAME, AUTHOR, YEAR, and PRICE using
		//      the following pointers. Store the information into the array of Book objects one at a time:
		char* leftPtr = bookData;//&bookData[0]
		char* rightPtr = nullptr;//C++ equivalent of NULL






	}
	fclose(fp);

	//TODO: print out all the information for all the books

	return 0;
}