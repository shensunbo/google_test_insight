#pragma once

#include "BaseDep.h"

class RealDep : public BaseDep
{
public:
    bool doSomething(int _foo) override;
    bool funcNeedMatcher(Car _car) override;
    bool passOneStr(std::string str) override;
};