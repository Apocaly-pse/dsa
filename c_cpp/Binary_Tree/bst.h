#ifndef BSTREE
#define BSTREE

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <tuple>
#include <cmath>
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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    // used by remove and insert
    TreeNode* parent;

    TreeNode() : val(0), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(int x, TreeNode* left1, TreeNode* right1)
        : val(x), left(left1), right(right1), parent(nullptr) {}
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
    TreeNode* maximum(TreeNode*);
    TreeNode* minimum(TreeNode*);
    // 整个树的最大值最小值
    int MAX();
    int MIN();
    // 前驱节点,后继结点
    TreeNode* predecessor(TreeNode*);
    TreeNode* successor(TreeNode*);
    // 树结点的查找, 添加和删除
    TreeNode* search(int);
    void insert(int);
    void remove_1(TreeNode*);
    void remove(TreeNode*);

private:
    TreeNode* root;
    TreeNode* _search(TreeNode*, int);
    void transplant(TreeNode*, TreeNode*);
};
#endif
