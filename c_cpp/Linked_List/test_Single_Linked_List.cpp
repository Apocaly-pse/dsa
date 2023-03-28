#include "Single_Linked_List.hpp"

// === test func === ===//
void test_ctor() {
    SingleLinkedList ll1(12);
    ll1.print();

    SingleLinkedList ll2(1, {2, 3, 4});
    ll2.print();

    SingleLinkedList ll3({1, 2, 3, 4});
    ll3.print();
    /*
       12 -> ∅
        1 -> 2 -> 3 -> 4 -> ∅
        1 -> 2 -> 3 -> 4 -> ∅
    */
}

void test_fundamental() {
    SingleLinkedList ll1({1, 2, 3, 4});
    ll1.print();
    cout << "len(ll1)=" << ll1.len() << endl;
    cout << ll1.first()->val << endl;
    cout << ll1.last()->val << endl;
    /* 1 -> 2 -> 3 -> 4 -> ∅ */
    /* len(ll1)=4 */
    /* 1 */
    /* 4 */
}

void test_append_pop() {
    SingleLinkedList ll1({1, 2, 3, 4});
    ll1.append(5);
    ll1.pop(0);
    ll1.pop_back();
    ll1.print();
    /* 2 -> 3 -> 4 -> ∅ */
    ll1.insert(4, 12);
    ll1.add2head(9);
    ll1.print();
    /* 9 -> 2 -> 3 -> 4 -> 12 -> ∅ */
}

void test_find_modify() {
    SingleLinkedList ll1({1, 2, 3, 4});
    cout << "ll1.find(2):" << ll1.find(2) << endl;
    cout << "ll1.find(12):" << ll1.find(12) << endl;
    ll1.append(1);
    /* ll1.remove(1, 3); */
    cout << "ll1[0]=" << ll1[0]->val << endl;
    cout << "ll1[0]=" << ll1.visit(0)->val << endl;
    /* cout << "ll1[9]=" << ll1[9] << endl; */
    ll1.modify(1, 11, 3);
    ll1.print();
    /* ll1.find(2):1 */
    /* ll1.find(12):-1 */
    /* ll1[0]=1 */
    /* ll1[0]=1 */
    /* can not find val 1 to modify */
    /* 11 -> 2 -> 3 -> 4 -> 11 -> ∅ */
}
int main(int argc, char* argv[]) {
    /* test_ctor(); */
    /* test_fundamental(); */
    /* test_append_pop(); */
    test_find_modify();
    return 0;
}
