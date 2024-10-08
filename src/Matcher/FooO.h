#pragma once

#include "TypeForMatcher.h"
#include <string>
#include <vector>

class FooO{
public:
    virtual ~FooO() = default;

    virtual  bool doThis(Car car_) = 0;
    virtual  bool doThat(Car& car_) = 0;
    virtual  bool doSomething(Car* car_) = 0;

    virtual  bool doAnything(int i) = 0;
    virtual  bool doNothing(std::string str) = 0;

    virtual  bool containerInput(const std::vector<int>& vec) const = 0;
};