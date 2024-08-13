#pragma once
#include <string>
class PureVirtual{
    public:
        virtual ~PureVirtual() = default;

        // overload
        virtual bool print(int i) = 0;
        virtual bool print(char i) = 0;
        virtual bool print(float i) = 0;
        virtual bool print(std::string i) = 0;
};