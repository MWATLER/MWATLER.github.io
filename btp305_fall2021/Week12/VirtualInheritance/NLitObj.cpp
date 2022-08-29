// NLitObj.cpp - Replicated Base Classes

#include <iostream>
#include "NLitObj.h"

NLitObj::NLitObj(const char* n, ulong c)
    : Name(n), color(c) { }

ulong NLitObj::emission() const {
    return color;
}