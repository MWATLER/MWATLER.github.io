//Stooge.h - abstract base class declaration for a stooge

#ifndef _STOOGE_H_
#define _STOOGE_H_

#include <iostream>

class Stooge
{
public:
    // Factory Method
    static Stooge* make_stooge(int choice);//does not depend on an object of class Stooge being created
    virtual void slap_stick() = 0;//pure virtual function
	virtual ~Stooge() {};//An interface in C++ SHOULD have a virtual destructor that is implemented and does nothing.
};

#endif _STOOGE_H_
