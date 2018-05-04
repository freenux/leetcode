#ifndef LEETCODE_PROBLEMS_167_H
#define LEETCODE_PROBLEMS_167_H

#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    virtual ~ListNode() {
        delete next;
    }
};

class Solution {
public:
    /*
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     */
    ListNode * addLists(ListNode * l1, ListNode * l2) {
        ListNode* rl1 = l1;
        ListNode* rl2 = l2;

        ListNode* rl = NULL;
        ListNode* p = NULL;

        int carry = 0;
        while (rl1 != NULL || rl2 != NULL || carry != 0) {
            int d = carry;
            if (rl1 != NULL) {
                d += rl1->val;
                rl1 = rl1->next;
            }
            if (rl2 != NULL) {
                d += rl2->val;
                rl2 = rl2->next;
            }
            if (d >= 10) {
                carry = 1;
                d -= 10;
            } else {
                carry = 0;
            }

            ListNode* n = new ListNode(d);
            if (p != NULL) {
                p->next = n;
            } else {
                rl = n;
            }
            p = n;
        }

        return rl;
    }
};

#endif // LEETCODE_PROBLEMS_167_H
