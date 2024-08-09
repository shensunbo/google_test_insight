#pragma once

#include <string>

class Tire {
    int boo;
};

class Wheel {
public:
    int foo = 0;
    Tire tire_;
};

class Engine {
public:
    int bar = 0;
};

class Car {
public:
    Wheel wheel_ = {};
    Engine engin_ = {};
    unsigned int price = 0;
    bool cool = true;
    std::string name_;
};
