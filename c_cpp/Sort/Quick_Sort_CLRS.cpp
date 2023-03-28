#include <iostream>
#include <stack>
#include <ctime>
#include <tuple>
#include <vector>
#include <chrono>
#include <random>

using namespace std::chrono;

using namespace std;

void printArray(const vector<int> &A) {
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

/*
快速排序基本思想
1. 选定pivot中心轴
2. 将大于pivot的数字放在pivot右边
3. 将小于pivot的数字放在pivot左边
4. 分别对左右子序列重复上述三步操作
具体思路:
首先默认以最右边的数为pivot, 进行遍历比较,
需要左右两个游标, 分别对左右两个子序列进行值比较
*/

// 这部分相当于是插入排序
int Partition1(vector<int> &arr, int l, int r) {
    /*i: the number of left side of x */
    int mid = l + (r - l) / 2; // 选pivot
    int pivot = arr[mid], i = l - 1;
    for (int j = l; j <= r; ++j) {
        if (j == mid) continue;
        if (arr[j] <= pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[++i], arr[mid]);
    return i; // 返回pivot插入的位置
}

int Partition2(vector<int> &arr, int l, int r) {
    /*i: the number of left side of x */
    int x = arr[r], i = l - 1;
    for (int j = l; j < r; ++j)
        if (arr[j] <= x) swap(arr[++i], arr[j]);
    swap(arr[++i], arr[r]);
    // printArray(arr);
    return i; // 返回pivot插入的位置
}

int Partition(vector<int> &arr, int l, int r) {
    /*i: the number of left side of x */
    int x = arr[l], i = l;
    for (int j = l + 1; j <= r; ++j)
        if (arr[j] <= x) swap(arr[++i], arr[j]);
    swap(arr[i], arr[l]);
    // printArray(arr);
    return i; // 返回pivot插入的位置
}

// 递归实现快速排序算法
void QuickSort1(vector<int> &arr, int l, int r) {
    if (l >= r) return;
    int m = Partition1(arr, l, r);
    QuickSort1(arr, l, m - 1);
    QuickSort1(arr, m + 1, r);
}


/* arr --> Array to be sorted,
    l  --> Starting index,
    r  --> Ending index */
void QuickSort2(vector<int> &arr) {
    int l{}, r = arr.size() - 1;
    int stack[r - l + 1];
    // 栈顶指针(索引)
    int top = -1;

    stack[++top] = l;
    stack[++top] = r;
    // 栈空, 说明每一个子区间都被处理完了
    while (top >= 0) {
        r = stack[top--];
        l = stack[top--];

        int p = Partition(arr, l, r);
        // pivot 左边元素入栈
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        // pivot 右边元素入栈
        if (p + 1 < r) {
            stack[++top] = p + 1;
            stack[++top] = r;
        }
    }
}

void QuickSort(vector<int> &arr) {
    int l{}, r = arr.size() - 1;
    // with STL: stack
    stack<pair<int, int>> st;
    st.push({l, r});
    while (!st.empty()) {
        tie(l, r) = st.top();
        st.pop();
        int p = Partition(arr, l, r);
        if (p - 1 > l) st.push({l, p - 1});
        if (p + 1 < r) st.push({p + 1, r});
    }
}

vector<int> gen_data(size_t N) {
    vector<int> data(N);
    int min1{}, max1{10000};

    // random_device seed;
    ranlux48 engine(1);
    uniform_int_distribution<> distrib(min1, max1);
    for (int i{}; i < N; ++i) {
        int ran1 = distrib(engine);
        data[i] = ran1;
    }
    // printArray(data);
    return data;
}

void t1() {
    auto start = system_clock::now();
    // 定义数组
    // vector<int> arr = {19, 97, 9, 17, 1, 8};
    auto arr = gen_data(10000);
    // 输出原始数组
    // printArray(arr);
    // 进行快速排序
    QuickSort(arr);
    cout << "sorting...\n";
    /* QuickSort1(arr, 0, arr.size() - 1); */
    // 输出排序后的数组
    /* printArray(arr); */
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time spent: "
         << double(duration.count()) * microseconds::period::num << "ms"
         << endl;
}

int main(int argc, char const *argv[]) {

    t1();
    return 0;
}
