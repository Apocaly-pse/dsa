#include "ll.h"
#include <iostream>

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


LinkedList::LinkedList(int head_val, vector<int> rest) {
    head = new ListNode(head_val);
    auto cur = head;
    for (auto i : rest) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
}

LinkedList::LinkedList(vector<int> nodes) {
    if (nodes.empty()) return;
    head = new ListNode(nodes[0]);
    auto cur = head;
    for (auto i = nodes.begin() + 1; i < nodes.end(); i++) {
        cur->next = new ListNode(*i);
        cur = cur->next;
    }
}

void LinkedList::print() { cout << head; }

ListNode* LinkedList::first() { return head; }

ListNode* LinkedList::last() {
    auto cur = head;
    while (cur->next) cur = cur->next;
    return cur;
}

int LinkedList::len() {
    int size = 0;
    auto cur = head;
    while (cur) {
        size++;
        cur = cur->next;
    }
    return size;
}

/* int& LinkedList::operator[](int pos) { */
/*     if (head == nullptr) { */
/*         cerr << "Attempt to get value from a NULL LinkedList\n"; */
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

ListNode* LinkedList::operator[](int pos) {
    if (head == nullptr) {
        cerr << "Attempt to get value from a NULL LinkedList\n";
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
ListNode* LinkedList::visit(int pos) {
    if (head == nullptr) {
        cerr << "Attempt to get value from a NULL LinkedList\n";
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


void LinkedList::insert(int pos, int val) {
    if (pos >= len()) {
        auto cur = last();
        cur->next = new ListNode(val);
    } else if (pos <= 0) {
        auto cur = head;
        head = new ListNode(val);
        head->next = cur;
    } else {
        auto pre = head;
        while (--pos) {
            pre = pre->next;
        }
        auto cur = pre->next;
        pre->next = new ListNode(val, cur);
    }
}

void LinkedList::add2head(int val) { insert(0, val); }
void LinkedList::append(int val) { insert(len(), val); }

void LinkedList::pop(int pos) {
    if (head == nullptr) {
        cout << "Attempt to delete a NULL LinkedList!" << endl;
    } else if (head->next == nullptr) {
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
void LinkedList::pop_front() { pop(0); }
void LinkedList::pop_back() { pop(len()); }

int LinkedList::find(int node) {
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

void LinkedList::remove(int val, int cnt) {
    int idx;
    do {
        if ((idx = find(val)) == -1) {
            cout << "can not find val " << val << " to delete\n";
            return;
        } else
            pop(idx);
    } while (--cnt);
}

// modify val->node cnt times
void LinkedList::modify(int val, int node, int cnt) {
    int idx;
    do {
        if ((idx = find(val)) == -1) {
            cout << "can not find val " << val << " to modify\n";
            return;
        } else {
            /* visit(idx)->val = node; */
            (*this)[idx]->val = node;
        }
    } while (--cnt);
}


// === test func === ===//
void test_ctor() {
    LinkedList ll1(12);
    ll1.print();

    LinkedList ll2(1, {2, 3, 4});
    ll2.print();

    LinkedList ll3({1, 2, 3, 4});
    ll3.print();
    /*
       12 -> ∅
        1 -> 2 -> 3 -> 4 -> ∅
        1 -> 2 -> 3 -> 4 -> ∅
    */
}

void test_func() {
    LinkedList ll1({1, 2, 3, 4});
    /* LinkedList ll1({1, 2}); */
    /* LinkedList ll1; */
    cout << "ll1=";
    ll1.print();
    cout << "len(ll1)=" << ll1.len() << endl;
    /* cout << ll1.first()->val << endl; */
    /* cout << ll1.last()->val << endl; */
    /* ll1.append(5); */
    /* ll1.pop(0); */
    /* ll1.pop_back(); */
    /* ll1.insert(4, 12); */
    /* ll1.add2head(9); */
    /* cout << "ll1.find(2):" << ll1.find(2) << endl; */
    /* cout << "ll1.find(12):" << ll1.find(12) << endl; */
    ll1.append(1);
    /* ll1.remove(1, 3); */
    cout << "ll1[0]=" << ll1[0]->val << endl;
    /* cout << "ll1[9]=" << ll1[9] << endl; */
    ll1.modify(1, 11, 3);
    ll1.print();
}
int main(int argc, char* argv[]) {
    /* test_ctor(); */
    test_func();
    return 0;
}
