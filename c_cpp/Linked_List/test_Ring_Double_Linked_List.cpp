#include "Ring_Double_Linked_List.hpp"

// === test func === ===//
void test_ctor() {
    RingDoubleLinkedList ll1(12);
    ll1.print();

    RingDoubleLinkedList ll2(1, {2, 3, 4});
    ll2.print();

    RingDoubleLinkedList ll3({1, 2, 3, 4});
    ll3.print();
    /* 12 <=> || */
    /* /\     || */
    /* ||=====|| */
    /* 1 <=> 2 <=> 3 <=> 4 <=> || */
    /* /\                      || */
    /* ||======================|| */
    /* 1 <=> 2 <=> 3 <=> 4 <=> || */
    /* /\                      || */
    /* ||======================|| */
    /* 1 2 3 4 deleted... */
    /* 1 2 3 4 deleted... */
    /* 12 deleted... */
}

void test_fundamental() {
    RingDoubleLinkedList ll1({1, 2, 3, 4});
    cout << ll1.len() << endl;
    cout << ll1.first()->val << endl;
    cout << ll1.last()->val << endl;
    /* 4 */
    /* 1 */
    /* 4 */
    /* 1 2 3 4 deleted... */
}

void test_operator_at() {
    RingDoubleLinkedList ll1({1, 2, 3, 4});
    cout << ll1[-10]->val << endl;     // 3
    cout << ll1[0]->val << endl;       // 1
    cout << ll1[2]->val << endl;       // 3
    cout << ll1[9]->val << endl;       // 2
    cout << ll1.visit(9)->val << endl; // 2
}

void test_insert_1() {
    RingDoubleLinkedList ll1;
    ll1.append(20);
    ll1.append(30);
    ll1.insert(-1, 2);
    ll1.print();
    /* 30 <=> 2 <=> 20 <=> || */
    /* /\                  || */
    /* ||==================|| */
    /* 30 2 20 deleted... */
}

void test_insert_2() {
    RingDoubleLinkedList ll1({1, 2, 3, 4});
    ll1.insert(1, 2);
    ll1.print();
    /* 1 <=> 2 <=> 2 <=> 3 <=> 4 <=> || */
    /* /\                            || */
    /* ||============================|| */
    /* 1 2 2 3 4 deleted... */
}

void test_pop_1() {
    RingDoubleLinkedList ll1({1, 2, 3, 4});
    ll1.pop(1);
    ll1.pop(1);
    ll1.pop(1);
    /* ll1.pop(1); */
    ll1.pop_front();
    ll1.print(); // ∅
}

void test_find() {
    RingDoubleLinkedList ll1({1, 2, 3, 4});
    cout << ll1.find(1) << endl; // 0
    cout << ll1.find(3) << endl; // 2
    cout << ll1.find(5) << endl; //-1
}

void test_remove_modify() {
    RingDoubleLinkedList ll1({1, 1, 3, 4});
    ll1.modify(1, 23, 2);
    ll1.remove(23, 1);
    ll1.print();
    /* 23 <=> 3 <=> 4 <=> || */
    /* /\                 || */
    /* ||=================|| */
    /* 23 3 4 deleted... */
}


int main(int argc, char* argv[]) {
    /* test_ctor(); */
    /* test_fundamental(); */
    /* test_operator_at(); */
    /* test_insert_1(); */
    /* test_insert_2(); */
    /* test_pop_1(); */
    /* test_find(); */
    test_remove_modify();
    return 0;
}
