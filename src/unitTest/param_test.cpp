#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <tuple>

#include "MockDep.h"
#include "BeTested.h"

using namespace testing;

// param test demo
class OddParamTest : public TestWithParam<int> {
};

INSTANTIATE_TEST_SUITE_P(
    OddInstance1,
    OddParamTest,
    Values(1, 3, 5, 7, 9)
);



INSTANTIATE_TEST_SUITE_P(
    OddInstance2,
    OddParamTest,
    Values(101, 103, 105, 107, 109)
);

TEST_P(OddParamTest, Odd)
{
    int n = GetParam();
    EXPECT_NE(n % 2, 0);
}

// --- param test demo end ---

class StrParamTest : public TestWithParam<std::string> {
};

INSTANTIATE_TEST_SUITE_P(
    StrInstance1,
    StrParamTest,
    Values("cat", "dog", "fish")
);

TEST_P(StrParamTest, Str)
{
    std::string s = GetParam();
    EXPECT_NE(s.size(), 0);
}

// --- mock test

class DepParamTest : public TestWithParam<std::tuple<ColorE, std::string>> {
public:
    DepParamTest() :mockDep_(std::make_shared<MockDep>()), tested_(BeTested(mockDep_)){

    }
public:
    std::shared_ptr<MockDep> mockDep_;
    BeTested tested_;
};

INSTANTIATE_TEST_SUITE_P(
    depInstance,
    DepParamTest,
    Values(
        std::make_tuple(ColorE::BLUE, "blue"),
        std::make_tuple(ColorE::GREEN, "green"),
        std::make_tuple(ColorE::RED, "red"),
        std::make_tuple(ColorE::YELLOW, "yellow")
    )
);

TEST_P(DepParamTest, depParamTest)
{
    auto param = GetParam();
    auto color = std::get<0>(param);
    auto str = std::get<1>(param);
    
    EXPECT_CALL(*mockDep_, passOneStr(str))
        .WillOnce(Return(true));

    EXPECT_TRUE(tested_.paramTest(color));
}

// TEST_P(DepParamTest, depParamTestFailed)
// {
//     auto param = GetParam();
//     auto color = std::get<0>(param);
//     auto str = std::get<1>(param);
    
//     EXPECT_CALL(*mockDep_, passOneStr(str + "_failed"))
//         .WillOnce(Return(true));

//     EXPECT_TRUE(tested_.paramTest(color));
// }