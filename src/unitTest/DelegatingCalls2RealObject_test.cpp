#include "gmock/gmock.h"
#include "MockRealObject.h"

TEST(mockRealObjectTest, test1){
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