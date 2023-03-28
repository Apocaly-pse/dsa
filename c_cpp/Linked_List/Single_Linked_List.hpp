#ifndef Single_Linked_List
#define Single_Linked_List
#include <iostream>
#include <vector>


using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next1) : val(x), next(next1) {}
};

ostream& operator<<(ostream& os, ListNode* lp);

class SingleLinkedList {
public:
    SingleLinkedList() : head(nullptr) {}
    SingleLinkedList(int head_val) : head(new ListNode(head_val)) {}
    SingleLinkedList(int head_val, vector<int> rest);
    SingleLinkedList(vector<int> nodes);
    ~SingleLinkedList();

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
    void add2head(int val);

    // delete by pos
    void pop(int pos);
    void pop_back();
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
    while (cur != nullptr) {
        os << cur->val << " -> ";
        cur = cur->next;
    }
    os << "∅";
    return os << endl;
}


SingleLinkedList::SingleLinkedList(int head_val, vector<int> rest) {
    head = new ListNode(head_val);
    auto cur = head;
    for (auto i : rest) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
}

SingleLinkedList::SingleLinkedList(vector<int> nodes) {
    if (nodes.empty()) return;
    head = new ListNode(nodes[0]);
    auto cur = head;
    for (auto i = nodes.begin() + 1; i < nodes.end(); i++) {
        cur->next = new ListNode(*i);
        cur = cur->next;
    }
}

SingleLinkedList::~SingleLinkedList() {
    ListNode* cur;
    while (head->next) {
        cur = head->next;
        delete head;
        head = cur;
    }
    delete head;
}

void SingleLinkedList::print() { cout << head; }

ListNode* SingleLinkedList::first() { return head; }

ListNode* SingleLinkedList::last() {
    auto cur = head;
    while (cur->next) cur = cur->next;
    return cur;
}

int SingleLinkedList::len() {
    int size = 0;
    auto cur = head;
    while (cur) {
        size++;
        cur = cur->next;
    }
    return size;
}

/* int& SingleLinkedList::operator[](int pos) { */
/*     if (head == nullptr) { */
/*         cerr << "Attempt to get value from a NULL SingleLinkedList\n"; */
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

ListNode* SingleLinkedList::operator[](int pos) {
    if (head == nullptr) {
        cerr << "Attempt to get value from a NULL SingleLinkedList\n";
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

ListNode* SingleLinkedList::visit(int pos) { return operator[](pos); }


void SingleLinkedList::insert(int pos, int val) {
    if (pos >= len()) {
        auto cur = last();
        cur->next = new ListNode(val);
    } else if (pos <= 0) {
        auto cur = head;
        head = new ListNode(val);
        head->next = cur;
    } else {
        auto pre = head;
        while (--pos) pre = pre->next;

        auto cur = pre->next;
        pre->next = new ListNode(val, cur);
    }
}

void SingleLinkedList::add2head(int val) { insert(0, val); }
void SingleLinkedList::append(int val) { insert(len(), val); }

void SingleLinkedList::pop(int pos) {
    if (head == nullptr) {
        cout << "Attempt to delete a NULL SingleLinkedList!" << endl;
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        if (pos >= len() - 1) {
            auto cur = head;
            while (cur->next && cur->next->next) cur = cur->next;
            cur->next = nullptr;
        } else if (pos <= 0) {
            auto cur = head->next;
            delete head;
            head = cur;
        } else {
            auto cur = head;
            while (--pos) cur = cur->next;
            cur->next = cur->next->next;
        }
    }
}
void SingleLinkedList::pop_front() { pop(0); }
void SingleLinkedList::pop_back() { pop(len()); }

int SingleLinkedList::find(int node) {
    if (head == nullptr) return -1;
    auto cur = head;
    int pos{};
    while (cur) {
        if (cur->val == node) return pos;
        pos++;
        cur = cur->next;
    }
    return -1;
}

void SingleLinkedList::remove(int val, int cnt) {
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
void SingleLinkedList::modify(int val, int node, int cnt) {
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
#endif // !SingleLinkedList
