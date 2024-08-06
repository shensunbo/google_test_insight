#pragma once
#include "TypeForMatcher.h"

class BaseDep{
    public:
        virtual ~BaseDep() = default;

        virtual bool doSomething(int _foo) = 0;
        virtual bool funcNeedMatcher(Car _car) = 0;
};