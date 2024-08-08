#pragma once

#include <iostream>
#include <string>

class RealObject{
public:
    void multify10(const int in, int& out){
        out = in * 10;
    }

    int minus5(const int in){
        return (in - 5);
    }

    //not pure virtual func
    std::string idk(std::string str){
        return str;
    }
};