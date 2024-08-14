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

    EXPECT_CALL(mock, doNothing(HasSubstr("match"))).Times(1);
    mock.doNothing("simple matcher");
}

//
// Container Matcher
//
TEST(simpleMatcherTest, ContainerMatcher){
    MockFooO mock;

    std::vector<int> vecBase = {1,2,3,4,5};
    EXPECT_CALL(mock, containerInput(Contains(5))).Times(1);

    std::vector<int> vecIn = {1,2,3,4,5};
    mock.containerInput(vecIn);

    EXPECT_CALL(mock, containerInput(Each(Lt(10)))).Times(1);
    mock.containerInput(vecIn);

    EXPECT_CALL(mock, containerInput(Eq(vecBase))).Times(1);
    mock.containerInput(vecIn);

    EXPECT_CALL(mock, containerInput(SizeIs(5))).Times(1);
    mock.containerInput(vecIn);

    EXPECT_CALL(mock, containerInput(ElementsAre(1,2,3,4,5))).Times(1);
    mock.containerInput(vecIn);
}