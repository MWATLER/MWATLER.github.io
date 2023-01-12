//BigMap.cpp - program that creates a large database based on STL's map

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
#include <iterator>
int main()
{
    const int SIZE = 16;
    double val;
    std::string key;
    std::map<std::string, double> bigMap;//std::map<key, value> mapOfSomething;

    //create the map
    for (int i = 0; i < 4000000; ++i) {
        char keyCh[SIZE];
        val = static_cast<double>(i) * static_cast<double>(i);
        sprintf(keyCh, "%d", i);
        key = keyCh;
        bigMap.insert(std::make_pair(key, val));
    }

    do {
        std::cout << "Enter a key: ";
        std::cin >> key;
        std::cout << "The value is " << bigMap[key] << std::endl;
    } while (key != "end");

    return 1;
}