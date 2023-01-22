#include "bst.h"

BinarySearchTree::~BinarySearchTree() {
    function<void(BSTreeNode *)> f = [&](BSTreeNode *node) {
        if (!node) return;
        BSTreeNode *Left_Tree = node->left;
        BSTreeNode *Right_Tree = node->right;
        cout << node->val << " ";
        delete node;
        if (Left_Tree) f(Left_Tree);
        if (Right_Tree) f(Right_Tree);
    };
    f(root);
    cout << " deleted..\n";
}

void BinarySearchTree::build_from_array(vector<int> &items) {
    if (items.empty()) return;
    // 有序数组构建二叉搜索树
    sort(items.begin(), items.end());
    function<BSTreeNode *(int, int)> f = [&](int l, int r) {
        if (l > r) return (BSTreeNode *)nullptr;
        int mid = l + (r - l) / 2;
        return new BSTreeNode(items[mid], f(l, mid - 1), f(mid + 1, r));
    };
    // 迭代
    function<BSTreeNode *(void)> g = [&]() {
        if (items.empty()) return (BSTreeNode *)nullptr;

        BSTreeNode *tmp_root = new BSTreeNode();
        queue<BSTreeNode *> nodeQue;
        queue<int> leftQue, rightQue;
        nodeQue.push(tmp_root);
        leftQue.push(0);
        rightQue.push(items.size() - 1);

        while (!nodeQue.empty()) {
            auto cur = nodeQue.front();
            nodeQue.pop();
            int L = leftQue.front();
            leftQue.pop();
            int R = rightQue.front();
            rightQue.pop();

            int mid = L + (R - L) / 2;
            cur->val = items[mid]; // 赋值
            if (L < mid) {
                cur->left = new BSTreeNode();
                nodeQue.push(cur->left);
                leftQue.push(L);
                rightQue.push(mid - 1);
            }
            if (R > mid) {
                cur->right = new BSTreeNode();
                nodeQue.push(cur->right);
                leftQue.push(mid + 1);
                rightQue.push(R);
            }
        }
        return tmp_root;
    };
    /* root = f(0, items.size() - 1); */
    root = g();
}

void BinarySearchTree::breadth_travel() {
    if (!root) return;
    queue<BSTreeNode *> que;
    que.push(root);
    vector<int> ret;
    while (!que.empty()) {
        BSTreeNode *cur = que.front();
        que.pop();
        ret.emplace_back(cur->val);

        if (cur->left) que.push(cur->left);
        if (cur->right) que.push(cur->right);
    }
    cout << ret;
}

