// NamedColouredCube.h - Replicated Base Classes

#include "NamedCube.h"
#include "ColouredName.h"

//              Name
//	  NamedCube       ColouredName
//			  NamedColouredCube
class NamedColouredCube : public NamedCube,
    public ColouredName {
public:
    NamedColouredCube(const char* n, double l,
        ulong c);
};