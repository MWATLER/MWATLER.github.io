//Biblio.h - Declarations for bibliography

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define MAX_STR 42

struct Book {
	char author[MAX_STR];
	char title[MAX_STR];
	int year;
	int barcode;
	char category[MAX_STR];
};
