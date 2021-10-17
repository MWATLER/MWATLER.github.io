// A.cpp
#include "A.h"
decltype(A().getValue()) operator+=(double& val, const A& other)//MW: incorrect prototype
{
    return val += other.getValue();
}