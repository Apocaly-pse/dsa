#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head) {
    if (!head) return head;
    ListNode *ans = new ListNode(head->val);
    while (head->next) {
        head = head->next;
        ListNode *node = new ListNode(head->val);
        node->next = ans;
        ans = node;
    }

    return ans;
}

void print(ListNode *ptr) {
    while (ptr) {
        cout << ptr->val;
        ptr = ptr->next;
    }
}

int main(int argc, char const *argv[]) {
    ListNode t1(1);
    ListNode t2(2);
    ListNode t3(3);
    t1.next = &t2;
    t2.next = &t3;
    // 遍历输出链表
    print(&t1);
    printf("\n");
    print(reverseList(&t1));

    return 0;
}
