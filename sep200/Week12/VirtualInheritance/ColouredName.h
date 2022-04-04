// ColouredName.h - Virtual Inheritance

#include "Name.h"
typedef unsigned long ulong;

class ColouredName : virtual public Name
{
    ulong color;
public:
    ColouredName(const char* n, ulong c);
    ulong GetColour() const;
};