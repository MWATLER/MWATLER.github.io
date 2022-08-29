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
    gameClub += jane;
    gameClub += john;
    gameClub += alice;
    gameClub += frank;
    gameClub.display();
    std::cout << std::endl;
    gameClub -= alice;
    gameClub -= john;
    gameClub -= stanley;
    gameClub.display();
}