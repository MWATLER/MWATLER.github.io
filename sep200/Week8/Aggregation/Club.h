//Club.h - class declaration for club

#ifndef _CLUB_H_
#define _CLUB_H_

#include "Name.h"

constexpr int M{ 50 };//The principle difference between const and constexpr is the time when their
                      //initialization values are known. While the values of const variables can be
                      //evaluated at both compile time and runtime, constexpr are always evaluated
                      //at compile time.

class Club {
    const Name* name[M]{};//an array of pointers
	                      //we want to point to objects of type Name who attend this club
	                      //objects of type name are created outside the class, and there are many of them
    int num{ 0 };//tracks how many names are in our club
public:
    Club& operator+=(const Name&);//add a name to the club
    Club& operator-=(const Name&);//remove a name from the club
    void display() const;
    //...
};

#endif// _CLUB_H_
