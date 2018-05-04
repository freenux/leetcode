//
// Created by Administrator on 2018/1/25.
//

#ifndef LEETCODE_727_H
#define LEETCODE_727_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        int last = nums[0];
        int pos = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != last) {
                if (pos != i) {
                    nums[pos] = nums[i];
                }
                pos++;
            }
            last = nums[i];
        }

        return pos;
    }
};

#endif //LEETCODE_727_H
