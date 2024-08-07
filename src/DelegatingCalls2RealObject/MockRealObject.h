#pragma once

#include "gmock/gmock.h"
#include "RealObject.h"

class MockRealObject : public RealObject{
public:
    MockRealObject(){
        ON_CALL(*this, multify10).WillByDefault([this](const int in, int& out){
            return realObject_.multify10(in, out);
        });

        ON_CALL(*this, minus5).WillByDefault([this](const int in){
            return realObject_.minus5(in);
        });
    }

    MOCK_METHOD((void), multify10, (const int in, int& out), ());
    MOCK_METHOD((int), minus5, (const int in), ());

private:
    RealObject realObject_;
};