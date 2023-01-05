#include <iostream>
#include <ctime>

using namespace std;

/*
快速排序基本思想
1. 选定pivot中心轴
2. 将大于pivot的数字放在pivot右边
3. 将小于pivot的数字放在pivot左边
4. 分别对左右子序列重复上述三步操作
具体思路:
首先默认以*左边*第一个数为pivot, 进行遍历比较,
需要左右两个游标, 分别对左右两个子序列进行值比较

*/

// 递归实现快速排序算法
void QuickSort(int arr[], int L, int R) {
    // 递归结束
    if (L >= R) return;

    int left = L, right = R;
    int pivot = arr[left];
    // 遍历数组
    while (left < right) {
        while (left < right && arr[right] >= pivot) right--;
        if (left < right) arr[left] = arr[right];
        while (left < right && arr[left] <= pivot) left++;

        if (left < right)
            arr[right] = arr[left];
        else
            arr[left] = pivot;
    }
    // 对左子序列进行快排
    QuickSort(arr, L, right - 1);
    // 对右子序列进行快排
    QuickSort(arr, right + 1, R);
}

// 此函数用于打印输出数组
void printArray(int arr[], int len) {
    for (int i = 0; i < len; ++i) { cout << arr[i] << " "; }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    clock_t t0, t1;
    t0 = clock();
    // 定义数组
    int a[6] = {19, 97, 9, 17, 1, 8};
    // 定义数组长度
    int len = sizeof(a) / sizeof(int);
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
