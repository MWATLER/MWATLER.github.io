//Stooge.h - base class declaration for a stooge

#ifndef _STOOGE_H_
#define _STOOGE_H_

#include <iostream>

class Stooge
{
public:
    // Factory Method
    static std::unique_ptr<Stooge> make_stooge(int choice);
    virtual void slap_stick() = 0;
    virtual ~Stooge() {
        std::cout << "~Stooge()" << std::endl;
    }
};

#endif _STOOGE_H_
