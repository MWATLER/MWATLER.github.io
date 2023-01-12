//MusicalInstrument.h - declaration for musical instruments
#ifndef _MUSICALINSTRUMENT_H
#define _MUSICALINSTRUMENT_H

#include "LibraryResource.h"

class MusicalInstrument : public LibraryResource {

public:
	MusicalInstrument(string _name, int id);
	double CalculateFees(void);
};

#endif//_MUSICALINSTRUMENT_H