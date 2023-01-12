// LibraryResource.h - Base class declaration for library resources
#ifndef _LIBRARYRESOURCE_H
#define _LIBRARYRESOURCE_H

#include <time.h>
#include <iostream>
using namespace std;

class LibraryResource {
	string title;
	int catalogID;

protected:
	time_t checkOutDate;
	time_t checkInDate;

public:
	LibraryResource(string _title, int id);
	void CheckOut(time_t date);
	void CheckIn(time_t date);
	virtual double CalculateFees(void);
	string GetTitle(void);
	int GetCatalogID(void);
};

#endif//_LIBRARYRESOURCE_H