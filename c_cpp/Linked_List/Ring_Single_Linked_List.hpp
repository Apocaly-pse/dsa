#ifndef Ring_Single_Linked_List
#define Ring_Single_Linked_List
#include <cstddef>
#include <iostream>
#include <vector>


using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* _next) : val(x), next(_next) {}
};

ostream& operator<<(ostream& os, ListNode* lp);

class RingSingleLinkedList {
public:
    RingSingleLinkedList() : head(nullptr) {}
    RingSingleLinkedList(int head_val) : head(new ListNode(head_val)) {
        head->next = head; // 一个节点成环
    }
    RingSingleLinkedList(int head_val, vector<int> rest);
    RingSingleLinkedList(vector<int> nodes);
    ~RingSingleLinkedList();

    void print();
    ListNode* first();
    ListNode* last();
    int len();

    // visit by pos
    /* int& operator[](int pos); */
    ListNode* operator[](int pos);
    ListNode* visit(int pos);

    // insert by pos
    void insert(int pos, int val);
    void append(int val);

    // delete by pos
    void pop(int pos);
    void pop_front();
    // delete by value
    void remove(int val, int cnt = 1);           // delete val cnt times
    void modify(int val, int node, int cnt = 1); // modify val->node cnt times
    int find(int node);                          // not found:-1


private:
    ListNode* head;
};


ostream& operator<<(ostream& os, ListNode* lp) {
    if (lp == nullptr) return os << "∅" << endl;
    ListNode* cur = lp;

    auto num_len = [](int num) {
        size_t ans{};
        while (num) ++ans, num /= 10;
        return ans;
    };

    size_t show_len = 4 + num_len(cur->val);
    os << cur->val << " -> ";
    while (cur->next != lp) {
        os << cur->next->val << " -> ";
        show_len += num_len(cur->next->val) + 4;
        cur = cur->next;
    }
    os << " |"s << endl;
    os << "^"s << string(show_len, ' ') << "|"s << endl;
    os << "|" << string(show_len, '_') << "|"s;
    return os << endl;
}


RingSingleLinkedList::RingSingleLinkedList(int head_val, vector<int> rest) {
    head = new ListNode(head_val);
    auto cur = head;
    for (auto i : rest) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cur->next = head;
}

RingSingleLinkedList::RingSingleLinkedList(vector<int> nodes) {
    if (nodes.empty()) return;
    head = new ListNode(nodes[0]);
    auto cur = head;
    for (auto i = nodes.begin() + 1; i < nodes.end(); i++) {
        cur->next = new ListNode(*i);
        cur = cur->next;
    }
    cur->next = head;
}

RingSingleLinkedList::~RingSingleLinkedList() {
    if (head == nullptr) return;
    ListNode *dummy = new ListNode(0, head), *tmp;
    while (head->next != dummy->next) {
        tmp = head->next;
        cout << head->val << " ";
        delete head;
        head = tmp;
    }
    cout << head->val << " ";
    delete head;
    head = nullptr;
    cout << "deleted...\n";
    delete dummy;
}

void RingSingleLinkedList::print() { cout << head; }

ListNode* RingSingleLinkedList::first() { return head; }

ListNode* RingSingleLinkedList::last() {
    auto cur = head;
    while (cur->next != head) cur = cur->next;
    return cur;
}

int RingSingleLinkedList::len() {
    if (head == nullptr) return 0;
    int size = 1;
    auto cur = head;
    while (cur->next != head) ++size, cur = cur->next;

    return size;
}

/* int& RingSingleLinkedList::operator[](int pos) { */
/*     if (head == nullptr) { */
/*         cerr << "Attempt to get value from a NULL RingSingleLinkedList\n"; */
/*         exit(1); */
/*     } */
/*     if (pos > len() - 1 || pos < 0) { */
/*         cerr << "Wrong pos!\n"; */
/*         exit(1); */
/*     } */
/*     auto cur = head; */
/*     while (pos--) cur = cur->next; */
/*     return cur->val; */
/* } */

ListNode* RingSingleLinkedList::operator[](int pos) {
    if (head == nullptr)
        cout << "Attempt to get value from a NULL RingSingleLinkedList\n";

    pos = pos < 0 ? pos % len() + len() : pos % len();

    auto cur = head;
    while (pos--) cur = cur->next;
    return cur;
}

ListNode* RingSingleLinkedList::visit(int pos) { return this->operator[](pos); }


void RingSingleLinkedList::insert(int pos, int val) {
    if (head == nullptr) {
        head = new ListNode(val);
        head->next = head;
        return;
    }
    pos = pos < 0 ? pos % len() + len() : pos % len();
    if (pos == 0) { // change head
        auto cur = head;
        head = new ListNode(val, cur);
        cur->next = head;
    } else {
        auto pre = head;
        while (--pos) pre = pre->next;

        auto cur = pre->next;
        pre->next = new ListNode(val, cur);
    }
}

void RingSingleLinkedList::append(int val) { insert(0, val); }

void RingSingleLinkedList::pop(int pos) {
    if (head == nullptr) {
        cout << "Attempt to delete a NULL RingSingleLinkedList!" << endl;
        return;
    }
    pos = pos < 0 ? pos % len() + len() : pos % len();
    if (len() == 1) {
        delete head;
        head = nullptr;
        return;
    }
    auto cur = head;
    while (--pos > 0) cur = cur->next; // 只判断 pos 不为零不行
    auto tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
}
void RingSingleLinkedList::pop_front() { pop(0); }

int RingSingleLinkedList::find(int node) {
    if (head == nullptr) return -1;
    if (head->val == node) return 0;
    auto cur = head;
    int pos{};
    while (cur->next != head) {
        if (cur->val == node) return pos;
        ++pos;
        cur = cur->next;
    }
    return -1;
}

void RingSingleLinkedList::remove(int val, int cnt) {
    int idx;
    do {
        if ((idx = find(val)) == -1) {
            cout << "can not find val " << val << " to delete\n";
            break;
        } else
            pop(idx);
    } while (--cnt);
}

// modify val->node cnt times
void RingSingleLinkedList::modify(int val, int node, int cnt) {
    int idx;
    do {
        if ((idx = find(val)) == -1) {
            cout << "can not find val " << val << " to modify\n";
            break;
        } else {
            /* visit(idx)->val = node; */
            /* (*this)[idx]->val = node; */
            this->operator[](idx)->val = node;
        }
    } while (--cnt);
}
#endif // !RingSingleLinkedList
