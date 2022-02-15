// Template Specialization
// Maximum.h

#include <cstring>

template <class T>
T maximum(T a, T b) {
    return a > b ? a : b;
}

// specialization for char* types
//
template <> // denotes specialization
char* maximum<char*>(char* a, char* b) {
    return std::strcmp(a, b) > 0 ? a : b;
}
/*
double maximum(double a, double b) {
	return a > b ? a : b;
}

char* maximum(char* a, char* b) {
    return std::strcmp(a, b) > 0 ? a : b;
}
*/