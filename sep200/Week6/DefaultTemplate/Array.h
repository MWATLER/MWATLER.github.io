// Static Data Member Declaration
// Array.h

template <typename T = int, int size = 50>//T by default is int, size by default is 50
class Array {
    T a[size];
    unsigned n;
    T dummy;
    static unsigned count;//count exists even if there is no object of type Array
public:
    Array() : n{ 0 }, dummy{ 0 } { ++count; }
    T& operator[](unsigned i) {
        return i < 50u ? a[i] : dummy;
    }
    static unsigned cnt() { return count; }
    ~Array() { --count; }
};

//In main(), three classes are being created! They are:
//Array<> s, t;//uses all default parameters: T is int, size is 50
//Array<double> u;//T is double, size is the default of 50
//Array<int, 40> v;//T is int, size is 40

unsigned Array<>::count = 0u;//uses all default parameters: T is int, size is 50
unsigned Array<double>::count = 0u;//T is double, size is the default of 50
unsigned Array<int, 40>::count = 0u;//T is int, size is 40