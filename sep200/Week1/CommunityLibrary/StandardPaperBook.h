//StandardPaperBook.h - declaration for standard paper books
#ifndef _STANDARDPAPERBOOK_H
#define _STANDARDPAPERBOOK_H

#include "Book.h"

class StandardPaperBook : public Book {

public:
	StandardPaperBook(string _title, string _author, int _year, int _id);
	virtual double CalculateFees(void);
};

#endif//_STANDARDPAPERBOOK_H