//Club.h - class declaration for club

#ifndef _CLUB_H_
#define _CLUB_H_

#include "Name.h"

constexpr int M{ 50 };

class Club {
    const Name* name[M]{};
    int m{ 0 };
public:
    Club& operator+=(const Name&);
    Club& operator-=(const Name&);
    void display() const;
    //...
};

#endif// _CLUB_H_
