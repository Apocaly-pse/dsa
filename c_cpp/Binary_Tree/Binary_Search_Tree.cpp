#include "bst.h"


// 递归版本生成二叉树(需要捕获用户输入)
void BinaryTree::add_recur1() {
    function<TreeNode*(void)> f = [&](void) {
        int data;
        cin >> data;
        if (data == 0) {
            return (TreeNode*)nullptr;
        }
        TreeNode* node = new TreeNode(data);
        node->val = data;
        node->left = f();
        node->right = f();
        return node;
    };
    root = f();
}

// 递归生成二叉树: 直接遍历外部数组实现
void BinaryTree::add_recur2(vector<int>& item) {
    function<TreeNode*(void)> f = [&](void) {
        if (item.empty() || item.front() == 0) {
            item.erase(item.begin());
            return (TreeNode*)nullptr;
        }
        TreeNode* node = new TreeNode(item.front());
        node->val = item.front();
        item.erase(item.begin());
        node->left = f();
        node->right = f();
        return node;
    };
    root = f();
}


void BinaryTree::add_iter(int item) {
    TreeNode* node = new TreeNode(item);

    if (!root) {
        root = node;
        return;
    }
    // 用队列模拟二叉树的层序遍历
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
        TreeNode* cur_node = que.front();
        que.pop();

        if (!cur_node->left) {
            cur_node->left = node;
            return;
        } else
            que.push(cur_node->left);

        // 接下来同样判断右边
        if (!cur_node->right) {
            cur_node->right = node;
            return;
        } else
            que.push(cur_node->right);
    }
}

void BinaryTree::breadth_travel() {
    queue<TreeNode*> que;
    que.push(root);
    vector<int> ret;
    if (!root) return;
    while (!que.empty()) {
        TreeNode* cur_node = que.front();
        que.pop();
        // 也可以直接打印, 省去了定义数组的步骤
        // cout<< cur_node->val<<endl;
        ret.push_back(cur_node->val);

        if (cur_node->left) que.push(cur_node->left);
        if (cur_node->right) que.push(cur_node->right);
    }
    cout << ret << endl;
}

/********** pre order **********/

void BinaryTree::pre_order() {
    vector<int> ret;
    auto recur_0 = [&ret](auto&& self, TreeNode* node) {
        // 递归终止条件
        if (!node) return;
        ret.push_back(node->val);
        self(self, node->left);
        self(self, node->right);
    };
    recur_0(recur_0, root);
    cout << ret << endl;
}

void BinaryTree::pre_order1() {
    vector<int> ret;
    stack<TreeNode*> st;
    if (root) st.push(root);
    while (!st.empty()) {
        auto node = st.top();
        st.pop();
        ret.push_back(node->val);
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }

    cout << ret << endl;
}
void BinaryTree::pre_order2() {
    vector<int> ret{};
    stack<pair<int, TreeNode*>> st;
    if (root) st.push(make_pair(0, root));
    int color;
    TreeNode* node;
    while (!st.empty()) {
        auto [color, node] = st.top();
        st.pop();
        if (node == nullptr) continue;
        if (color == 0) {
            st.push(make_pair(0, node->right));
            st.push(make_pair(0, node->left));
            st.push(make_pair(1, node));
        } else {
            ret.push_back(node->val);
        }
    }
    cout << ret << endl;
}

/********** in order **********/

void BinaryTree::in_order() {
    vector<int> ret;
    auto recur_1 = [&ret](auto&& self, TreeNode* node) {
        if (!node) return;

        self(self, node->left);
        ret.push_back(node->val);
        self(self, node->right);
    };
    recur_1(recur_1, root);
    cout << ret << endl;
}

void BinaryTree::in_order1() {
    vector<int> ret;
    stack<TreeNode*> st;
    auto cur = root;
    while (!st.empty() || cur) {
        if (cur) {
            st.push(cur);
            cur = cur->left;
        } else {
            cur = st.top();
            st.pop();
            ret.push_back(cur->val);
            cur = cur->right;
        }
    }
    cout << ret << endl;
}

void BinaryTree::in_order2() {
    vector<int> ret;
    stack<TreeNode*> st;
    if (root) {
        st.push(root);
    }
    while (!st.empty()) {
        auto node = st.top();
        st.pop();
        if (node) {
            if (node->right) {
                st.push(node->right);
            }
            st.push(node);
            st.push(nullptr);
            if (node->left) {
                st.push(node->left);
            }
        } else {
            node = st.top();
            st.pop();
            ret.push_back(node->val);
        }
    }
    cout << ret << endl;
}

void BinaryTree::in_order3() {
    vector<int> ret{};
    stack<pair<int, TreeNode*>> st;
    if (root) st.push(make_pair(0, root));
    int color;
    TreeNode* node;
    while (!st.empty()) {
        auto [color, node] = st.top();
        st.pop();
        if (node == nullptr) continue;
        if (color == 0) {
            st.push(make_pair(0, node->right));
            st.push(make_pair(1, node));
            st.push(make_pair(0, node->left));
        } else {
            ret.push_back(node->val);
        }
    }
    cout << ret << endl;
}

/********** post order **********/

