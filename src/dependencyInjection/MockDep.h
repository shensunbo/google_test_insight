#pragma once

#include "BaseDep.h"
#include "gmock/gmock.h"

class MockDep : public BaseDep {
    public:
        MOCK_METHOD(bool, doSomething, (int _foo), (override));
        MOCK_METHOD(bool, funcNeedMatcher, (Car _car), (override));
};