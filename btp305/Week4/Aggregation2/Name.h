//Name.h - class declaration for a name

#ifndef _NAME_H_
#define _NAME_H_

class Name {
    char* name{ nullptr };
public:
    Name(const char*);
    Name(const Name&);
    Name& operator=(const Name&);
    ~Name();
    const char* get() const;
    void set(const char*);
};

#endif// _NAME_H_
