#include <iostream>
#include <vector>

using namespace std;

// 并查集
class UnionFind {
private:
    vector<int> parents;

public:
    UnionFind(int size) : parents(size) {
        // 初始化，每个元素都指向自己
        for (int i = 0; i < size; i++) { parents[i] = i; }
    }

    // 合并两个元素所在的集合
    void Union(int A, int B) {
        int rootA = Find(A);
        int rootB = Find(B);
        if (rootA != rootB) { parents[rootA] = rootB; }
    }

    // 查找元素所在的集合
    int Find(int A) {
        if (parents[A] != A) {
            // 路径压缩
            parents[A] = Find(parents[A]);
        }
        return parents[A];
    }
};
/*上面的代码中，我们演示了如何使用并查集来维护一组不相交的集合。首先，我们创建了一个大小为
10
的并查集，每个元素都指向自己，表示每个元素都是一个单独的集合。然后，我们演示了如何将两个集合合并为一个集合，并且如何查找一个元素所在的集合。在这个例子中，我们将
0，1，2，3，4，5，6，7，8 合并到一个集合中，9 在一个单独的集合中。

需要注意的是，这个实现方法只是简单的演示了并查集的一些操作，在实际应用中，它可能需要更多的优化。例如，我们可以使用路径压缩的方法来加快查找的速度，或者使用更复杂的方法来维护不相交集合的性质


继续

抱歉，您希望我继续讲什么呢？我已经为您提供了关于并查集的实现方法的说明，如果您对它还有疑问，请随时告诉我。如果您有其他问题，我也会尽力回答。



*/
int main() {
    UnionFind uf(10);
    uf.Union(0, 1);
    uf.Union(1, 2);
    uf.Union(3, 4);
    uf.Union(4, 5);
    uf.Union(5, 6);
    uf.Union(6, 7);
    uf.Union(7, 8);
    uf.Union(0, 3);

    cout << "0 和 1 是否在同一个集合中："
         << (uf.Find(0) == uf.Find(1) ? "是" : "否") << endl;
    cout << "3 和 8 是否在同一个集合中："
         << (uf.Find(3) == uf.Find(8) ? "是" : "否") << endl;
    cout << "2 和 7 是否在同一个集合中：" << (uf.Find(2) == uf.Find(7) ? "是" : "否") << endl;
}
