#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ostream &operator<<(ostream &os, const ListNode *node) {
    os << "[";
    while (node) {
        os << node->val << (node->next ? ", " : "]\n");
        node = node->next;
    }
    return os;
}


// class Solution {
// public:
//     ListNode *reverseBetween(ListNode *head, int left, int right) {
//         auto dummy = new ListNode(0, head);
//     }
// };


class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        // 设置 dummyNode 是这一类问题的一般做法
        ListNode *dummyNode = new ListNode(-1, head);
        ListNode *pre = dummyNode;
        for (int i = 0; i < left - 1; i++) { pre = pre->next; }
        ListNode *cur = pre->next;
        ListNode *next;
        for (int i = 0; i < right - left; i++) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummyNode->next;
    }
};


void t1() {
    Solution s;
    ListNode *root = new ListNode(1), *curNode = root;
    for (auto &i : {2, 3, 4, 5}) {
        curNode->next = new ListNode(i);
        curNode = curNode->next;
    }
    cout << root;
    ListNode *lp = s.reverseBetween(root, 2, 4);
    cout << lp;
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}