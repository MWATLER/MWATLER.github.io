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
    Club gameClub;
    gameClub += jane;//name[0] will point to jane
    gameClub += john;//name[1] will point to john
    gameClub += alice;//name[2] will point to alice
    gameClub += frank;//name[3] will point to frank
    gameClub.display();
    std::cout << std::endl;
    gameClub -= alice;//name[2] is nullptr, but name[3] will be shifted to name[2], so
	                  //name[2] now points to frank
    gameClub -= john;//name[1] now points to frank
	//name[0] points to jane, name[1] points to frank
    gameClub -= stanley;//not found
    gameClub.display();
}