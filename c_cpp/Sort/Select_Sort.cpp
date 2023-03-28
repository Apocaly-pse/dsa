#include <iostream>
#include <vector>

using namespace std;


void SelectSort1(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min1 = i;
        // unordered
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[min1]) min1 = j;
        // this location is not the min
        if (min1 != i) {
            /* swap(arr[min1], arr[i]); */
            int tmp = arr[min1];
            arr[min1] = arr[i];
            arr[i] = tmp;
        }
    }
}

void SelectSort2(vector<int> &arr) {
    int n = arr.size(), i{};
    while (i < n) {
        int min1 = i;
        for (int j = i + 1; j < n; ++j)
            if (arr[min1] > arr[j]) min1 = j;
        if (min1 != i) swap(arr[min1], arr[i]);
        i++;
    }
}

void SelectSort(vector<int> &arr) {
    int n = arr.size();
    for (int i{}; i < n - 1; ++i) {
        int min1 = i, j{i + 1};
        for (; j < n; ++j)
            if (arr[j] < arr[min1]) min1 = j;
        if (min1 != i) swap(arr[min1], arr[i]);
    }
}

// 此函数用于打印输出数组
void printArray(vector<int> arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    // 定义数组
    vector<int> a = {19, 97, 9, 17, 1, 8};
    // 输出原始数组
    printArray(a);
    // 排序
    SelectSort(a);
    // 输出排序后的数组
    printArray(a);
    return 0;
}

