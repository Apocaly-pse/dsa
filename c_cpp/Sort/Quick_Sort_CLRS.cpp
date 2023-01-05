#include <iostream>
#include <stack>
#include <ctime>
#include <tuple>

using namespace std;

void printArray(int A[], int len) {
    for (int i = 0; i < len; ++i) { cout << A[i] << " "; }
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

// 子数组的处理
int Partition(int A[], int l, int r) {
    /*i: the number of left side of x */
    int mid = l + (r - l) / 2;
    int pivot = A[mid], i = l - 1;
    for (int j = l; j <= r; ++j) {
        if (j == mid) continue;
        if (A[j] <= pivot) swap(A[++i], A[j]);
    }
    swap(A[i + 1], A[mid]);
    return i + 1;
}

// 递归实现快速排序算法
void QuickSort1(int A[], int l, int r) {
    if (l >= r) return;
    int m = Partition(A, l, r);
    QuickSort1(A, l, m - 1);
    QuickSort1(A, m + 1, r);
}


/* A[] --> Array to be sorted,
    l  --> Starting index,
    r  --> Ending index */
void QuickSort2(int arr[], int l, int r) {
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

void QuickSort(int A[], int l, int r) {
    // with STL: stack
    stack<pair<int, int>> st;
    st.push(make_pair(l, r));
    while (!st.empty()) {
        tie(l, r) = st.top();
        st.pop();
        int p = Partition(A, l, r);
        if (p - 1 > l) st.push(make_pair(l, p - 1));
        if (p + 1 < r) st.push(make_pair(p + 1, r));
    }
}


int main(int argc, char const *argv[]) {
    clock_t t0, t1;
    t0 = clock();
    const int len = 6;
    // 定义数组
    int a[len] = {19, 97, 9, 17, 1, 8};
    // 输出原始数组
    printArray(a, len);
    // 进行快速排序
    QuickSort(a, 0, len - 1);
    // 输出排序后的数组
    printArray(a, len);
    t1 = clock();
    cout << "Time: " << double(t1 - t0) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
