#include <iostream>
#include <algorithm>

using namespace std;

const bool RED = true;
const bool BLACK = false;

// 红黑树节点
struct Node {
    int val;
    bool color;
    Node *left;
    Node *right;
    Node *parent;

    Node(int val)
        : val(val),
          color(RED),
          left(nullptr),
          right(nullptr),
          parent(nullptr) {}
};

// 红黑树
class RedBlackTree {
private:
    Node *root;

public:
    RedBlackTree() : root(nullptr) {}

    // 插入节点
    void insert(int val) {
        // 如果树为空，则新建一个黑色根节点
        if (root == nullptr) {
            root = new Node(val);
            root->color = BLACK;
            return;
        }

        // 查找要插入的位置
        Node *node = root;
        Node *parent = nullptr;
        while (node != nullptr) {
            parent = node;
            if (val < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }

        // 创建新节点
        Node *newNode = new Node(val);
        newNode->parent = parent;
        // 将新节点插入到树中
        if (val < parent->val) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        // 修复红黑树性质
        fixInsert(newNode);
    }

    // 修复插入节点后破坏的红黑树性质
    void fixInsert(Node *node) {
        // 如果当前节点是根节点，则直接将其染为黑色
        if (node->parent == nullptr) {
            node->color = BLACK;
            return;
        }

        // 如果父节点是黑色，则不需要修复
        if (node->parent->color == BLACK) { return; }

        // 父节点和叔父节点
        Node *parent = node->parent;
        Node *uncle = getUncle(node);

        // 叔父节点为红色
        if (uncle != nullptr && uncle->color == RED) {
            parent->color = BLACK;
            uncle->color = BLACK;
            Node *grandparent = getGrandParent(node);
            grandparent->color = RED;
            fixInsert(grandparent);
        } else {
            // 叔父节点为黑色或不存在
            Node *grandparent = getGrandParent(node);
            if (node == parent->right && parent == grandparent->left) {
                rotateLeft(parent);
                node = node->left;
            } else if (node == parent->left && parent == grandparent->right) {
                rotateRight(parent);
                node = node->right;
            }
            parent = node->parent;
            grandparent = getGrandParent(node);
            if (node == parent->left) {
                rotateRight(grandparent);
            } else {
                rotateLeft(grandparent);
            }
            parent->color = BLACK;
            grandparent->color = RED;
        }
    }

    // 左旋
    void rotateLeft(Node *node) {
        if (node->right == nullptr) { return; }

        Node *right = node->right;
        node->right = right->left;

        if (right->left != nullptr) { right->left->parent = node; }

        right->parent = node->parent;

        if (node->parent == nullptr) {
            // 如果当前节点是根节点，则将新的根节点设置为右节点
            root = right;
        } else {
            if (node == node->parent->left) {
                node->parent->left = right;
            } else {
                node->parent->right = right;
            }
        }

        right->left = node;
        node->parent = right;
    }

    // 右旋
    void rotateRight(Node *node) {
        if (node->left == nullptr) { return; }

        Node *left = node->left;
        node->left = left->right;

        if (left->right != nullptr) { left->right->parent = node; }

        left->parent = node->parent;

        if (node->parent == nullptr) {
            // 如果当前节点是根节点，则将新的根节点设置为左节点
            root = left;
        } else {
            if (node == node->parent->right) {
                node->parent->right = left;
            } else {
                node->parent->left = left;
            }
        }

        left->right = node;
        node->parent = left;
    }

    // 获取叔父节点
    Node *getUncle(Node *node) {
        Node *parent = node->parent;
        Node *grandparent = getGrandParent(node);
        if (grandparent == nullptr) { return nullptr; }

        if (parent == grandparent->left) { return grandparent->right; }

        return grandparent->left;
    }

    // 获取祖父节点
    Node *getGrandParent(Node *node) {
        if (node != nullptr && node->parent != nullptr) {
            return node->parent->parent;
        }
        return nullptr;
    }
};
void t1(){}
int main(int argc, char const *argv[])
{
    t1();
    return 0;
}