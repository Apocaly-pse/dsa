//
// Created by hep on 2023/3/22.
//
#include <vector>
#include <random>

using namespace std;


constexpr int MAX_LEVEL = 8; // 遵循Redis的zset数据结构的取法
constexpr double P_FACTOR = 0.25; // 每4个元素抽取一个元素分层(作为上一层的节点)

class Skiplist {
private:
    struct Node {
        int val;
        vector<Node *> forward;

        Node(int _val, int _max_level = MAX_LEVEL)
            : val(_val), forward(_max_level, nullptr) {}
    };

    Node *head; // 头结点
    int level;
    mt19937 gen{random_device{}()};        // 随机数生成器
    uniform_real_distribution<double> dis; // 随机数分布

public:
    Skiplist() : head(new Node(-1)), level(0), dis(0, 1) {}

    ~Skiplist() { delete head; }

    int randomLevel() { // 更新层
        int lv{1};
        while (dis(gen) < P_FACTOR && level < MAX_LEVEL) ++lv;
        return lv;
    }

    void helper(int target, vector<Node *> &pre) { // 辅助函数
        auto p = head;
        for (int i{level - 1}; i >= 0; --i) {
            while (p->forward[i] && p->forward[i]->val < target)
                p = p->forward[i];
            pre[i] = p;
        }
    }

    bool search(int target) {
        vector<Node *> pre(level);
        helper(target, pre);
        auto p = pre[0]->forward[0]; // 归为最后一层
        return p && p->val == target;
    }

    void add(int num) {
        vector<Node *> pre(level, head);
        helper(num, pre);

        int lv = randomLevel();
        level = max(level, lv);
        auto newNode = new Node(num, lv);

        for (int i{}; i < lv; ++i) {
            // 更新i层的状态, 将当前元素的 forward 指向新的节点
            newNode->forward[i] = pre[i]->forward[i];
            pre[i]->forward[i] = newNode;
            // if (rand() % 2) break; // 50% 概率不插入新节点
        }
    }

    bool erase(int num) {
        vector<Node *> pre(level);
        helper(num, pre);

        auto p = pre[0]->forward[0];
        if (!p || p->val != num) return false;

        // 更新第 i 层状态, forward 指向被删除节点的下一跳
        for (int i{}; i < level && pre[i]->forward[i] == p; ++i)
            pre[i]->forward[i] = p->forward[i];

        delete p;
        // 更新当前 level
        while (level > 1 && head->forward[level - 1] == nullptr) --level;
        return true;
    }
};

void t1() {
    //
    Skiplist sp;
    sp.add(1);
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}