void BinaryTree::post_order() {
    vector<int> ret;
    auto recur_2 = [&ret](auto&& self, TreeNode* node) {
        if (!node) return;

        self(self, node->left);
        self(self, node->right);
        ret.push_back(node->val);
    };
    recur_2(recur_2, root);
    cout << ret << endl;
}

void BinaryTree::post_order1() {
    stack<TreeNode*> st;
    vector<int> ret;
    if (root) {
        st.push(root);
    }
    while (!st.empty()) {
        auto node = st.top();
        st.pop();
        ret.push_back(node->val);
        if (node->left) st.push(node->left);
        if (node->right) st.push(node->right);
    }
    // 进行逆序操作: 或者采用逆序算法
    // vector<int> ret1;
    // for (auto it = ret.rbegin(); it != ret.rend(); it++)
    // ret1.push_back(*it);
    reverse(ret.begin(), ret.end());

    cout << ret << endl;
}

void BinaryTree::post_order2() {
    stack<TreeNode*> st;
    vector<int> ret;
    auto node = root;
    while (!st.empty() || node) {
        while (node) {
            st.push(node);
            node = node->left ? node->left : node->right;
        }
        node = st.top();
        st.pop();
        ret.push_back(node->val);
        node =
            !st.empty() && st.top()->left == node ? st.top()->right : nullptr;
    }

    cout << ret << endl;
}

void BinaryTree::post_order3() {
    stack<TreeNode*> st;
    vector<int> ret;
    TreeNode* node = root;
    while (!st.empty() || node) {
        if (node) {
            ret.push_back(node->val);
            if (node->left) st.push(node->left);
            node = node->right;
        } else {
            node = st.top();
            st.pop();
        }
    }
    reverse(ret.begin(), ret.end());

    cout << ret << endl;
}

void BinaryTree::post_order4() {
    vector<int> ret{};
    stack<pair<int, TreeNode*>> st;
    if (root) st.push(make_pair(0, root));
    int color;
    TreeNode* node;
    while (!st.empty()) {
        auto [color, node] = st.top();
        st.pop();
        if (node == nullptr) continue;
        if (color == 0) {
            st.push(make_pair(1, node));
            st.push(make_pair(0, node->right));
            st.push(make_pair(0, node->left));
        } else {
            ret.push_back(node->val);
        }
    }
    cout << ret << endl;
}


int main(int argc, char const* argv[]) {
    BinaryTree tree;
    // 第一种生成方式, 层序生成(使用队列进行循环)
    for (int i = 1; i < 8; ++i) {
        tree.add_iter(i);
    }

    // // 第二种生成方式, 递归生成(前序递归), 需要传入用户输入
    // tree.add_recur1();

    // // 第三种(同第二种), 递归生成, 直接读取数组即可
    // vector<int> arr = {1, 2, 0, 4, 0, 0, 3, 0, 5, 0, 0};
    // vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 0, 0, 0, 0, 0, 0, 0, 0};
    // vector<int> arr = {1, 2, 4, 0, 0, 5, 0, 0, 3, 6, 0, 0, 7, 0, 0};
    // vector<int> arr = {1, 2, 0, 5, 0, 0, 3, 0, 0};
    // tree.add_recur2(arr);

    // 下面是遍历
    // 广度遍历
    cout << "breadth_travel:\n";
    tree.breadth_travel();

    // 前序遍历(递归)
    cout << "\npre_order_recur:\n";
    tree.pre_order();
    // 前序遍历(循环)
    cout << "pre_order_iter1:\n";
    tree.pre_order1();
    cout << "pre_order_iter2:\n";
    tree.pre_order2();

    // 中序遍历(递归)
    cout << "\nin_order_recur:\n";
    tree.in_order();
    // 中序遍历(循环)
    cout << "in_order_iter1:\n";
    tree.in_order1();
    cout << "in_order_iter2:\n";
    tree.in_order2();
    cout << "in_order_iter3:\n";
    tree.in_order3();

    // 后序遍历(递归)
    cout << "\npost_order_recur:\n";
    tree.post_order();
    // 后序遍历(循环)
    cout << "post_order_iter1:\n";
    tree.post_order1();
    cout << "post_order_iter2:\n";
    tree.post_order2();
    cout << "post_order_iter3:\n";
    tree.post_order3();
    cout << "post_order_iter4:\n";
    tree.post_order4();
    return 0;
    /*
breadth_travel:
[1, 2, 3, 4, 5, 6, 7]

pre_order_recur:
[1, 2, 4, 5, 3, 6, 7]
pre_order_iter1:
[1, 2, 4, 5, 3, 6, 7]
pre_order_iter2:
[1, 2, 4, 5, 3, 6, 7]

in_order_recur:
[4, 2, 5, 1, 6, 3, 7]
in_order_iter1:
[4, 2, 5, 1, 6, 3, 7]
in_order_iter2:
[4, 2, 5, 1, 6, 3, 7]
in_order_iter3:
[4, 2, 5, 1, 6, 3, 7]

post_order_recur:
[4, 5, 2, 6, 7, 3, 1]
post_order_iter1:
[4, 5, 2, 6, 7, 3, 1]
post_order_iter2:
[4, 5, 2, 6, 7, 3, 1]
post_order_iter3:
[4, 5, 2, 6, 7, 3, 1]
post_order_iter4:
[4, 5, 2, 6, 7, 3, 1]
    */
}
