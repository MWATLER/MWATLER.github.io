//Stooge.h - base class declaration for a stooge

#ifndef _STOOGE_H_
#define _STOOGE_H_

#include <iostream>

class Stooge
{
public:
    // Factory Method
    static Stooge* make_stooge(int choice);
    virtual void slap_stick() = 0;
};

#endif _STOOGE_H_
