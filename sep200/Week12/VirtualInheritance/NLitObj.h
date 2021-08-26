// NLitObj.h - Virtual Inheritance

#include "Name.h"
typedef unsigned long ulong;

class NLitObj : virtual public Name
{
    ulong color;
public:
    NLitObj(const char* n, ulong c);
    ulong emission() const;
};