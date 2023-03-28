#include "Ring_Single_Linked_List.hpp"

// === test func === ===//
void test_ctor() {
    RingSingleLinkedList ll1(12);
    ll1.print();

    RingSingleLinkedList ll2(1, {2, 3, 4});
    ll2.print();

    RingSingleLinkedList ll3({1, 2, 3, 4});
    ll3.print();
    /*
    12 ->  |
    ^      |
    |______|
    1 -> 2 -> 3 -> 4 ->  |
    ^                    |
    |____________________|
    1 -> 2 -> 3 -> 4 ->  |
    ^                    |
    |____________________|
    1 2 3 4 deleted...
    1 2 3 4 deleted...
    12 deleted...
    */
}

void test_fundamental() {

    RingSingleLinkedList ll1({1, 2, 3, 4});
    cout << ll1.len() << endl;
    cout << ll1.first()->val << endl;
    cout << ll1.last()->val << endl;
    /* 4 */
    /* 1 */
    /* 4 */
    /* 1 2 3 4 deleted... */
}

void test_operator_at() {
    RingSingleLinkedList ll1({1, 2, 3, 4});
    cout << ll1[-10]->val << endl;     // 3
    cout << ll1[0]->val << endl;       // 1
    cout << ll1[2]->val << endl;       // 3
    cout << ll1[9]->val << endl;       // 2
    cout << ll1.visit(9)->val << endl; // 2
}

void test_insert_1() {
    RingSingleLinkedList ll1;
    ll1.append(20);
    ll1.append(30);
    ll1.insert(-1, 2);
    ll1.print();
    // TODO: 一个小bug, 插入第一个节点之后, 再插入第二个节点时, 只能改变头结点,
    // 因为取余会导致1变为0
    /* 30 -> 2 -> 20 ->  | */
    /* ^                 | */
    /* |_________________| */
    /* 30 2 20 deleted... */
}

void test_insert_2() {
    RingSingleLinkedList ll1({1, 2, 3, 4});
    ll1.insert(1, 2);
    ll1.print();
    /* 1 -> 2 -> 2 -> 3 -> 4 ->  | */
    /* ^                         | */
    /* |_________________________| */
    /* 1 2 2 3 4 deleted... */
}

void test_pop_1() {
    RingSingleLinkedList ll1({1, 2, 3, 4});
    ll1.pop(1);
    ll1.pop(1);
    ll1.pop(1);
    /* ll1.pop(1); */
    ll1.pop_front();
    ll1.print(); // ∅
}

void test_find() {
    RingSingleLinkedList ll1({1, 2, 3, 4});
    cout << ll1.find(1) << endl; // 0
    cout << ll1.find(3) << endl; // 2
    cout << ll1.find(5) << endl; //-1
}

void test_remove_modify() {
    RingSingleLinkedList ll1({1, 1, 3, 4});
    ll1.modify(1, 23, 2);
    ll1.remove(23, 1);
    ll1.print();
    /* 23 -> 3 -> 4 ->  | */
    /* ^                | */
    /* |________________| */
    /* 23 3 4 deleted... */
}


int main(int argc, char* argv[]) {
    /* test_ctor(); */
    /* test_fundamental(); */
    /* test_operator_at(); */
    test_insert_1();
    /* test_insert_2(); */
    /* test_pop_1(); */
    /* test_find(); */
    /* test_remove_modify(); */
    return 0;
}
