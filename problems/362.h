//
// Created by Administrator on 2018/1/25.
//

#ifndef LEETCODE_362_H
#define LEETCODE_362_H

#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> nums, int k) {
        vector<int> maxVec;
        if (nums.empty()) {
            return maxVec;
        }

        int max_index = max_i(nums, 0, k);
        int max = nums[max_index];

        maxVec.push_back(max);
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > max) {
                max_index = i;
                max = nums[i];
            } else if (max_index + k == i) {
                max_index = max_i(nums, i - k + 1, k);
                max = nums[max_index];
            }
            maxVec.push_back(max);
        }
        return maxVec;
    }

private:
    int max_i(vector<int> nums, int s, int k) {
        int max_index = -1;
        int max = INT_MIN;
        for (int i = s; i < k+s && i < nums.size(); ++i) {
            if (nums[i] > max) {
                max_index = i;
                max = nums[i];
            }
        }

        return max_index;
    }
};

#endif //LEETCODE_362_H
