//Cargo.h - declarations for cargo

#ifndef _CARGO_H_
#define _CARGO_H_

#include <iostream>
enum class CargoType {
    Car,
    Food,
    Commodity
};
class Cargo {
    std::string name;
    double value;
    CargoType cType;
public:
    Cargo(std::string name, double value, CargoType type) {
        this->name = name;
        this->value = value;
        this->cType = type;
    }
    std::string GetName() const {
        return name;
    }
    double GetValue() const {
        return value;
    }
    CargoType GetType() const {
        return cType;
    }
};

#endif// _CARGO_H_