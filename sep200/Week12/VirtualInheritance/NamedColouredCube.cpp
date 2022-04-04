// NamedColouredCube.cpp - Virtual Inheritance

#include "NamedColouredCube.h"

NamedColouredCube::NamedColouredCube(const char* n, double len, ulong c) :
	Name(n), NamedCube(n, len), ColouredName(n, c) { }