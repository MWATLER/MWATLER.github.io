// Wrapper.cpp - demo code for the reference wrapper

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
    vector<double> original(3, 10.3);//a vector of 3 10.3's: 10.3, 10.3, 10.3
    vector<reference_wrapper<double>> references(original.begin(), original.end());
    for (auto& e : original) {
        e *= 3;
    }
    for (auto e : references) {
        cout << e << " ";
    }
    cout << endl;
}
