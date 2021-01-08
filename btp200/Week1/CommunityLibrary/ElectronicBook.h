//ElectronicBook.h - declaration for electronic books
#ifndef _ELECTRONICBOOK_H
#define _ELECTRONICBOOK_H

#include "Book.h"

class ElectronicBook : public Book {

public:
	ElectronicBook(string _title, string _author, int _year, int _id);
	virtual double CalculateFees(void);
};

#endif//_ELECTRONICBOOK_H