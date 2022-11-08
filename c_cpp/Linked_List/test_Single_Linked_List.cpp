#include "Single_Linked_List.hpp"

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
