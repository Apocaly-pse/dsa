#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<int>&);

void RadixSort(vector<int>& arr) {
    int n = arr.size();
    int d{}, mx = *max_element(arr.begin(), arr.end());
    while (mx) mx /= 10, ++d;
    // 计数器
    vector<int> tmp(n), count(10);
    int i, j, k, radix = 1;
    for (i = 1; i <= d; i++) // 进行d次排序
    {
        fill(count.begin(), count.end(), 0); // 每次分配前清空计数器
        // 统计每个桶中的记录数(通过`余数`来区分放入哪个桶, 共有10个桶)
        for (int num : arr) count[(num / radix) % 10]++;
        /*
        2 3 0 3 0 0 2 0 0 0
        5 0 4 1 0 0 0 0 0 0
        7 0 0 2 1 0 0 0 0 0
        9 0 0 1 0 0 0 0 0 0
        9 0 0 0 1 0 0 0 0 0
        */
        // printArray(count);

        // 将tmp中的位置依次分配给每个桶(前缀和)
        for (j = 1; j < 10; j++) count[j] += count[j - 1];
        // printArray(count);
        /*
        2 5 5 8 8 8 10 10 10 10
        5 5 9 10 10 10 10 10 10 10
        7 7 7 9 10 10 10 10 10 10
        9 9 9 10 10 10 10 10 10 10
        9 9 9 9 10 10 10 10 10 10
        */
        // 将所有桶中记录依次收集到tmp中
        for (j = n - 1; j >= 0; j--)
            tmp[--count[(arr[j] / radix) % 10]] = arr[j];
        /*
        0 320 21 321 1 3 3 23 6 43436
        0 1 3 3 6 320 21 321 23 43436
        0 1 3 3 6 21 23 320 321 43436
        0 1 3 3 6 21 23 320 321 43436
        0 1 3 3 6 21 23 320 321 43436
        */
        // printArray(tmp);
        // 将临时数组的内容复制到arr中
        arr = tmp;
        // printArray(arr);
        radix = radix * 10;
    }
    // printArray(arr);
}

// 此函数用于打印输出数组
void printArray(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // vector<int> a{2, 5, 3, 0, 2, 3, 0, 3};
    vector<int> a{6, 0, 21, 320, 321, 3, 43436, 1, 3, 23};
    printArray(a);
    RadixSort(a);
    printArray(a);
    return 0;
}
