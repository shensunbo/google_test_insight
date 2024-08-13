#pragma once

#include "PureVirtual.h"
#include <gmock/gmock.h>

class MockPureVirtual : public PureVirtual {
public:
    MOCK_METHOD(bool, print, (int i), (override));
    MOCK_METHOD(bool, print, (char i), (override));
    MOCK_METHOD(bool, print, (float i), (override));
    MOCK_METHOD(bool, print, (std::string i), (override));
};