// A.cpp
#include "A.h"
decltype(A().getValue()) operator+=(double& val, const A& other)
{
    return val += other.getValue();
}