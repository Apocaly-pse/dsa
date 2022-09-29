#ifndef BTREE
#define BTREE

#include <iostream>
#include <queue>
#include <stack>
#include <vector>


using namespace std;

// 重载<<操作符输出数组
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << (it != v.end() - 1 ? ", " : "] ");
    }
    return os;
}

// 二叉树节点的结构体实现
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};


class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {}
    void add_iter(int item);
    TreeNode* add_recur1();
    TreeNode* add_recur2(vector<int>& item);
    void breadth_travel();
    void pre_order();
    void pre_order1();
    void in_order();
    void in_order1();
    void in_order2();
    void post_order();
    void post_order1();
    void post_order2();

private:
    TreeNode* root;
};

#endif