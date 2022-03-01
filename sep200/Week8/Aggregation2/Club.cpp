//Club.cpp - function definitions for club

#include <iostream>
#include <cstring>
#include "Club.h"
#include "Name.h"

Club& Club::operator+=(const Name& n) {
    //allocate the array of pointers in batches of five
    if (num % BATCH_NUM == 0) {
        const Name** tmp = new const Name * [num + BATCH_NUM];//the newly allocated array of pointers
        for (int i = 0; i < num; ++i) {//copy values to the newly allocated array of pointers
            tmp[i] = const_cast<Name*>(name[i]);//remove the constness so we can point to the names in the name array
        }
        delete[] name;//get rid of the old allocated array of pointers
        name = tmp;//point to the newly allocated array of pointers
    }
    name[num++] = const_cast<Name*>(&n);//add the address of the new Name to the array of pointers
    return *this;
}

Club& Club::operator-=(const Name& t) {
    bool found = false;
    int i;
    for (i = 0; i < num && !found; i++) {
        if (std::strcmp( name[i]->get(), t.get() )==0) {
            found = true;
        }
    }
    if (found) {
        for (; i < num; i++)
            name[i - 1] = name[i];
        if (num) {
            name[num - 1] = nullptr;//this does not deallocate memory
            num--;
        }
        if (num % BATCH_NUM == 0) {//reduce the allocated array of pointers in batches of five
            //get rid of the empty slots
            const Name** tmp = nullptr;//the new array of pointers
            if (num > 0) {
                tmp = new const Name * [num];//the newly allocated array of pointers
                for (int i = 0; i < num; ++i) {//copy values to the newly allocated memory
                    tmp[i] = const_cast<Name*>(name[i]);
                }
            }
            delete[] name;//get rid of the old allocated memory
            name = tmp;//point to the newly allocated memory
        }
    }
    return *this;
}

void Club::display() const {
    for (int i = 0; i < num; i++) {
        std::cout << name[i]->get() << std::endl;
    }
}