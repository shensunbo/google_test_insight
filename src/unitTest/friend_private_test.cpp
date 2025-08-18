#include "gtest/gtest.h"
#include "Base.h"

using namespace testing;

// friend class test
class BaseTest : public Test {
protected:
    int getBaseNum(const Base& base) {
        return base.num_;
    }

    std::string getBaseName(const Base& base) {
        return base.name_;
    }

    // change some internal state
    void setBaseNum(Base& base, int num) {
        base.num_ = num;
    }

    void setBaseName(Base& base, std::string name) {
        base.name_ = name;
    }
};

TEST_F(BaseTest, getNum) {
    Base base(1, "test");
    EXPECT_EQ(1, getBaseNum(base));
}

TEST_F(BaseTest, getName) {
    Base base(1, "test");
    EXPECT_EQ("test", getBaseName(base));
}

TEST_F(BaseTest, setNum) {
    Base base(1, "test");
    base.setNum(2);
    EXPECT_EQ(2, getBaseNum(base));
}

TEST_F(BaseTest, friendSetNum) {
    Base base(1, "test");
    setBaseNum(base, -30);
    EXPECT_EQ(-30, getBaseNum(base));
}

TEST_F(BaseTest, friendSetName) {
    Base base(1, "test");
    setBaseName(base, "fromFriend");
    EXPECT_EQ("fromFriend", getBaseName(base));
}

// friend function test
void memberStateTest(const Base& base, int a, std::string str){
    EXPECT_EQ(a, base.num_);
    EXPECT_EQ(str, base.name_);
}

TEST(FunctionTest, memberStateTest) {
    Base base(1, "test");
    memberStateTest(base, 1, "test");
}

TEST(FunctionTest, memberStateTest2) {
    Base base(1, "test");
    base.setNum(123);
    memberStateTest(base, 123, "test");
}