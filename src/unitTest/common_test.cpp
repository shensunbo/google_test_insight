#include "MockPureVirtual.h"
#include "gmock/gmock.h"

using namespace testing;

TEST(OverloadFuncTest, test1){
    MockPureVirtual mock;

    EXPECT_CALL(mock, print(Matcher<int>(5))).Times(1);
    mock.print(5);

    EXPECT_CALL(mock, print(Matcher<char>(_))).Times(1);
    mock.print('a');

    //Creates a matcher that matches any value of the given type T
    EXPECT_CALL(mock, print(An<float>())).Times(1);
    mock.print(3.14f);

    // has type type and is equal to value. 
    //You may need to use this instead of Eq(value) when the mock function is overloaded.
    EXPECT_CALL(mock, print(TypedEq<std::string>("hello world"))).Times(1);
    mock.print("hello world");
}

TEST(OverloadFuncTest, test2){
    MockPureVirtual mock;
    
    EXPECT_CALL(mock, print(Matcher<int>(5))).Times(1);
    EXPECT_CALL(mock, print(Matcher<char>('a'))).Times(1);
    EXPECT_CALL(mock, print(Matcher<float>(1.0f))).Times(1);
    EXPECT_CALL(mock, print(Matcher<std::string>("hello"))).Times(1);

    mock.print(5);
    mock.print('a');
    mock.print(1.0f);
    mock.print("hello");
}