// lvalue References
// lvalue.cpp
#include "A.h"
#include "B.h"

B e(8), f(6);
B& b = e; // LVALUE REQUIRES INITIALIZER

int main() {
    A a(f);
    foo(a);
}