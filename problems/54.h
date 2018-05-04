#ifndef LEETCODE_PROBLEMS_54_H
#define LEETCODE_PROBLEMS_54_H

#include <climits>
#include <string>

using namespace std;

class Solution {
public:
    /*
     * @param str: A string
     * @return: An integer
     */
    int atoi(string &str) {
        size_t start = 0;
        while (start < str.size() && isspace(str[start])) {
            ++start;
        }

        bool negative = false;
        if (start < str.size() && (str[start] == '-' || str[start] == '+')) {
            negative = str[start] == '-';
            ++start;
        }

        int num = 0;
        for (; start < str.size(); ++start) {
            char c = str[start];
            if (!isdigit(c)) {
                break;
            }

            int d = c - '0';
            int next = num * 10 + d;
            if (next < 0) {
                return negative ? INT_MIN : INT_MAX;
            }
            num = next;
        }

        if (negative) {
            num = 0 - num;
        }

        return num;
    }
};

#endif // LEETCODE_PROBLEMS_54_H
