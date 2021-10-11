//Book.h - class declaration for a book

#ifndef _BOOK_H_
#define _BOOK_H_

#include <iostream>

class Book {
public:
	enum class Type {
		Science_Fiction,
		Documentary,
		Romance,
		Sport,
		Fiction
	};
private:
	std::string name;
	int id;
	Type type;
public:
	Book() {}
	Book(std::string name, int id, Book::Type type) {
		this->name = name;
		this->id = id;
		this->type = type;
	}
	std::string GetName() const { return name; }
	Book::Type GetType() const { return type; }
};

#endif// _BOOK_H_
