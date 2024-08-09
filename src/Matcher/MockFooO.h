#pragma once

#include "gmock/gmock.h"
#include "FooO.h"

class MockFooO : public FooO {
public:
    MOCK_METHOD((bool), doThis, (Car car_), (override));
    MOCK_METHOD((bool), doThat, (Car& car_), (override));
    MOCK_METHOD((bool), doSomething, (Car* car_), (override));

    MOCK_METHOD((bool), doAnything, (int i), (override));
    MOCK_METHOD((bool), doNothing, (std::string str), (override));
};