#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<int>&);

// 希尔排序, 递减增量排序算法
void ShellSort(vector<int>& arr) {
    int n = arr.size(), group = 3;
    // group:组数(行数), inc:间隔(列数)
    // 当间隔减小到1时, 完成排序
    for (int inc = n / group; inc > 0; inc /= group)
        // 对列做插入排序
        for (int i = inc; i < n; ++i) {
            int tmp = arr[i], j = i;
            for (; j >= inc && arr[j - inc] > tmp; j -= inc)
                arr[j] = arr[j - inc];
            arr[j] = tmp;
        }
}

// 此函数用于打印输出数组
void printArray(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // vector<int> a{13, 14, 94, 33, 82, 25, 59, 94,
    //               65, 23, 45, 27, 73, 25, 39, 10};
    vector<int> a{6, 50, 21, 32, 31, 3, 43, 1, 3, 23};
    printArray(a);
    ShellSort(a);
    printArray(a);
    return 0;
}
