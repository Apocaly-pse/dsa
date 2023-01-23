#ifndef RBTREE
#define RBTREE

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <functional> // 递归lambda


using namespace std;

// 重载<<操作符输出数组
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    if (v.empty()) return os << "[]\n";
    os << "[";
    for (auto it = v.begin(); it != v.end(); it++) {
        os << *it << (it != v.end() - 1 ? ", " : "] \n");
    }
    return os;
}

struct RBTreeNode {
    int val;
    RBTreeNode* left;
    RBTreeNode* right;
    bool color; // true:black, false:red
    RBTreeNode* parent;

    RBTreeNode(int val1, RBTreeNode* l1, RBTreeNode* r1, bool c1)
        : val(val1), left(l1), right(r1), color(c1) {}

    RBTreeNode() : RBTreeNode(0, nullptr, nullptr, true) {}
    RBTreeNode(int x) : RBTreeNode(x, nullptr, nullptr, true) {}
    RBTreeNode(int x, bool c1) : RBTreeNode(x, nullptr, nullptr, c1) {}
    RBTreeNode(int x, RBTreeNode* l1, RBTreeNode* r1)
        : RBTreeNode(x, l1, r1, true) {}
};

class RedBlackTree {
public:
    RedBlackTree() : root(nullptr) {}
    ~RedBlackTree();
    // 遍历部分
    void breadth_travel();                       // bfs
    void print_tree(bool = false, bool = false); // bfs
    void in_order();                             // 顺序输出
    // rotate
    void left_rotate(RBTreeNode*);
    void right_rotate(RBTreeNode*);
    // 以结点x为根的树的最大节点,最小节点
    RBTreeNode* maximum(RBTreeNode*);
    RBTreeNode* minimum(RBTreeNode*);
    // 整个树的最大值最小值
    int MAX();
    int MIN();
    // 前驱节点,后继结点
    RBTreeNode* predecessor(RBTreeNode*);
    RBTreeNode* successor(RBTreeNode*);
    // 树结点的查找, 添加和删除
    RBTreeNode* search(int);
    void insert(int);
    void remove(RBTreeNode*);

private:
    RBTreeNode* root;
    static RBTreeNode* nil;
    void insert_fixup(RBTreeNode*);
    void delete_fixup(RBTreeNode*);
    RBTreeNode* _search(RBTreeNode*, int);
    void transplant(RBTreeNode*, RBTreeNode*);
};
#endif
