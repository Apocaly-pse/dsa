#ifndef BSTREE
#define BSTREE

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <functional> // 递归lambda


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

// 二叉树节点的结构体实现, 参考LeetCode
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
    // 树的生成
    void add_iter(int item); // 迭代方式生成树(广度遍历逆操作)
    void add_recur1();       // 递归捕获用户输入方式
    void add_recur2(vector<int>& item); // 直接遍历数组实现
    // 遍历部分
    void breadth_travel(); // bfs
    void pre_order();      // 前序(递归)
    void pre_order1();     // 迭代
    void pre_order2();     // 迭代(通解)

    void in_order();  // 中序(递归
    void in_order1(); // 迭代(指针)
    void in_order2(); // 迭代(通解)
    void in_order3(); // 迭代(通解)

    void post_order();  // 后序(递归)
    void post_order1(); // 从前序得到
    void post_order2(); // 通解
    void post_order3(); // 通解
    void post_order4(); // 通解

private:
    TreeNode* root;
};
#endif
