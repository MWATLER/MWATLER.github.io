//BookObserver.h - book observer class for books in a library

#ifndef _BOOKOBSERVER_H_
#define _BOOKOBSERVER_H_

#include "Book.h"

class BookObserver {
	int numScienceFiction{ 0 };
	int numDocumentary{ 0 };
	int numRomance{ 0 };
	int numSport{ 0 };
	int numFiction{ 0 };
	int numBooks{ 0 };
public:
	BookObserver() {}//default constructor
	BookObserver(const BookObserver&) = delete;//disable the copy constructor
	BookObserver& operator=(const BookObserver&) = delete;//disable the copy assignment
	static void RegisterBook(BookObserver* bookObserver, Book::Type type) {
		//This function has to always exist in order for it to be registered
		//as a callback function, therefore it is declared as static.
		++bookObserver->numBooks;
		switch (type) {
		case Book::Type::Science_Fiction:
			++bookObserver->numScienceFiction;
			break;
		case Book::Type::Documentary:
			++bookObserver->numDocumentary;
			break;
		case Book::Type::Romance:
			++bookObserver->numRomance;
			break;
		case Book::Type::Sport:
			++bookObserver->numSport;
			break;
		case Book::Type::Fiction:
			++bookObserver->numFiction;
			break;
		}
	}
	double operator()(Book::Type type) {
		double retVal = 0.0;
		if (numBooks == 0) throw "Divide by zero error...";
		else {
			switch (type) {
			case Book::Type::Science_Fiction:
				retVal = (double)numScienceFiction / numBooks;
				break;
			case Book::Type::Documentary:
				retVal = (double)numDocumentary / numBooks;
				break;
			case Book::Type::Romance:
				retVal = (double)numRomance / numBooks;
				break;
			case Book::Type::Sport:
				retVal = (double)numSport / numBooks;
				break;
			case Book::Type::Fiction:
				retVal = (double)numFiction / numBooks;
				break;
			}
		}
		return retVal;
	}
};



#endif _BOOKOBSERVER_H_
