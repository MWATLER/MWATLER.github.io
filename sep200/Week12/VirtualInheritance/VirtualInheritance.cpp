// VirtualInheritance.cpp - Virtual Inheritance

#include "NamedColouredCube.h"

int main() {
    NamedCube    sc("a named cube", 2);//name, length
    ColouredName  sl("a named lit object", 0x55bb77aaUL);//name, colour (RGB)
    NamedColouredCube lc("a named lit cube", 2, 0xccFF33FFUL);//name, length colour (RGB)
    sc.display();
    sl.display();
    lc.display();
}