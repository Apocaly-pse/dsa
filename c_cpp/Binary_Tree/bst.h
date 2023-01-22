#ifndef BSTREE
#define BSTREE

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

struct BSTreeNode {
    int val;
    BSTreeNode* left;
    BSTreeNode* right;
    // used by remove and insert
    BSTreeNode* parent;

    BSTreeNode(int x, BSTreeNode* left1, BSTreeNode* right1)
        : val(x), left(left1), right(right1) {}
    BSTreeNode() : BSTreeNode(0, nullptr, nullptr) {}
    BSTreeNode(int x) : BSTreeNode(x, nullptr, nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree();
    // 树的生成
    void build_from_array(vector<int>&); // 不会出现不平衡的
    // 遍历部分
    void breadth_travel(); // bfs
    void print_tree();     // bfs
    void in_order_recur(); // 顺序输出
    void in_order_iter();  // 顺序输出
    // 以结点x为根的树的最大节点,最小节点
    BSTreeNode* maximum(BSTreeNode*);
    BSTreeNode* minimum(BSTreeNode*);
    // 整个树的最大值最小值
    int MAX();
    int MIN();
    // 前驱节点,后继结点
    BSTreeNode* predecessor(BSTreeNode*);
    BSTreeNode* successor(BSTreeNode*);
    // 树结点的查找, 添加和删除
    BSTreeNode* search(int);
    void insert(int);
    void remove_1(BSTreeNode*);
    void remove(BSTreeNode*);

private:
    BSTreeNode* root;
    BSTreeNode* _search(BSTreeNode*, int);
    void transplant(BSTreeNode*, BSTreeNode*);
};
#endif
