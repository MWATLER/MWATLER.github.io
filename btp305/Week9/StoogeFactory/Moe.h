//Moe.h - class declaration for Moe

#ifndef _MOE_H_
#define _MOE_H_

#include "Stooge.h"

class Moe : public Stooge
{
public:
    void slap_stick()
    {
        std::cout << "Moe: slap head\n";
    }
    ~Moe() {
        std::cout << "~Moe()" << std::endl;
    }
};

#endif _MOE_H_
