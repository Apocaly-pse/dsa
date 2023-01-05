#include "bt.h"

BinaryTree::~BinaryTree() {
    function<void(TreeNode*)> f = [&](TreeNode* node) {
        if (!node) return;
        cout << node->val << "deleted.." << endl;
        TreeNode* Left_Tree = node->left;
        TreeNode* Right_Tree = node->right;
        delete node;
        if (Left_Tree) // 左子树非空则释放
            f(Left_Tree);
        if (Right_Tree) // 同
            f(Right_Tree);
    };
    function<void(TreeNode*)> g = [&](TreeNode* node) {
        if (!node) return;
        stack<TreeNode*> st;
        st.push(node);
        while (!st.empty()) {
            node = st.top();
            st.pop();
            cout << node->val << "deleted...\n";
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
            delete node;
        }
    };
    // recur dtor by preorder
    // f(root);
    // iter dtor by preorder
    g(root);
}

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
    /* int color; */
    /* TreeNode* node; */
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

void BinaryTree::morris_preorder() {
    if (!root) return;
    vector<int> ans{};
    TreeNode* cur = root;
    TreeNode* mostRight;
    while (cur) {
        mostRight = cur->left;
        if (mostRight) {
            while (mostRight->right and mostRight->right != cur)
                mostRight = mostRight->right;
            if (!mostRight->right) {
                mostRight->right = cur;
                ans.push_back(cur->val);
                cur = cur->left;
                continue;
            } else
                mostRight->right = nullptr;
        } else
            ans.push_back(cur->val);
        cur = cur->right;
    }
    cout << ans << endl;
}

// 一般方法(前中后都可用, 通过空节点'标记'根节点位置)
void BinaryTree::pre_order3() {
    vector<int> ret;
    stack<TreeNode*> st;
    if (root) st.push(root);
    while (!st.empty()) {
        auto node = st.top();
        st.pop();
        if (node) {
            // 添加右节点, 空节点不入栈
            if (node->right) st.push(node->right);
            // 添加左节点, 空节点不入栈
            if (node->left) st.push(node->left);
            st.push(node); // 中(根)节点标记
            st.push(nullptr);
        } else {
            node = st.top();
            st.pop();
            ret.push_back(node->val);
        }
    }
    cout << ret << endl;
}


/*Morris 前序遍历的流程如下：
第一步.当前结点的左孩子是否为空，若是则输出当前结点，并更新当前结点为当前结点的右孩子；否则进入第二步.
第二步.在当前结点的左子树中寻找左子树中最右结点作为前驱结点
a.若前驱结点的右孩子为空,则将前驱结点的右孩子指向当前结点,输出当前结点.当前结点更新为当前结点的左孩子,
进入第三步.
b.若前驱结点的右孩子为当前结点（不为空）,将前驱结点的右孩子置NULL,当前结点更新为当前结点的右孩子,
进入第三步.
第三步.若当前结点不为空,进入第一步；否则程序结束
*/
void BinaryTree::morris_preorder1() {
    if (!root) return;
    vector<int> ans{};
    TreeNode *cur = root, *pre = nullptr;
    while (cur) {
        if (!cur->left) {
            ans.push_back(cur->val);
            cur = cur->right;
        } else {
            // 定位左子树
            pre = cur->left;
            // 找左子树的最右节点(不能与cur相同)
            while (pre->right && pre->right != cur) pre = pre->right;
            if (!pre->right) {
                pre->right = cur;
                ans.push_back(cur->val);
                cur = cur->left;
            } else {
                pre->right = nullptr;
                cur = cur->right;
            }
        }
    }
    cout << ans << endl;
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
            cur = cur->left; // 左
        } else {
            cur = st.top();
            st.pop();
            ret.push_back(cur->val); // 根
            cur = cur->right;        // 右
        }
    }
    cout << ret << endl;
}

