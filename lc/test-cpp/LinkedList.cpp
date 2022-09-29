#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ostream& operator<<(ostream& os, const ListNode* node) {
    os << "[";
    while (node) {
        os << node->val << (node->next ? ", " : "]\n");
        node = node->next;
    }
    // os << endl;
    return os;
}


void t1() {
    ListNode* root = new ListNode(1), *curNode = root;
    for (auto &i : {2, 3, 4, 5}) {
        curNode->next = new ListNode(i);
        curNode = curNode->next;
    }
    cout << root;
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}