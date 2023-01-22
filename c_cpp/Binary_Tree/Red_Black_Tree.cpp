#include "rbt.h"
#include <chrono>

RBTreeNode *RedBlackTree::nil = new RBTreeNode();

RedBlackTree::~RedBlackTree() {
    function<void(RBTreeNode *)> f = [&](RBTreeNode *node) {
        if (!node || node == RedBlackTree::nil) return;
        RBTreeNode *Left_Tree = node->left;
        RBTreeNode *Right_Tree = node->right;
        cout << node->val << " ";
        delete node;
        if (Left_Tree) f(Left_Tree);
        if (Right_Tree) f(Right_Tree);
    };
    f(root);
    cout << " deleted..\n";
}

void RedBlackTree::breadth_travel() {
    if (!root) return;
    queue<RBTreeNode *> que;
    que.push(root);
    vector<int> ret;
    while (!que.empty()) {
        RBTreeNode *cur = que.front();
        que.pop();
        ret.emplace_back(cur->val);

        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
    }
    cout << ret;
}

void RedBlackTree::print_tree(bool iscolor, bool show_nil) {
    if (!root) return;
    queue<RBTreeNode *> q;
    q.push(root);
    int m = 0;
    while (!q.empty()) {
        int qs = q.size();
        for (auto i = 0; i < qs; i++) {
            auto cur = q.front();
            q.pop();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        m++;
    }
    int n = (1 << m) - 1;
    vector<vector<string>> ans(m, vector<string>(n, " "));
    vector<vector<string>> branch(m, vector<string>(n, " "));
    queue<tuple<int, int, RBTreeNode *, string>> bq;
    bq.push({0, (n - 1) / 2, root, ""s});
    while (!bq.empty()) {
        int bqs = bq.size();
        for (auto i = 0; i < bqs; i++) {
            auto &[r, c, cur, slash] = bq.front();
            bq.pop();
            if (!show_nil && !cur->val) continue; // 表示不打印nil节点
            // 打印值或颜色
            ans[r][c] = to_string(iscolor ? cur->color : cur->val);
            if (r == m - 1) {
                branch[r][c] = slash;
            } else {
                if (slash == "/"s)
                    branch[r][c + 1] = slash;
                else
                    branch[r][c - 1] = slash;
            }
            if (cur->left)
                bq.push({r + 1, c - pow(2, m - r - 2), cur->left, "/"s});
            if (cur->right)
                bq.push({r + 1, c + pow(2, m - r - 2), cur->right, "\\"s});
        }
    }
    for (int i = 0; i < m; i++) {
        for (auto &s : branch[i]) cout << s;
        cout << endl;
        for (auto &s : ans[i]) cout << s;
        cout << endl;
    }
}

void RedBlackTree::in_order() {
    if (!root) return;
    vector<int> ret;
    stack<RBTreeNode *> st;
    auto cur = root;
    while (!st.empty() || cur) {
        if (cur) {
            st.push(cur);
            cur = cur->left;
        } else {
            cur = st.top();
            st.pop();
            ret.emplace_back(cur->val);
            cur = cur->right;
        }
    }
    cout << ret;
}

RBTreeNode *RedBlackTree::maximum(RBTreeNode *x) {
    while (x->right != RedBlackTree::nil) x = x->right;
    return x;
}

RBTreeNode *RedBlackTree::minimum(RBTreeNode *x) {
    while (x->left != RedBlackTree::nil) x = x->left;
    return x;
}

int RedBlackTree::MAX() { return maximum(root)->val; }
int RedBlackTree::MIN() { return minimum(root)->val; }

RBTreeNode *RedBlackTree::successor(RBTreeNode *x) {
    // 如果结点x的右子树非空, 则x后继结点就是其右子树的最左节点(minimum)
    if (x->right != RedBlackTree::nil) return minimum(x->right);
    RBTreeNode *y = x->parent;
    // 如果x右子树为空且其后继结点存在, 则其后继就是x的有左孩子的最底层祖先
    while (y != RedBlackTree::nil && x == y->right) x = y, y = y->parent;
    return y;
}

RBTreeNode *RedBlackTree::predecessor(RBTreeNode *x) {
    if (x->left != RedBlackTree::nil) return maximum(x->left);
    RBTreeNode *y = x->parent;
    while (y != RedBlackTree::nil && x == y->left) x = y, y = y->parent;
    return y;
}

RBTreeNode *RedBlackTree::_search(RBTreeNode *x, int target) {
    /* if (!x || target == x->val) return x; */
    /* if (target < x->val) */
    /*     return _search(x->left, target); */
    /* else */
    /*     return _search(x->right, target); */
    while (x && target != x->val)
        if (target < x->val)
            x = x->left;
        else
            x = x->right;
    return x;
}

RBTreeNode *RedBlackTree::search(int target) { return _search(root, target); }


void RedBlackTree::left_rotate(RBTreeNode *x) {
    auto y = x->right;
    x->right = y->left;
    if (RedBlackTree::nil != y->left) y->left->parent = x;
    y->parent = x->parent;
    if (RedBlackTree::nil == x->parent)
        root = y;
    else if (x->parent->left == x)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void RedBlackTree::right_rotate(RBTreeNode *y) {
    auto x = y->left;
    y->left = x->right;
    if (RedBlackTree::nil != x->right) x->right->parent = y;
    x->parent = y->parent;
    if (RedBlackTree::nil == y->parent)
        root = x;
    else if (y->parent->left == y)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}


void RedBlackTree::insert_fixup(RBTreeNode *z) {
    // 插入节点修正
    // 只要z的父节点是红色就进行操作
    while (!z->parent->color) {
        // z的父节点是其祖父节点的左子结点
        if (z->parent == z->parent->parent->left) {
            // y是z祖父节点的右孩子, 叔结点
            auto y = z->parent->parent->right;
            if (!y->color) {
                // y 红色, case1
                z->parent->color = true;
                y->color = true;
                z->parent->parent->color = false;
                // 更新当前节点z, 变为其祖父节点
                z = z->parent->parent;
                continue;
            } else if (z == z->parent->right) {
                z = z->parent;
                left_rotate(z);
            }
            z->parent->color = true;
            z->parent->parent->color = false;
            right_rotate(z->parent->parent);
        } else {
            auto y = z->parent->parent->left;
            if (!y->color) {
                z->parent->color = true;
                y->color = true;
                z->parent->parent->color = false;
                z = z->parent->parent;
                continue;
            } else if (z == z->parent->left) {
                z = z->parent;
                right_rotate(z);
            }
            z->parent->color = true;
            z->parent->parent->color = false;
            left_rotate(z->parent->parent);
        }
    }
    root->color = true;
}

void RedBlackTree::insert(int item) {
    auto y = RedBlackTree::nil, x = root;
    auto z = new RBTreeNode(item);
    while (x && x != RedBlackTree::nil) {
        y = x;
        if (item < x->val)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (RedBlackTree::nil == y)
        root = z;
    else if (item < y->val)
        y->left = z;
    else
        y->right = z;
    z->left = RedBlackTree::nil;
    z->right = RedBlackTree::nil;
    z->color = false;
    insert_fixup(z); // 只比BST多了这一步
}

void RedBlackTree::remove_1(RBTreeNode *node) {
    // case 1: 无子树
    if (!node->left && !node->right) {
        auto parent = node->parent;
        if (!parent) {
            delete root;
            root = nullptr;
            return;
        }
        if (node == parent->left) {
            delete parent->left;
            parent->left = nullptr;
            return;
        } else if (node == parent->right) {
            delete parent->right;
            parent->right = nullptr;
            return;
        }
    }
    // case 2: 只有左子树
    if (node->left && !node->right) {
        auto cur = node->left;
        auto val = cur->val;
        node->left = cur->left;
        node->right = cur->right;
        node->val = val;
        // 修正parent
        if (node->left) node->left->parent = node;
        if (node->right) node->right->parent = node;
        // 删除cur
        delete cur;
        cur = nullptr;
        return;
    }
    // case 3: 只有右子树
    if (!node->left && node->right) {
        auto cur = node->right;
        auto val = cur->val;
        node->left = cur->left;
        node->right = cur->right;
        node->val = val;
        // 修正parent
        if (node->left) node->left->parent = node;
        if (node->right) node->right->parent = node;
        // 删除cur
        delete cur;
        cur = nullptr;
        return;
    }
    // case 4: 左右子树都存在且不为空
    if (node->left && node->right) {
        auto pre = node->left;
        while (pre->right) pre = pre->right;
        node->val = pre->val;
        // 递归, 最后一定能删除到前面三种情况, 此时结束递归
        remove(pre);
    }
}

void RedBlackTree::transplant(RBTreeNode *u, RBTreeNode *v) {
    // 用以v为根的子树替换以u为根的子树
    if (u->parent == RedBlackTree::nil)
        // 处理u是BST根节点的情况
        root = v;
    else if (u == u->parent->left)
        // u是其父节点的左孩子
        u->parent->left = v;
    else
        // u是其父节点的右孩子
        u->parent->right = v;
    v->parent = u->parent;
}

void RedBlackTree::delete_fixup(RBTreeNode *x) {
    while (x != root && x->color) {
        if (x == x->parent->left) {
            auto w = x->parent->right;
            if (!w->color) {
                w->color = true;
                x->parent->color = false;
                left_rotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color && w->right->color) {
                w->color = false;
                x = x->parent;
                continue;
            } else if (w->right->color) {
                w->left->color = true;
                w->color = false;
                right_rotate(w);
                w = x->parent->right;
            }
            w->color = x->parent->color;
            x->parent->color = true;
            w->right->color = true;
            left_rotate(x->parent);
            x = root;
        } else {
            //
            auto w = x->parent->left;
            if (!w->color) {
                w->color = true;
                x->parent->color = false;
                left_rotate(x->parent);
                w = x->parent->left;
            }
            if (w->right->color && w->left->color) {
                w->color = false;
                x = x->parent;
                continue;
            } else if (w->left->color) {
                w->right->color = true;
                w->color = false;
                left_rotate(w);
                w = x->parent->left;
            }
            w->color = x->parent->color;
            x->parent->color = true;
            w->left->color = true;
            right_rotate(x->parent);
            x = root;
        }
    }
    x->color = true;
}

void RedBlackTree::remove(RBTreeNode *z) {
    RBTreeNode *x{};
    bool y_origin_color = z->color;
    if (z->left == RedBlackTree::nil) { // 没有左子树, 右子树可有可无
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == RedBlackTree::nil) { // 没有右子树, 有左子树
        x = z->left;
        transplant(z, z->left);
    } else { // 左右子树均存在且不为空
        // 查找z的后继
        /*因为z右子树非空, 所以后继一定是该子树的最小节点*/
        auto y = minimum(z->right);
        y_origin_color = y->color;
        x = y->right;
        if (y->parent == z)
            x->parent = y;
        else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    delete z;
    z = nullptr;
    // 待删除节点是黑节点才修正红黑树
    if (y_origin_color) delete_fixup(x);
}

void t1() {
    RedBlackTree tree;
    /* vector<int> nodes{2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20}; */
    vector<int> nodes{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};

    /* vector<int> nodes{3, 1, 2}; */
    for (int i : nodes) {
        tree.insert(i);
        /* tree.print_tree(); */
    }

    tree.print_tree();
    int node1{15};
    cout << "delete node: " << node1 << endl;
    tree.remove(tree.search(node1));
    /* tree.remove(tree.search(4)); */
    /* tree.remove(tree.search(3)); */
    tree.print_tree();
}

/*                15                */
/*         /             \         */
/*        6               18        */
/*     /     \         /     \     */
/*    3       9       17       20    */
/*   / \     / \                   */
/*  2   4   7   13                  */
/*                                 */
/*                                 */
/* delete node: 15 */
/*                                */
/*                17                */
/*         /             \         */
/*        6               18        */
/*     /     \               \     */
/*    3       9               20    */
/*   / \     / \                   */
/*  2   4   7   13                  */
/*                                 */
/*                                 */
/* 17 6 3 2 4 9 7 13 18 20  deleted.. */


void t0() {
    RedBlackTree tree;
    /* vector<int> nodes{1}; */
    /* vector<int> nodes{1, 2, 4, 5, 7, 8, 11, 14, 15}; */
    /* vector<int> nodes{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9}; */
    /* sort(nodes.begin(), nodes.end()); */
    vector<int> nodes{2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20};
    for (int i : nodes) {
        tree.insert(i);
        tree.print_tree(false, true);
    }

    /* tree.breadth_travel(); */
    cout << "RBT is: \n";
    /* tree.in_order(); */
    tree.print_tree(true, true);
}

int main(int argc, char const *argv[]) {
    /* t0(); */
    t1();
    return 0;
}
