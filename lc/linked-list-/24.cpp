#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next1) : val(x), next(next1) {}
};

ostream& operator<<(ostream& os, ListNode* lp) {
    ListNode* cur = lp;
    while (cur != nullptr) {
        os << cur->val << " -> ";
        cur = cur->next;
    }
    os << "∅";
    return os << endl;
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        using Lp = ListNode*;
        Lp cur = head;
        head = head->next;
        cur->next = head->next;
        head->next = cur;
        Lp pre = cur;
        cur = cur->next;
        while (cur && nullptr != cur->next) {
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = cur;
            // update
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};


int main(int argc, char* argv[]) {
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    for (auto& i : {2, 3, 4}) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cout << head;
    Solution s;
    cout << s.swapPairs(head);
    delete head;
    return 0;
}
