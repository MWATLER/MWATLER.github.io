// Module A Header
// A.h
#pragma once

class B;
class A {
    B& d; // no initializer required: class member declaration
public:
    A(B& bb); // no initializer required: function parameter declaration
};

A& foo(A&);