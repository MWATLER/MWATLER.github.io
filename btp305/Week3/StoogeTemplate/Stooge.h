//Stooge.h - base class declaration for a stooge

#ifndef _STOOGE_H_
#define _STOOGE_H_

#include <iostream>

template <typename T>
class Stooge{ 
public:
    void entertain() {
        std::cout << "The entertainment ladies and gentlemen: ";
        static_cast<T*>(this)->slap_stick();
    }
};

#endif _STOOGE_H_
