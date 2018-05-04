#include "363.h"

#include "thirdparty/gtest/gtest.h"

TEST(Test363, Test) {
    Solution s;
    vector<int> v;

    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    v.assign(a, a+sizeof(a)/sizeof(a[0]));
    EXPECT_EQ(6, s.trapRainWater(v));
}
