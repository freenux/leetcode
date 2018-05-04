#include "54.h"

#include "thirdparty/gtest/gtest.h"

TEST(Test54, Test) {
    Solution s;
    std::string str;

    str = "10";
    EXPECT_EQ(atoi(str.c_str()), s.atoi(str));

    str = "-1";
    EXPECT_EQ(atoi(str.c_str()), s.atoi(str));

    str = "123123123123123";
    EXPECT_EQ(INT_MAX, s.atoi(str));

    str = "1.0";
    EXPECT_EQ(atoi(str.c_str()), s.atoi(str));

    str = "2147483647";
    EXPECT_EQ(INT_MAX, s.atoi(str));

    str = "-2147483648";
    EXPECT_EQ(INT_MIN, s.atoi(str));

    str = "-2147483647";
    EXPECT_EQ(-2147483647, s.atoi(str));

    str = "  10";
    EXPECT_EQ(atoi(str.c_str()), s.atoi(str));

    str = "  -10";
    EXPECT_EQ(atoi(str.c_str()), s.atoi(str));

    str = "  +10";
    EXPECT_EQ(atoi(str.c_str()), s.atoi(str));

    str = "  -k10";
    EXPECT_EQ(atoi(str.c_str()), s.atoi(str));

    str = " -00000012d121212121212121 ";
    EXPECT_EQ(atoi(str.c_str()), s.atoi(str));

    str = "";
    EXPECT_EQ(atoi(str.c_str()), s.atoi(str));
}
