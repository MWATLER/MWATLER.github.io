//Book.cpp - definition for book

#include "Book.h"

Book::Book(string _title, string _author, int _year, int _id) : LibraryResource(_title, _id)
{
	author = _author;
	yearOfPublication = _year;
}

double Book::CalculateFees(void)
{
	double days = difftime(checkInDate, checkOutDate);
	double fees = 0.00;
	const int maxDays = 21;
	const double feePerDay = 0.15;
	const double maxFees = 6.00;
	if (days > maxDays) {
		fees = (days - maxDays) * feePerDay;
		if (fees > maxFees) {
			fees = maxFees;
		}
	}
	return fees;
}
