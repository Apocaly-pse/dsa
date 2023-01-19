#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<int>&);

void ConutingSort(vector<int>& arr) {
    int n = arr.size(), k = *max_element(arr.begin(), arr.end());
    vector<int> C(k + 1), B(n);
    // C[]用于计数
    for (int num : arr) C[num]++;
    // printArray(C); // 2 0 2 3 0 1
    // 前缀和
    for (int i{}; i < k; ++i) C[i + 1] += C[i];
    // printArray(C); // 2 2 4 7 7 8
    for (int num : arr) B[--C[num]] = num;
    arr = B;
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
    ConutingSort(a);
    printArray(a);
    return 0;
}
