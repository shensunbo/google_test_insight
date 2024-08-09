#include "gmock/gmock.h"
#include "MockFooO.h"

using namespace testing;

TEST(simpleMatcherTest, simpleMatcher1){
    MockFooO mock;
    Car car;

    EXPECT_CALL(mock, doThis(_)).Times(1);
    mock.doThis(car);

    // EXPECT_CALL(mock, doThis(Eq(car))).Times(1);
    // mock.doThis(car);
}

TEST(simpleMatcherTest, simpleMatcher2){
    MockFooO mock;

    EXPECT_CALL(mock, doAnything(Lt(10))).Times(1);
    mock.doAnything(-100);

    EXPECT_CALL(mock, doAnything(AllOf(Gt(10), Lt(15)))).Times(1);
    mock.doAnything(12);

    // EXPECT_CALL(mock, doNothing(Lt(10))).Times(1);
    // mock.doNothing(12);

}