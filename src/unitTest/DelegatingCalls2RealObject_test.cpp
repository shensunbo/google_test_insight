#include "gmock/gmock.h"
#include "MockRealObject.h"

TEST(mockRealObjectTest, directUseRealObj){
    MockRealObject mock;

    int multify = 0;
    EXPECT_CALL(mock, multify10(10, multify))
        .Times(1);

    EXPECT_CALL(mock, minus5(55))
        .Times(1);

    
    mock.multify10(10, multify);
    EXPECT_EQ(100, multify);

    int val = mock.minus5(55);
    EXPECT_EQ(50, val);
}

TEST(mockRealObjectTest, notPureVirtualTest){
    MockRealObject mock;

    //method 1, use ON_CALL
    EXPECT_CALL(mock, idk("hello world"))
        .Times(1);

    std::string str = mock.idk("hello world");
    EXPECT_STREQ("hello world", str.c_str());

    //method 2, use lambda
    EXPECT_CALL(mock, anotherIdk("bye-bye"))
        .Times(1)
        .WillOnce([&mock](std::string s){
            return mock.RealObject::anotherIdk(s);
        });

    std::string anotherStr = mock.anotherIdk("bye-bye");
    EXPECT_STREQ("bye-bye", anotherStr.c_str());
}