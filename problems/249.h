#ifndef LEETCODE_PROBLEM_249_H
#define LEETCODE_PROBLEM_249_H

#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param A: an integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        vector<int> result;
        if (A.empty()) {
            return result;
        }

        result.push_back(0);
        for (size_t i = 1; i < A.size(); ++i) {
            int n = A[i];
            int j = i-1;
            for (;A[j] >= n && j >= 0; --j) {
                A[j+1] = A[j];
            }

            result.push_back(j + 1);
            A[j+1] = n;
        }

        return result;
    }
};

#endif //LEETCODE_PROBLEM_249_H
