// NLitObj.h - Virtual Inheritance
// An NLitObj object holds a color in RGBA format, where the high order byte holds the red intensity,
// the next byte holds the green intensity, the next byte holds the blue intensity, and the low order 
// byte holds the opacity.  Each byte has a range of 0-255 for zero to full intensity respectively.

#include "Name.h"
typedef unsigned long ulong;

class NLitObj : virtual public Name
{
    ulong color;
public:
    NLitObj(const char* n, ulong c);
    ulong emission() const;
};