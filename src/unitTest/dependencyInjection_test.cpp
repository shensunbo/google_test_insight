#include "gmock/gmock.h"

#include "MockDep.h"
#include "BeTested.h"

using namespace testing;

// 1. test dependency Injection
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

TEST_F(DepTest, funcNeedMatcherWithFieldTest1){
    EXPECT_CALL(*mockDep_, funcNeedMatcher(AllOf(Field(&Car::cool, true), Field(&Car::price, 999))))
        .Times(1)
        .WillOnce(testing::Return(true));

    Car testCar;
    testCar.cool = true;
    testCar.price = 999;

    bool res = tested_.setCar(testCar);
    EXPECT_TRUE(res);
}

//Field is designed to match a specific field in an object, 
//but it doesn't support nested fields or fields that are part of a nested object
// TEST_F(DepTest, funcNeedMatcherWithFieldTest2){
//     EXPECT_CALL(*mockDep_, funcNeedMatcher(&Car::wheel_.foo, 999))
//         .Times(1)
//         .WillOnce(testing::Return(true));

//     Car testCar;
//     testCar.wheel_.foo = 999;

//     bool res = tested_.setCar(testCar);
//     EXPECT_TRUE(res);
// }


MATCHER_P(CarMatcher, expected, "Car MATCHER_P :-)") {
  return arg.wheel_.foo == expected.wheel_.foo && arg.engin_.bar == expected.engin_.bar;
}

TEST_F(DepTest, funcNeedMatcherNestedTest1){
    // auto matcher = [](const Car& car) { 
    //     return car.wheel_.foo == 999 && car.engin_.bar == 888; 
    // };
    Car mock={};
    mock.wheel_.foo = 999;
    mock.engin_.bar = 888;
    EXPECT_CALL(*mockDep_, funcNeedMatcher(CarMatcher(mock)))
        .Times(1)
        .WillOnce(testing::Return(true));

    Car testCar;
    testCar.wheel_.foo = 999;
    testCar.engin_.bar = 888;

    bool res = tested_.setCar(testCar);
    EXPECT_TRUE(res);
}