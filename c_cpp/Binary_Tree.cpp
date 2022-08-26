#include <iostream>
#include <vector>
#include <queue>
#include <stack>



using namespace std;

void printvec(vector<int> &v){
    for (int & it : v){
        // 有一些bug, 最后一个元素和中间某元素相同时候点号已经出现
        cout<<it<<(it != *(v.end()-1)?", ":". ");
    }
    cout<<endl;
}

// 二叉树节点的结构体实现
struct TreeNode {
    int val;
    TreeNode* lchild;
    TreeNode* rchild;

    TreeNode() : val(0), lchild(nullptr), rchild(nullptr)
    {  }
    TreeNode(int x) : val(x), lchild(nullptr), rchild(nullptr)
    {  }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), lchild(left), rchild(right)
    {  }
};


class BinaryTree
{
public:
    BinaryTree()
    : root(nullptr)
    {  }
    ~BinaryTree()
    {  }
    void add(int item);
    TreeNode* add1();
    TreeNode* add2(vector<int> &item);
    void breadth_travel(TreeNode* node);
    void pre_order(TreeNode* node);
    void pre_order1(TreeNode* node);
    void in_order(TreeNode* node);
    void in_order1(TreeNode* node);
    void in_order2(TreeNode* node);
    void post_order(TreeNode* node);
    void post_order1(TreeNode* node);
    void post_order2(TreeNode* node);
    TreeNode* get_root(BinaryTree &tree);
private:
    TreeNode* root;
};

TreeNode* BinaryTree::get_root(BinaryTree &tree)
{
    return tree.root;
}

// 递归版本生成二叉树(需要捕获用户输入)
TreeNode* BinaryTree::add1()
{
    int data;
    cin>>data;
    if (data < 0)
    {
        return nullptr;
    }
    TreeNode* node  = new TreeNode(data);
    node->val = data;
    node->lchild = BinaryTree::add1();
    node->rchild = BinaryTree::add1();
    return node;
}

// 递归生成二叉树: 直接外部遍历数组实现
TreeNode* BinaryTree::add2(vector<int> &item)
{
    if (item.empty() || item.front() == 0)
    {
        item.erase(item.begin());
        return nullptr;
    }
    TreeNode* node  = new TreeNode(item.front());
    node->val = item.front();
    item.erase(item.begin());
    node->lchild = BinaryTree::add2(item);
    node->rchild = BinaryTree::add2(item);
    return node;
}


void BinaryTree::add(int item)
{
    TreeNode* node = new TreeNode(item);
    // 这是错误的代码
    // 由于把新结点实例化在了栈区, 导致内存错误
    // TreeNode node(item);
    if (!root)
    {
        root = node;
        return ;
    }
    // 用队列模拟二叉树的层序遍历
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()) {
        TreeNode* cur_node = que.front();
        que.pop();

        if (!cur_node->lchild)
        {
            cur_node->lchild = node;
            return ;
        }
        else
            que.push(cur_node->lchild);

        // 接下来同样判断右边
        if (!cur_node->rchild)
        {
            cur_node->rchild = node;
            return ;
        }
        else
            que.push(cur_node->rchild);
        }
}

void BinaryTree::breadth_travel(TreeNode* node)
{
    queue<TreeNode*> que;
    que.push(node);
    vector<int> ret;
    if (!node)
        return ;
    while(!que.empty()) {
        TreeNode* cur_node = que.front();
        que.pop();
        // 也可以直接打印, 省去了定义数组的步骤
        // cout<< cur_node->val<<endl;
        ret.push_back(cur_node->val);

        if (cur_node->lchild)
            que.push(cur_node->lchild);
        if (cur_node->rchild)
            que.push(cur_node->rchild);
    }
    printvec(ret);
}

void recur_0(TreeNode* node, vector<int> &ret)
{
    // 递归终止条件
    if (!node)
        return ;
    ret.push_back(node->val);
    recur_0(node->lchild, ret);
    recur_0(node->rchild, ret);

}

void BinaryTree::pre_order(TreeNode* node)
{
    vector<int> ret;
    // if (!node)
    //     return ;
    // cout<<node->val<<", ";
    // pre_order(node->lchild);
    // pre_order(node->rchild);
    recur_0(node, ret);
    printvec(ret);
}

void BinaryTree::pre_order1(TreeNode* node)
{
    vector<int> ret;
    stack<TreeNode*> st;
    if (node)
        st.push(node);
    while(!st.empty()) {
        node = st.top();
        st.pop();
        ret.push_back(node->val);
        if (node->rchild)
            st.push(node->rchild);
        if (node->lchild)
            st.push(node->lchild);
    }
    
    printvec(ret);
}

