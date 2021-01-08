//MusicalInstrument.cpp - definition for musical instruments

#include "MusicalInstrument.h"

MusicalInstrument::MusicalInstrument(string _name, int id) : LibraryResource(_name, id)
{
}

double MusicalInstrument::CalculateFees(void)
{
	double days = difftime(checkInDate, checkOutDate);
	double fees = 0.00;
	const int maxDays = 5;
	const double feePerDay = 0.50;
	const double maxFees = 15.00;
	if (days > maxDays) {
		fees = (days - maxDays) * feePerDay;
		if (fees > maxFees) {
			fees = maxFees;
		}
	}
	return fees;
}