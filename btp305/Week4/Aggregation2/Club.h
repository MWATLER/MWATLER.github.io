//Club.h - class declaration for club

#ifndef _CLUB_H_
#define _CLUB_H_

#include "Name.h"

class Club {
    const Name** name;//an array of pointers where we don't know how many pointers there will be.
                      //const - in this example we don't want to change anything we're pointing to.
    int num{ 0 };//the number of Names
    const int BATCH_NUM = 5;//allocate and deallocate our array of pointers to Name in batches of five
public:
    Club& operator+=(const Name&);
    Club& operator-=(const Name&);
    void display() const;
    //...
};

#endif// _CLUB_H_
