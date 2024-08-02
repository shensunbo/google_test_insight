#pragma once

class BaseDep{
    public:
        virtual ~BaseDep() = default;

        virtual bool doSomething(int _foo) = 0;
};