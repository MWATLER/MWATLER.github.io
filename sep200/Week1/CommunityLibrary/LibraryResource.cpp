// LibraryResource.cpp - Base class definition for library resources

#include "LibraryResource.h"

LibraryResource::LibraryResource(string _title, int id)
{
	title = _title;
	catalogID = id;
	checkOutDate = 0;
	checkInDate = 0;
}

void LibraryResource::CheckOut(time_t date)
{
	checkOutDate = date;
}

void LibraryResource::CheckIn(time_t date)
{
	checkInDate = date;
}

double LibraryResource::CalculateFees(void)
{
	double days = difftime(checkInDate, checkOutDate);
	double fees=0.00;
	const int maxDays = 28;
	const double feePerDay = 0.10;
	const double maxFees = 5.00;
	if (days > maxDays) {
		fees = (days - maxDays) * feePerDay;
		if (fees > maxFees) {
			fees = maxFees;
		}
	}
	return fees;
}

string LibraryResource::GetTitle(void)
{
	return title;
}

int LibraryResource::GetCatalogID(void)
{
	return catalogID;
}