void BinarySearchTree::print_tree() {
    if (!root) return;
    queue<BSTreeNode *> q;
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
    queue<tuple<int, int, BSTreeNode *, string>> bq;
    bq.push({0, (n - 1) / 2, root, ""s});
    while (!bq.empty()) {
        int bqs = bq.size();
        for (auto i = 0; i < bqs; i++) {
            auto &[r, c, cur, slash] = bq.front();
            bq.pop();
            if (!cur) continue;
            ans[r][c] = to_string(cur->val);
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

void BinarySearchTree::in_order_recur() {
    vector<int> ret;
    function<void(BSTreeNode *)> f = [&](BSTreeNode *node) {
        if (!node) return;

        f(node->left);
        ret.emplace_back(node->val);
        f(node->right);
    };
    f(root);
    cout << ret;
}
void BinarySearchTree::in_order_iter() {
    if (!root) return;
    vector<int> ret;
    stack<BSTreeNode *> st;
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

BSTreeNode *BinarySearchTree::maximum(BSTreeNode *x) {
    while (x->right) x = x->right;
    return x;
}

BSTreeNode *BinarySearchTree::minimum(BSTreeNode *x) {
    while (x->left) x = x->left;
    return x;
}

int BinarySearchTree::MAX() { return maximum(root)->val; }
int BinarySearchTree::MIN() { return minimum(root)->val; }

BSTreeNode *BinarySearchTree::successor(BSTreeNode *x) {
    // 如果结点x的右子树非空, 则x后继结点就是其右子树的最左节点(minimum)
    if (x->right) return minimum(x->right);
    BSTreeNode *y = x->parent;
    // 如果x右子树为空且其后继结点存在, 则其后继就是x的有左孩子的最底层祖先
    while (y && x == y->right) x = y, y = y->parent;
    return y;
}

BSTreeNode *BinarySearchTree::predecessor(BSTreeNode *x) {
    if (x->left) return maximum(x->left);
    BSTreeNode *y = x->parent;
    while (y && x == y->left) x = y, y = y->parent;
    return y;
}

BSTreeNode *BinarySearchTree::_search(BSTreeNode *x, int target) {
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
    /* cout << x << endl; */
    return x;
}

BSTreeNode *BinarySearchTree::search(int target) {
    return _search(root, target);
}

void BinarySearchTree::insert(int item) {
    // 循环插入结点构建二叉搜索树, 但是容易退化成链表(不具备平衡性)
    BSTreeNode *y{}, *x = root, *z = new BSTreeNode(item);
    while (x) {
        y = x;
        if (item < x->val)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;
    if (!y)
        root = z;
    else if (item < y->val)
        y->left = z;
    else
        y->right = z;
}

void BinarySearchTree::remove_1(BSTreeNode *node) {
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

void BinarySearchTree::transplant(BSTreeNode *u, BSTreeNode *v) {
    // 用以v为根的子树替换以u为根的子树
    // 允许v空
    if (!u->parent)
        // 处理u是BST根节点的情况
        root = v;
    else if (u == u->parent->left)
        // u是其父节点的左孩子
        u->parent->left = v;
    else
        // u是其父节点的右孩子
        u->parent->right = v;
    // v非空, 更新父节点指针
    if (v) v->parent = u->parent;
}

void BinarySearchTree::remove(BSTreeNode *z) {
    if (!z->left) // 没有左子树, 右子树可有可无
        transplant(z, z->right);
    else if (!z->right) // 没有右子树, 有左子树
        transplant(z, z->left);
    else { // 左右子树均存在且不为空
        // 查找z的后继
        /*因为z右子树非空, 所以后继一定是该子树的最小节点*/
        auto y = minimum(z->right);
        if (y->parent != z) {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    delete z;
    z = nullptr;
}

void t1() {
    BinarySearchTree tree;
    vector<int> nodes{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    /* vector<int> nodes{2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20}; */

    /* for (int i : nodes) tree.insert(i); */
    for (int i : nodes) {
        tree.insert(i);
        tree.print_tree();
    }

    /* cout << "breadth_travel: \n"; */
    tree.print_tree();
    /* tree.breadth_travel(); */
    int node1{15};
    cout << "delete node: " << node1 << endl;
    tree.remove(tree.search(node1));
    /* tree.remove(tree.search(4)); */
    /* tree.remove(tree.search(3)); */
    tree.print_tree();
    /* tree.breadth_travel(); */
}

void t0() {
    BinarySearchTree tree;
    vector<int> nodes{15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    // 方法一
    // 严格递增序列, 这样构建的树一定是高度为n-1的一条链
    // 退化成链表, 所以需要有平衡性的限制(AVL, RBT)
    /* sort(nodes.begin(), nodes.end()); */
    for (int i : nodes) tree.insert(i);
    /* for (int i{1}; i < 8; ++i) tree.insert(i); */
    // 方法二: 数组构建二叉搜索树, 这种方法出来的一定是平衡的
    // 但是没有处理父节点指针
    /* vector<int> arr = {1, 2, 3, 4, 5, 6, 7}; */
    /* tree.build_from_array(nodes); */

    tree.breadth_travel();
    cout << "BST is :\n";
    tree.in_order_recur();

    cout << "MAX of the BST is " << tree.MAX() << endl;
    cout << "MIN of the BST is " << tree.MIN() << endl;

    auto n1 = tree.search(6);
    cout << "maximum in tree(6) is " << tree.maximum(n1)->val << endl;
    cout << "minimum in tree(6) is " << tree.minimum(n1)->val << endl;

    auto node = tree.search(13);
    int suc = tree.successor(node)->val;
    int pre = tree.predecessor(node)->val;
    cout << "suc of 13 is " << suc << endl;
    cout << "pre of 13 is " << pre << endl;
    /* [15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9]  */
    /* BST is : */
    /* [2, 3, 4, 6, 7, 9, 13, 15, 17, 18, 20]  */
    /* MAX of the BST is 20 */
    /* MIN of the BST is 2 */
    /* maximum in tree(6) is 13 */
    /* minimum in tree(6) is 2 */
    /* suc of 13 is 15 */
    /* pre of 13 is 9 */
    /* 15 6 3 2 4 7 13 9 18 17 20  deleted.. */
}

int main(int argc, char const *argv[]) {
    /* t0(); */
    t1();
    return 0;
}
