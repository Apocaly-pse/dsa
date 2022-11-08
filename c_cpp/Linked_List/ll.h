#ifndef Linked_List
#define Linked_List
#include <cstddef>
#include <unistd.h>
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

class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    LinkedList(int head_val) : head(new ListNode(head_val)) {}
    LinkedList(int head_val, vector<int> rest);
    LinkedList(vector<int> nodes);
    ~LinkedList() {}

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


#endif // !LinkedList
