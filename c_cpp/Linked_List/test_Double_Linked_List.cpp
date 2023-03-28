#include "Double_Linked_List.hpp"

// === test func === ===//
void test_ctor() {
    DoubleLinkedList ll1(12);
    ll1.print();

    DoubleLinkedList ll2(1, {2, 3, 4});
    ll2.print();

    DoubleLinkedList ll3({1, 2, 3, 4});
    ll3.print();
    /* ∅ <== 12 ==> ∅ */
    /* ∅ <== 1 <=> 2 <=> 3 <=> 4 ==> ∅ */
    /* ∅ <== 1 <=> 2 <=> 3 <=> 4 ==> ∅ */
    /* 1 2 3 4 deleted... */
    /* 1 2 3 4 deleted... */
    /* 12 deleted... */
}

void test_fundamental() {
    DoubleLinkedList ll1({1, 2, 3, 4});
    cout << "ll1=";
    ll1.print();
    cout << "len(ll1)=" << ll1.len() << endl;
    cout << "first: " << ll1.first()->val << endl;
    cout << "last: " << ll1.last()->val << endl;
    cout << "visit(1) : " << ll1.visit(1)->val << endl;
    cout << "rvisit(1) : " << ll1.rvisit(1)->val << endl;
    /* ll1=∅ <- 1 <-> 2 <-> 3 <-> 4 -> ∅ */
    /* len(ll1)=4 */
    /* first: 1 */
    /* last: 4 */
    /* visit(1) : 2 */
    /* rvisit(1) : 3 */
    /* 1 2 3 4 deleted... */
}

void test_insert() {
    DoubleLinkedList ll1({1, 2, 3, 4});
    ll1.print();
    ll1.insert(0, 3);
    ll1.insert(5, 3);
    ll1.insert(2, 3);
    ll1.print();
    /* ∅ <- 1 <-> 2 <-> 3 <-> 4 -> ∅ */
    /* ∅ <- 3 <-> 1 <-> 3 <-> 2 <-> 3 <-> 4 <-> 3 -> ∅ */
    /* 3 1 3 2 3 4 3 deleted... */
}

void test_pop() {
    DoubleLinkedList ll1({0, 1, 2, 3, 4});
    ll1.pop(12);
    ll1.pop(-1);
    ll1.pop(1);
    ll1.print(); // ∅ <- 1 <-> 3 -> ∅
    /* 1 3  deleted... */
}

void test_find_pop() {
    DoubleLinkedList ll1({1, 2, 3, 4});
    ll1.append(5);
    ll1.pop(0);
    ll1.pop_back();
    ll1.insert(4, 12);
    ll1.add2head(9);
    cout << "ll1.find(2):" << ll1.find(2) << endl;
    cout << "ll1.rfind(12):" << ll1.rfind(12) << endl;
    ll1.print();
    /* ll1.find(2):1 */
    /* ll1.rfind(12):0 */
    /* ∅ <- 9 <-> 2 <-> 3 <-> 4 <-> 12 -> ∅ */
    /* 9 2 3 4 12 deleted... */
}

void test_operator_at_modify() {
    DoubleLinkedList ll1({1, 2, 3, 4});
    ll1.append(1);
    ll1.remove(1, 3);
    ll1.print();
    cout << "ll1[0]=" << ll1[0]->val << endl;
    /* cout << "ll1[9]=" << ll1[9] << endl; */
    ll1.add2head(1);
    ll1.modify(1, 11, 3);
    ll1.print();
    /* can not find val 1 to delete */
    /* ∅ <- 2 <-> 3 <-> 4 -> ∅ */
    /* ll1[0]=2 */
    /* can not find val 1 to modify */
    /* ∅ <- 11 <-> 2 <-> 3 <-> 4 -> ∅ */
    /* 11 2 3 4 deleted... */
}

int main(int argc, char* argv[]) {
    test_ctor();
    /* test_fundamental(); */
    /* test_insert(); */
    /* test_pop(); */
    /* test_find_pop(); */
    /* test_operator_at_modify(); */
    return 0;
}
