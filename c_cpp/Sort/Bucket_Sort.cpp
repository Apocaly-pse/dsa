#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<int>&);

void InsertionSort(vector<int>& A) {
    int n = A.size();
    // 待插入的元素
    for (int i = 1; i < n; ++i) {
        int tmp = A[i], j = i - 1;
        for (; j >= 0 && A[j] > tmp; --j) A[j + 1] = A[j];
        A[j + 1] = tmp;
    }
}

void BucketSort(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> B(10);
    for (int num : arr) B[num / 10].emplace_back(num);
    // printArray(B[0]);
    int i{};
    for (vector<int>& A : B) {
        InsertionSort(A);
        // printArray(A);
        for (int a : A) arr[i++] = a;
    }
}

// 此函数用于打印输出数组
void printArray(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // vector<int> a{2, 5, 3, 0, 2, 3, 0, 3};
    vector<int> a{6, 50, 21, 32, 31, 3, 43, 1, 3, 23};
    printArray(a);
    BucketSort(a);
    printArray(a);
    return 0;
}
