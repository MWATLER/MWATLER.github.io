// Name.h - Replicated Base Classes

#ifndef NAME_H
#define NAME_H

class Name {
    const char* name;
protected:
    Name(const char* n);
public:
    virtual void display() const;
};
#endif