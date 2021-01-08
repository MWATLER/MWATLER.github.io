//DVD.h - declaration for DVDs
#ifndef _DVD_H
#define _DVD_H

#include "LibraryResource.h"

class DVD : public LibraryResource {
	int releaseYear;

public:
	DVD(string _title, int year, int id);
	double CalculateFees(void);
};

#endif//_DVD_H