#include "167.h"

#include "thirdparty/gtest/gtest.h"

ListNode* buildList(int* a, int n) {
    if (0 == n || NULL == a) {
        return NULL;
    }

    ListNode* l = new ListNode(a[0]);
    ListNode* p = l;
    for (int i = 1; i < n; ++i) {
        ListNode* n = new ListNode(a[i]);
        p->next = n;
        p = n;
    }

    return l;
}

TEST(Test167, Test) {
    int a1[] = {3,1,2};
    ListNode* l1 = buildList(a1, sizeof(a1)/sizeof(a1[0]));
    int a2[] = {5,9,5,1};
    ListNode* l2 = buildList(a2, sizeof(a2)/sizeof(a2[0]));

    Solution s;
    ListNode* l = s.addLists(l1, l2);

    std::string num;
    for (ListNode* p = l; p != NULL; p = p->next) {
        num += p->val + '0';
    }
    EXPECT_EQ("8081", num);

    delete l;
    delete l1;
    delete l2;
}
