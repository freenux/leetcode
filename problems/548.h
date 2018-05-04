#ifndef LEETCODE_PROBLEMS_548_H
#define LEETCODE_PROBLEMS_548_H

#include <vector>

class Solution {
public:

    /*
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        vector<int> ret;
        int i1 = 0, i2 = 0;
        while (i1 < nums1.size() && i2 < nums2.size()) {
            if (nums1[i1] == nums2[i2]) {
                ret.push_back(nums1[i1]);
                i1++;
                i2++;
            } else if (nums1[i1] < nums2[i2]) {
                i1++;
            } else {
                i2++;
            }
        }
    }
};

#endif // LEETCODE_PROBLEMS_548_H
