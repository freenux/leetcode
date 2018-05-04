#include "249.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

void ExpectVector(std::vector<int> input, const std::vector<int>& output) {
    Solution s;
    vector<int> result = s.countOfSmallerNumberII(input);
    EXPECT_THAT(result, output);
}

TEST(Test249, Test) {
    int input[] = {1,2,7,8,5};
    int output[] = {0,1,2,3,2};
    ExpectVector(
        std::vector<int>(input, input+sizeof(input)/sizeof(input[0])),
        std::vector<int>(output, output+sizeof(output)/sizeof(output[0]))
    );

    int input1[] = {68,64,53,43,38,3};
    int output1[] = {0,0,0,0,0,0};
    ExpectVector(
        std::vector<int>(input1, input1+sizeof(input1)/sizeof(input1[0])),
        std::vector<int>(output1, output1+sizeof(output1)/sizeof(output1[0]))
    );

    int input2[] = {26,78,27,100};
    int output2[] = {0,1,1,3};
    ExpectVector(
        std::vector<int>(input2, input2+sizeof(input2)/sizeof(input2[0])),
        std::vector<int>(output2, output2+sizeof(output2)/sizeof(output2[0]))
    );

    int input3[] = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    int output3[] = {0,1,1,3,2,3,5,0,4,0,5,1,6,2,9,2,14,10,17,14,16,7,16,7,22,2,0,25,1,20,29,15,4,6,28,20,20,16,37,18};
    ExpectVector(
        std::vector<int>(input3, input3+sizeof(input3)/sizeof(input3[0])),
        std::vector<int>(output3, output3+sizeof(output3)/sizeof(output3[0]))
    );
}
