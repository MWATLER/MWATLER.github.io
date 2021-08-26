// NLitCube.cpp - Virtual Inheritance

#include "NLitCube.h"

NLitCube::NLitCube(const char* n, double len, ulong c) :
	Name(n), NCube(n, len), NLitObj(n, c) { }