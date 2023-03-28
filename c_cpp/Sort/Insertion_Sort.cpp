#include <iostream>
#include <vector>

using namespace std;

// 此函数用于打印输出数组
void printArray(vector<int> arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void InsertionSort1(vector<int> &arr) {
    int len = arr.size();
    // 首先从第二个元素开始,遍历数组
    for (int j = 1; j < len; j++) {
        int key = arr[j]; // 待插入的元素, 用变量key保存
        // 首元素不动, 从第二个元素开始依次遍历比较
        int i = j - 1;
        //
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i -= 1; // 每一步比较i均进行左移, 直到找到合适位置
        }
        arr[i + 1] = key;
    }
}

void InsertionSort2(vector<int> &arr) {
    int n = arr.size();
    // 左边为已排序区,右边是待排序区
    for (int j = 1; j < n; ++j) {
        int i = j - 1, tmp = arr[j]; // tmp:待插入元素
        // 往后挪元素,腾出来位置留给tmp
        // 从后往前遍历,寻找插入位置
        for (; i >= 0 && arr[i] > tmp; --i) arr[i + 1] = arr[i];
        // 最后插入tmp
        arr[i + 1] = tmp;
    }
}

void InsertionSort3(vector<int> &arr) {
    int n = arr.size();
    // 遍历待插入元素
    for (int i = 1; i < n; ++i) {
        int tmp = arr[i], j{};
        // 从前往后遍历, 寻找插入位置(遍历已排好序的元素)
        while (j < i && arr[j] <= tmp) ++j;
        if (j == i) continue;
        int idx = j;
        // for (; i > idx; --i) arr[i] = arr[i - 1];
        for (int k{}; k <= i - idx; ++k) arr[i - k] = arr[i - 1 - k];
        arr[idx] = tmp;
        printArray(arr);
    }
}

void InsertionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i{1}; i < n; ++i) {
        int key = arr[i], j = i - 1;
        /* while (j >= 0 && arr[j] > key) arr[j + 1] = arr[j], --j; */
        for (; j >= 0 && arr[j] > key; --j) arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

int main(int argc, char const *argv[]) {
    // 定义数组
    vector<int> a = {19, 97, 9, 17, 1, 8};

    // 输出原始数组
    printArray(a);
    // 排序
    InsertionSort(a);
    // 输出排序后的数组
    printArray(a);
    return 0;
}
