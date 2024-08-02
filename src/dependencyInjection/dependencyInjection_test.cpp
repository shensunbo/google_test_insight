#include "gmock/gmock.h"

#include "MockDep.h"
#include "BeTested.h"

class DepTest : public ::testing::Test {

public:
    DepTest() :mockDep_(std::make_shared<MockDep>()), tested_(BeTested(mockDep_)){

    }
public:
    std::shared_ptr<MockDep> mockDep_;
    BeTested tested_;
};

TEST_F(DepTest, funcWithDepTest1) {
    EXPECT_CALL(*mockDep_, doSomething(1000))
        .Times(1)
        .WillOnce(testing::Return(true));

    bool res = tested_.funcWithDep(1000);
    EXPECT_TRUE(res);
}

TEST_F(DepTest, funcWithDepTest2) {
    EXPECT_CALL(*mockDep_, doSomething(66))
        .Times(1)
        .WillOnce(testing::Return(false));

    bool res = tested_.funcWithDep(66);
    EXPECT_FALSE(res);
}