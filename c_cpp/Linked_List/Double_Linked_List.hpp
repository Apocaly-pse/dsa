#ifndef Double_Linked_List
#define Double_Linked_List
#include <iostream>
#include <vector>

// 双向链表实现
using namespace std;

class ListNode {
public:
    int val;
    ListNode* prev; // 前驱结点
    ListNode* next; // 后继结点
    ListNode() : ListNode(0, nullptr, nullptr) {}
    ListNode(int x) : ListNode(x, nullptr, nullptr) {}
    ListNode(int x, ListNode* _next) : ListNode(x, nullptr, _next) {}

    // 委托构造
    ListNode(int x, ListNode* _prev, ListNode* _next)
        : val(x), prev(_prev), next(_next) {}
};

ostream& operator<<(ostream& os, ListNode* lp);

class DoubleLinkedList {
public:
    DoubleLinkedList() : head(nullptr) {}
    DoubleLinkedList(int head_val) : head(new ListNode(head_val)) {}
    DoubleLinkedList(int head_val, vector<int> rest);
    DoubleLinkedList(vector<int> nodes);
    ~DoubleLinkedList();

    void print();
    ListNode* first();
    ListNode* last();
    int len();

    // visit by pos
    /* int& operator[](int pos); */
    ListNode* operator[](int pos);
    ListNode* visit(int pos);
    ListNode* rvisit(int pos);

    // insert by pos
    void insert(int pos, int val);
    void append(int val);
    void add2head(int val);

    // delete by pos
    void pop(int pos);
    void pop_back();
    void pop_front();
    // delete by value
    void remove(int val, int cnt = 1);           // delete val cnt times
    void modify(int val, int node, int cnt = 1); // modify val->node cnt times
    int find(int node);                          // not found:-1
    int rfind(int node);                         // not found:-1


private:
    ListNode* head;
};


ostream& operator<<(ostream& os, ListNode* lp) {
    if (lp == nullptr) return os << "∅" << endl;
    os << "∅ <== ";
    ListNode* cur = lp;
    while (cur != nullptr) {
        os << cur->val << (cur->next ? " <=> " : " ==> ");
        cur = cur->next;
    }
    os << "∅";
    return os << endl;
}


DoubleLinkedList::DoubleLinkedList(int head_val, vector<int> rest) {
    head = new ListNode(head_val);
    ListNode *cur = head, *nxt = nullptr;
    for (auto i : rest) {
        nxt = new ListNode(i);
        cur->next = nxt;
        nxt->prev = cur;
        cur = cur->next;
    }
}

DoubleLinkedList::DoubleLinkedList(vector<int> nodes) {
    if (nodes.empty()) {
        cout << "Empty Data Source!\n";
        return;
    }
    head = new ListNode(nodes[0]);
    auto cur = head;
    for (auto i = nodes.begin() + 1; i < nodes.end(); i++) {
        auto nxt = new ListNode(*i);
        cur->next = nxt;
        nxt->prev = cur;
        cur = cur->next;
    }
}

DoubleLinkedList::~DoubleLinkedList() {
    ListNode* cur;
    while (head->next) {
        cur = head->next;
        cout << head->val << " ";
        delete head;
        head = cur;
    }
    cout << head->val << " ";
    delete head;
    cout << "deleted...\n";
}

void DoubleLinkedList::print() { cout << head; }

ListNode* DoubleLinkedList::first() { return head; }

ListNode* DoubleLinkedList::last() {
    auto cur = head;
    while (cur->next) cur = cur->next;
    return cur;
}

int DoubleLinkedList::len() {
    int size = 0;
    auto cur = head;
    while (cur) ++size, cur = cur->next;
    return size;
}

/* int& DoubleLinkedList::operator[](int pos) { */
/*     if (head == nullptr) { */
/*         cerr << "Attempt to get value from a NULL DoubleLinkedList\n"; */
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

ListNode* DoubleLinkedList::operator[](int pos) {
    if (head == nullptr) {
        cerr << "Attempt to get value from a NULL DoubleLinkedList\n";
        exit(1);
    }
    if (pos > len() - 1 || pos < 0) {
        cerr << "Wrong pos!\n";
        exit(1);
    }
    auto cur = head;
    while (pos--) cur = cur->next;
    return cur;
}

ListNode* DoubleLinkedList::visit(int pos) {
    // 从左往右遍历找目标位置
    if (head == nullptr) {
        cerr << "Attempt to get value from a NULL DoubleLinkedList\n";
        exit(1);
    }
    if (pos > len() - 1 || pos < 0) {
        cerr << "Wrong pos!\n";
        exit(1);
    }
    auto cur = head;
    while (pos--) cur = cur->next;
    return cur;
}

ListNode* DoubleLinkedList::rvisit(int rpos) {
    // 从右往左遍历找目标位置
    if (head == nullptr) {
        cerr << "Attempt to get value from a NULL DoubleLinkedList\n";
        exit(1);
    }
    if (rpos > len() - 1 || rpos < 0) {
        cerr << "Wrong rpos!\n";
        exit(1);
    }
    auto cur = visit(len() - 1);
    while (rpos--) cur = cur->prev;
    return cur;
}


void DoubleLinkedList::insert(int pos, int val) {
    if (pos >= len()) {
        auto cur = last(), nxt = new ListNode(val);
        cur->next = nxt;
        nxt->prev = cur;
    } else if (pos <= 0) {
        auto cur = head;
        head = new ListNode(val);
        head->next = cur;
        cur->prev = head;
    } else { // 中间位置
        auto pre = head;
        while (--pos) pre = pre->next;

        // pre为待插入位置的前一个节点
        auto cur = pre->next;
        pre->next = new ListNode(val, pre, cur);
    }
}

void DoubleLinkedList::add2head(int val) { insert(0, val); }
void DoubleLinkedList::append(int val) { insert(len(), val); }

void DoubleLinkedList::pop(int pos) {
    if (head == nullptr) {
        cout << "Attempt to delete a NULL DoubleLinkedList!" << endl;
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr; // 指针置为空, 避免空悬指针, 下同
    } else {
        if (pos >= len() - 1) {
            // 使用内置的visit函数
            auto cur = rvisit(1), tmp = cur->next;
            delete tmp;
            cur->next = nullptr; // 必须加, 否则析构时候会出错
        } else if (pos <= 0) {
            auto cur = head->next;
            delete head;
            head = cur;
        } else {
            auto cur = visit(pos - 1);
            auto nxt = cur->next->next, tmp = cur->next;
            cur->next = nxt;
            delete tmp;
        }
    }
}
void DoubleLinkedList::pop_front() { pop(0); }
void DoubleLinkedList::pop_back() { pop(len()); }

int DoubleLinkedList::find(int node) {
    if (head == nullptr) return -1;
    auto cur = head;
    int pos{};
    while (cur) {
        if (cur->val == node) return pos;
        ++pos;
        cur = cur->next;
    }
    return -1;
}

int DoubleLinkedList::rfind(int node) {
    // 从右往左找
    auto cur = last();
    if (cur == nullptr) return -1;
    int pos{};
    while (cur) {
        if (cur->val == node) return pos;
        ++pos;
        cur = cur->prev;
    }
    return -1;
}

void DoubleLinkedList::remove(int val, int cnt) {
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
void DoubleLinkedList::modify(int val, int node, int cnt) {
    int idx;
    do {
        if ((idx = find(val)) == -1) {
            cout << "can not find val " << val << " to modify\n";
            break;
        } else {
            /* visit(idx)->val = node; */
            (*this)[idx]->val = node;
        }
    } while (--cnt);
}
#endif // !DoubleLinkedList
