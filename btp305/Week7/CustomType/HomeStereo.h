//HomeStereo.h

#ifndef _HOMESTEREO_H_
#define _HOMESTEREO_H_

#include <iostream>
#include "Switch.h"

class HomeStereo {
	const Switch** switches = nullptr;
	int numSwitches{ 0 };
public:
	HomeStereo(const Switch* theSwitches[], int num);
	std::ostream& displayOutputState(std::ostream& os);
	//missing the rule of 5
	~HomeStereo();
};


#endif _HOMESTEREO_H_
