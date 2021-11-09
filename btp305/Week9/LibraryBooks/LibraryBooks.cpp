//LibraryBooks.cpp - function definitions for a library of books

#include <algorithm>//std::transform
#include <numeric>//std::accumulate
#include "LibraryBooks.h"

/*struct Book {
	std::string name;
	std::string author;
	int pages;
	double price;
};*/

//	std::vector<Book> m_books;
LibraryBooks::LibraryBooks(Book books[], int size) {
	for (int i = 0; i < size; ++i) {
		Book book;
		book.name = books[i].name;
		book.author = books[i].author;
		book.pages = books[i].pages;
		book.price = books[i].price;
		m_books.push_back(book);
	}
}

bool LibraryBooks::ConvertPrice(double exchangeRate) {
	bool retVal = true;
	if (exchangeRate <= 0 || m_books.size() == 0) retVal = false;
	else {
		//https://en.cppreference.com/w/cpp/algorithm/transform
		std::transform(m_books.begin(), m_books.end(), m_books.begin(), [=](Book book) {
			book.price *= exchangeRate;
			return book;
			});
	}
	return retVal;
}

int LibraryBooks::TotalPages() const {
	double total = std::accumulate(m_books.begin(), m_books.end(), 0.0, [](const double& sum, const Book& book) {
		return sum + book.pages;
		});
	return total;
}

bool LibraryBooks::sort(std::string field) {
	bool retVal = true;
	if (field == "price") {
		std::sort(m_books.begin(), m_books.end(), [](const Book& a, const Book& b) {
			return a.price < b.price;
			});
	}
	else if (field == "pages") {
		std::sort(m_books.begin(), m_books.end(), [](const Book& a, const Book& b) {
			return a.pages < b.pages;
			});
	}
	else {
		std::cout << "Invalid field" << std::endl;
		retVal = false;
	}
	return retVal;
}

void LibraryBooks::display(std::ostream& out) const {
	std::for_each(m_books.begin(), m_books.end(), [&out](const Book& book) {
		out.precision(2);
		out << book.name << " " << book.author << " " << book.pages << std::fixed << " pages $" << book.price << std::endl;
		});
}