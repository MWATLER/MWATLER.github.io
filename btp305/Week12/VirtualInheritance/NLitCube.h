// NLitCube.h - Replicated Base Classes

#include "NCube.h"
#include "NLitObj.h"

class NLitCube : public NCube, public NLitObj {
public:
    NLitCube(const char* n, double l, ulong c);
};