#pragma once
#include "TypeForMatcher.h"
#include <string>

class BaseDep{
    public:
        virtual ~BaseDep() = default;

        virtual bool doSomething(int _foo) = 0;
        virtual bool funcNeedMatcher(Car _car) = 0;

        virtual bool passOneStr(std::string str) = 0;
};