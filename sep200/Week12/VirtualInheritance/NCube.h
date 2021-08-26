// NCube.h - Virtual Inheritance

#include "Name.h"

class NCube : virtual public Name
{
    double len;
public:
    NCube(const char* n, double l);
    double volume() const;
};