#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>
#include <string>
#include <set>
#include <tuple>

using namespace testing;

TEST(expectThatTest, numTest){
    std::set<int> set_ = {1,2,3,4,5};

    EXPECT_THAT(set_, Contains(3));

    // error test
    // EXPECT_THAT(set_, Contains(8));

    EXPECT_THAT(set_, Not(Contains(8)));

    EXPECT_THAT(set_, Contains(Lt(8)));
    EXPECT_THAT(set_, UnorderedElementsAre(5,4,3,2,1));
}

TEST(expectThatTest, strTest){
    std::string str_ = "how are you";

    EXPECT_THAT(str_, HasSubstr("are"));
    EXPECT_THAT(str_,StartsWith("how"));
    EXPECT_THAT(str_,EndsWith("you"));
}

TEST(ExampleTest, floatTest) {
    float a = 3.1415;
    double b = 3.1415;

    EXPECT_THAT(a, FloatEq(3.1415));
    EXPECT_THAT(a, FloatNear(3.1415, 0.0001));

    EXPECT_EQ(a, 3.1415f); // 不加f会失败
    EXPECT_EQ(b, 3.1415);
    EXPECT_FLOAT_EQ(a, 3.1415); // ? 理论上应该失败
    EXPECT_FLOAT_EQ(b, 3.1415f); // ? 理论上应该失败
}
