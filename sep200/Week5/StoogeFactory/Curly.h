//Curly.h - class declaration for Curly

#ifndef _CURLY_H_
#define _CURLY_H_

#include "Stooge.h"

class Curly : public Stooge
{
public:
    void slap_stick()
    {
        std::cout << "Curly: suffer abuse\n";
    }
	~Curly() {
		std::cout << "~Curly:" << std::endl;
	}
};

#endif _CURLY_H_
