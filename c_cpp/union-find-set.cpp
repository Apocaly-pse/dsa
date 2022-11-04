#include <iostream>
#include <vector>
const int MAXN = 10000;

using namespace std;

// 初始化并查集数组
int fa[MAXN];
inline void init(int n) {
    for (int i = 1; i <= n; ++i) fa[i] = i;
}

// 查找
int find(int x) {
    if (fa[x] == x)
        return x;
    else
        return find(fa[x]);
}

// 合并
void merge(int i, int j) { fa[find(i)] = find(j); }

int main(int argc, char const *argv[]) {
    init(10);
    return 0;
}
