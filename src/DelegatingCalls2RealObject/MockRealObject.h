#pragma once

#include "gmock/gmock.h"
#include "RealObject.h"
#include <string>
class MockRealObject : public RealObject{
public:
    MockRealObject(){
        ON_CALL(*this, multify10).WillByDefault([this](const int in, int& out){
            return realObject_.multify10(in, out);
        });

        ON_CALL(*this, minus5).WillByDefault([this](const int in){
            return realObject_.minus5(in);
        });

        //not pure virtual func mock and call parent func
        ON_CALL(*this, idk).WillByDefault([this](std::string str){
            return realObject_.RealObject::idk(str);
        });
    }

    MOCK_METHOD((void), multify10, (const int in, int& out), ());
    MOCK_METHOD((int), minus5, (const int in), ());

    //not pure virtual func mock and call parent func
    MOCK_METHOD((std::string), idk, (std::string), ());
    MOCK_METHOD((std::string), anotherIdk, (std::string), ());

private:
    RealObject realObject_;
};