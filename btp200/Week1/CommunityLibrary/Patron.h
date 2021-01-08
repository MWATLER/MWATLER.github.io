//Patron.h - declaration for patrons
#ifndef _PATRON_H
#define _PATRON_H

#include <iostream>
#include <vector>
#include "LibraryResource.h"

class Patron {
	vector<LibraryResource*> resource;
	int patronID;
	string fullName;
	int numResources;
	double lateFees;

public:
	Patron(int id, string name);
	void BorrowResources(void);
	void ReturnResources(void);
	void ReportResources(void);
	void ReportFees(void);

};

#endif//_PATRON_H