//CatToy.cpp - function definitions for a cat toy

#include <iomanip>//setw
#include <string>//stod
#include "CatToy.h"

using namespace std;

CatToy::CatToy(const std::string& toy) {
/*  std::string name = "";
    std::string colour = "";
    double cost = 0.00;*/
	//parse a string of the type NAME:COLOUR:COST
	int startPos = 0;
	int endPos = toy.find(':');
	name = toy.substr(startPos, endPos - startPos);
	startPos = endPos + 1;//skip over the ':'
	endPos = toy.find(':', startPos);
	colour = toy.substr(startPos, endPos - startPos);
	startPos = endPos + 1;//skip over the ':'
	endPos = toy.find(':', startPos);//if ':' is not found, will return npos (the size of the string)
	cost = stod(toy.substr(startPos, endPos - startPos));
}

std::ostream& operator<<(std::ostream& out, const CatToy& toy)
{
	out << "Name: " << setw(10) << toy.name << " Colour: " << setw(10) << toy.colour << " Cost:" << setw(10) << fixed << setprecision(2) << toy.cost << endl;
	return out;
}