void recur_1(TreeNode* node, vector<int> &ret)
{
    if (!node)
        return ;
    
    recur_1(node->lchild, ret);
    ret.push_back(node->val);
    recur_1(node->rchild, ret);
}

void BinaryTree::in_order(TreeNode* node)
{
    vector<int> ret;
    // if (!node)
    //     return ;
    // pre_order(node->lchild);
    // cout<<node->val<<", ";
    // pre_order(node->rchild);
    recur_1(node, ret);
    printvec(ret);
}

void BinaryTree::in_order1(TreeNode* node)
{
    vector<int> ret;
    stack<TreeNode*> st;
    auto cur = node;
    while(cur || !st.empty()) {
        if (cur)
        {
            st.push(cur);
            cur = cur->lchild;
        } else {
            cur = st.top();
            st.pop();
            ret.push_back(cur->val);
            cur = cur->rchild;
        }
    }
    printvec(ret);
}

void BinaryTree::in_order2(TreeNode* node)
{
    vector<int> ret;
    stack<TreeNode*> st;
    if (node)
    {
        st.push(node);
    }
    while(!st.empty()) {
        node = st.top();
        if (node)
        {
            st.pop();
            if (node->rchild)
            {
                st.push(node->rchild);
            }
            st.push(node);
            st.push(nullptr);
            if (node->lchild)
            {
                st.push(node->lchild);
            }
        } else {
            st.pop();
            node = st.top();
            st.pop();
            ret.push_back(node->val);
        }
    }
    printvec(ret);
}

void recur_2(TreeNode* node, vector<int> &ret)
{
    if (!node)
        return ;
    
    recur_2(node->lchild, ret);
    recur_2(node->rchild, ret);
    ret.push_back(node->val);

}

void BinaryTree::post_order(TreeNode* node)
{
    vector<int> ret;
    // if (!node)
    //     return ;
    // pre_order(node->lchild);
    // pre_order(node->rchild);
    // cout<<node->val<<", ";
    recur_2(node, ret);
    printvec(ret);
}

void BinaryTree::post_order1(TreeNode* node)
{
    stack<TreeNode*> st;
    vector<int> ret;
    if (node)
    {
        st.push(node);
    }
    while(!st.empty()) {
        node = st.top();
        st.pop();
        ret.push_back(node->val);
        if (node->lchild)
            st.push(node->lchild);
        if (node->rchild)
            st.push(node->rchild);
    }
    // 进行逆序操作: 或者用iterator的逆序算法
    vector<int> ret1;
    for (auto it=ret.rbegin();it!=ret.rend();it++)
        ret1.push_back(*it);

    printvec(ret1);
}

void BinaryTree::post_order2(TreeNode* node)
{
    stack<TreeNode*> st;
    vector<int> ret;
    while(!st.empty() || node) {
        while(node) {
            st.push(node);
            node = node->lchild?node->lchild:node->rchild;
        }
        node = st.top();
        st.pop();
        ret.push_back(node->val);
        node = !st.empty() && st.top()->lchild == node ? st.top()->rchild:nullptr;
    }

    printvec(ret);
}


int main(int argc, char const *argv[]) {
    BinaryTree tree;
    // 第一种生成方式, 层序生成(使用队列进行循环)
    // for (int i = 0; i < 9; ++i)
    // {
    //     tree.add(i);
    // }

    // 第二种生成方式, 递归生成(前序递归), 需要传入用户输入
    // TreeNode* node = tree.add1();

    // 第三种(同第二种), 递归生成, 直接读取数组即可
    vector<int> item = {1,2,0,4,0,0,3,0,5,0,0};
    // vector<int> item = {1,2,3,4,5,6,7,0,0,0,0,0,0,0,0};
    // vector<int> item = {1,2,4,0,0,5,0,0,3,6,0,0,7,0,0};
    // vector<int> item = {1,2,0,5,0,0,3,0,0};

    auto node = tree.add2(item);

    // 下面是遍历
    // 广度遍历
    // tree.breadth_travel(node);

    // 前序遍历(递归)
    tree.pre_order(node);
    // 前序遍历(循环)
    // tree.pre_order1(tree.get_root(tree));

    // 中序遍历(递归)
    tree.in_order(node);
    // 中序遍历(循环)
    // tree.in_order1(tree.get_root(tree));
    // tree.in_order2(tree.get_root(tree));

    // 后序遍历(递归)
    // tree.post_order(tree.get_root(tree));
    // 后序遍历(循环)
    // tree.post_order1(tree.get_root(tree));
    // tree.post_order2(tree.get_root(tree));
    return 0;
}