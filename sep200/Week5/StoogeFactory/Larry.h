//Larry.h - class declaration for the stooge Larry

#ifndef _LARRY_H_
#define _LARRY_H_

#include "Stooge.h"

class Larry : public Stooge
{
public:
    void slap_stick()
    {
        std::cout << "Larry: poke eyes\n";
    }
	~Larry() {
		std::cout << "~Larry:" << std::endl;
	}
};

#endif _LARRY_H_
