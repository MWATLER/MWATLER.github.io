//Book.h - declaration for books
#ifndef _BOOK_H
#define _BOOK_H

#include "LibraryResource.h"

class Book : public LibraryResource {
	string author;
	int yearOfPublication;

public:
	Book(string _title, string _author, int _year, int _id);
	virtual double CalculateFees(void);
};

#endif//_BOOK_H