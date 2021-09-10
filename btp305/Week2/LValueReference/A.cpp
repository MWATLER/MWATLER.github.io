// Module A Implementation
 // A.cpp
#include <iostream>
#include "A.h"
#include "B.h"

extern B& b; // no initializer required: external linkage

A::A(B& bb) : d(bb) { // initialization is in constructor definition
    d.display();
}

A& foo(A& a) { // no initializers required:
               // parameter and return type declarations
    A& aa = a; // LVALUE REQUIRES AN INITIALIZER
    b.display();
    return aa;
}