//StandardPaperBook.cpp - definition for standard paper book

#include "StandardPaperBook.h"

StandardPaperBook::StandardPaperBook(string _title, string _author, int _year, int _id) : Book(_title, _author, _year, _id)
{
	;
}

double StandardPaperBook::CalculateFees(void)
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