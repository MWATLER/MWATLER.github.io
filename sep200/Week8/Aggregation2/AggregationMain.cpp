//AggregationMain.cpp - code that demonstrates aggregation.

#include <iostream>
#include "Club.h"
#include "Name.h"

int main() {
    Name jane("Jane");
    Name john("John");
    Name alice("Alice");
    Name frank("Frank");
    Name stanley("Stanley");
    Name miguel("Miguel");
    Club gameClub;
    gameClub += jane;//name[0] = &jane, allocation of 5 pointers to Name
    gameClub += john;//name[1] = &john
    gameClub += alice;//name[2] = &alice
    gameClub += frank;//name[3] = &frank
    gameClub += stanley;//name[4] = &stanley
    gameClub += miguel;//name[5] = &miguel, reallocation for 10 pointers to Name
    gameClub.display();
    std::cout << std::endl;
    gameClub -= alice;//we had an array of 10 pointers to Name, 6 pointers were used
	                  //when we get rid of alice, only 5 pointers are used,
	                  //we need to deallocate from 10 pointers to 5 pointers to Name
    gameClub -= john;
    gameClub -= stanley;
    gameClub.display();
}