// Static Data Member Declaration
// Array.h

template <typename T = int, int size = 50>
class Array {
    T a[size];
    unsigned n;
    T dummy;
    static unsigned count;
public:
    Array() : n{ 0 }, dummy{ 0 } { ++count; }
    T& operator[](unsigned i) {
        return i < 50u ? a[i] : dummy;
    }
    static unsigned cnt() { return count; }
    ~Array() { --count; }
};

unsigned Array<>::count = 0u;
unsigned Array<double>::count = 0u;
unsigned Array<int, 40>::count = 0u;