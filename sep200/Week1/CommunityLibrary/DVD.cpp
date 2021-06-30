//DVD.cpp - definition for DVDs

#include "DVD.h"

DVD::DVD(string _title, int year, int id) : LibraryResource(_title, id)
{
	releaseYear = year;
}

double DVD::CalculateFees(void)
{
	double days = difftime(checkInDate, checkOutDate);
	double fees = 0.00;
	const int maxDays = 14;
	const double feePerDay = 0.25;
	const double maxFees = 9.00;
	if (days > maxDays) {
		fees = (days - maxDays) * feePerDay;
		if (fees > maxFees) {
			fees = maxFees;
		}
	}
	return fees;
}