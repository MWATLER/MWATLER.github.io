//ElectronicBook.cpp - definition for electronic book

#include "ElectronicBook.h"

ElectronicBook::ElectronicBook(string _title, string _author, int _year, int _id) : Book(_title, _author, _year, _id)
{
	;
}

double ElectronicBook::CalculateFees(void)
{
	double days = difftime(checkInDate, checkOutDate);
	double fees = 0.00;
	const int maxDays = 7;
	const double feePerDay = 0.30;
	const double maxFees = 12.00;
	if (days > maxDays) {
		fees = (days - maxDays) * feePerDay;
		if (fees > maxFees) {
			fees = maxFees;
		}
	}
	return fees;
}