// 一般方法(前中后都可用, 通过空节点'标记'根节点位置)
void BinaryTree::in_order2() {
    vector<int> ret;
    stack<TreeNode*> st;
    if (root) st.push(root);
    while (!st.empty()) {
        auto node = st.top();
        st.pop();
        if (node) {
            // 添加右节点, 空节点不入栈
            if (node->right) st.push(node->right);
            st.push(node); // 中(根)节点标记
            st.push(nullptr);
            // 添加左节点, 空节点不入栈
            if (node->left) st.push(node->left);
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
    /* int color; */
    /* TreeNode* node; */
    while (!st.empty()) {
        auto [color, node] = st.top(); // C++17
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

void BinaryTree::morris_inorder() {
    if (!root) return;
    vector<int> ans{};
    TreeNode* cur = root;
    TreeNode* mostRight;
    while (cur) {
        mostRight = cur->left;
        if (mostRight) {
            while (mostRight->right and mostRight->right != cur)
                mostRight = mostRight->right;
            if (!mostRight->right) {
                mostRight->right = cur;
                cur = cur->left;
                continue;
            } else
                mostRight->right = nullptr;
        }
        ans.push_back(cur->val);
        cur = cur->right;
    }
    cout << ans << endl;
}

/*Morris 中序遍历的流程如下:
第一步.当前结点的左孩子是否为空,若是则输出当前结点,并更新当前结点为当前结点的右孩子;否则进入第二步.
第二步.在当前结点的左子树中寻找左子树中最右结点作为前驱结点
a.若前驱结点的右孩子为空,则将前驱结点的右孩子指向当前结点,当前结点更新为当前结点的左孩子;进入第三步;
b.若前驱结点的右孩子为当前结点（不为空）,将前驱结点的右孩子置NULL,输出当前结点,当前结点更新为当前结点的右孩子,进入第三步;
第三步.若当前结点不为空, 进入第一步; 否则程序结束*/
void BinaryTree::morris_inorder1() {
    if (!root) return;
    vector<int> ans{};
    TreeNode *cur = root, *pre = nullptr;
    while (cur) {
        if (!cur->left) {
            ans.push_back(cur->val);
            cur = cur->right;
        } else {
            pre = cur->left;
            while (pre->right && pre->right != cur) pre = pre->right;
            if (!pre->right) {
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = nullptr;
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    cout << ans << endl;
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

// 从前序的逆序得到
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
    /* int color; */
    /* TreeNode* node; */
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

// 一般方法(前中后都可用, 通过空节点'标记'根节点位置)
void BinaryTree::post_order5() {
    vector<int> ret;
    stack<TreeNode*> st;
    if (root) st.push(root);
    while (!st.empty()) {
        auto node = st.top();
        st.pop();
        if (node) {
            st.push(node); // 中(根)节点标记
            st.push(nullptr);
            // 添加右节点, 空节点不入栈
            if (node->right) st.push(node->right);
            // 添加左节点, 空节点不入栈
            if (node->left) st.push(node->left);
        } else {
            node = st.top();
            st.pop();
            ret.push_back(node->val);
        }
    }
    cout << ret << endl;
}


/*Morris 后序遍历的流程如下:
新建一个Dummy结点,该结点的左孩子指向树根root,将Dummy作为当前结点;
第一步.当前结点的左孩子是否为空,更新当前结点为当前结点的右孩子;否则进入第二步;
第二步.在当前结点的左子树中寻找中序遍历下的前驱结点（左子树中最右结点）:
a.若前驱结点的右孩子为空,则将前驱结点的右孩子指向当前结点,当前结点更新为当前结点的左孩子,进入3;
b.若前驱结点的右孩子为当前结点（不为空）,反转当前结点左孩子到前驱结点之间的路径,输出该路径所有结点;再反转恢复原状.
将前驱结点的右孩子置NULL,当前结点更新为当前结点的右孩子,进入第三步;
第三步.若当前结点不为空,进入第一步;否则程序结束*/
void BinaryTree::morris_postorder() {
    if (!root) return;
    vector<int> ans{};

    function<TreeNode*(TreeNode*)> reverseEdge = [&](TreeNode* node) {
        TreeNode *pre = nullptr, *next = nullptr;
        while (node) {
            next = node->right;
            node->right = pre;
            pre = node;
            node = next;
        }
        return pre;
    };

    function<void(TreeNode*)> printEdge = [&](TreeNode* node) {
        TreeNode* tail = reverseEdge(node);
        TreeNode* cur = tail;
        while (cur) {
            ans.push_back(cur->val);
            cur = cur->right;
        }
        reverseEdge(tail);
    };
    TreeNode *cur = root, *mostRight;
    while (cur) {
        mostRight = cur->left;
        if (mostRight) {
            while (mostRight->right and mostRight->right != cur)
                mostRight = mostRight->right;
            if (!mostRight->right) {
                mostRight->right = cur;
                cur = cur->left;
                continue;
            } else {
                mostRight->right = nullptr;
                printEdge(cur->left);
            }
        }
        cur = cur->right;
    }
    printEdge(root);
    cout << ans << endl;
}

/*
1.新建临时节点cur,令该节点为 root;
2.如果当前节点的左子节点为空,则遍历当前节点的右子节点;
3.如果当前节点的左子节点不为空,在当前节点的左子树中找到当前节点在中序遍历下的前驱节点;
    a.如果前驱节点的右子节点为空,将前驱节点的右子节点设置为当前节点,当前节点更新为当前节点的左子节点.
    b.如果前驱节点的右子节点为当前节点,将它的右子节点重新设为空.
倒序输出从当前节点的左子节点到该前驱节点这条路径上的所有节点.
当前节点更新为当前节点的右子节点.
4.重复步骤2和步骤3,直到遍历结束.
*/
void BinaryTree::morris_postorder1() {
    if (!root) return;
    vector<int> res;

    function<void(TreeNode*)> addPath = [&](TreeNode* node) {
        // addPath 添加至结果数组, 然后完成部分数组反转
        int count{};
        while (node) {
            ++count;
            res.emplace_back(node->val);
            node = node->right;
        }
        reverse(res.end() - count, res.end());
    };
    TreeNode *cur = root, *pre = nullptr;
    while (cur) {
        pre = cur->left;
        if (!pre)
            cur = cur->right;
        else {
            while (pre->right && pre->right != cur) pre = pre->right;
            if (!pre->right) {
                pre->right = cur;
                cur = cur->left;
            } else {
                pre->right = nullptr;
                addPath(cur->left);
                cur = cur->right;
            }
        }
    }
    addPath(root);
    cout << res << endl;
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
    cout << "pre_order_iter3:\n";
    tree.pre_order3();
    cout << "morris_preorder:\n";
    tree.morris_preorder();
    tree.morris_preorder1();


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
    cout << "morris_inorder:\n";
    tree.morris_inorder();
    tree.morris_inorder1();


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
    cout << "post_order_iter5:\n";
    tree.post_order5();
    cout << "morris_postorder:\n";
    tree.morris_postorder();
    tree.morris_postorder1();

    return 0;
    /*
    breadth_travel:
    [1, 2, 3, 4, 5, 6, 7]

    pre_order_recur:
    [1, 2, 4, 5, 3, 6, 7]

    in_order_recur:
    [4, 2, 5, 1, 6, 3, 7]

    post_order_recur:
    [4, 5, 2, 6, 7, 3, 1]
    */
}
