// NamedCube.h - Virtual Inheritance

#include "Name.h"

class NamedCube : virtual public Name
{
    double len;
public:
    NamedCube(const char* n, double l);
    double volume() const;
};