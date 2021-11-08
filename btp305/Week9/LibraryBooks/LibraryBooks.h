//LibraryBooks.h - a library of books

#ifndef _LIBRARYBOOKS_H_
#define _LIBRARYBOOKS_H_

#include <iostream>
#include <vector>

struct Book {
	std::string name;
	std::string author;
	int pages;
	double price;
};

class LibraryBooks {
	std::vector<Book> m_books;
public:
	LibraryBooks(Book books[], int size);
	bool ConvertPrice(double exchangeRate);
	double TotalPages() const;
	bool sort(std::string field);
	void display(std::ostream& out) const;
};



#endif// _LIBRARYBOOKS_H_
