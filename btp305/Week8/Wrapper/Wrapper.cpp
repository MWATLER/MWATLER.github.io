// Wrapper.cpp - demo code for the reference wrapper

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
    //From https://en.cppreference.com/w/cpp/utility/functional/reference_wrapper:
    //std::reference_wrapper is a class template that wraps a reference in a copyable, 
    //assignable object. It is frequently used as a mechanism to store references 
    //inside standard containers (like std::vector) which cannot normally hold references. 

    //From https://stackoverflow.com/questions/26766939/difference-between-stdreference-wrapper-and-simple-pointer
    //std::reference_wrapper is useful in combination with templates. It wraps an object by storing a pointer to it, 
    //allowing for reassignment and copy while mimicking its usual semantics. It also instructs certain library 
    //templates to store references instead of objects.
    vector<double> original(3, 10.3);//a vector of 3 10.3's
    vector<reference_wrapper<double>> references(original.begin(), original.end());
    for (auto& e : original) {
        e *= 3;
    }
    for (auto e : references) {
        cout << e << " ";
    }
    cout << endl;
}
