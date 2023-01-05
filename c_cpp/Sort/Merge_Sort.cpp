#include <climits>
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

/*
归并排序基本思想
具体思路:
*/

void printArray(int arr[], int len);


// merge the sorted list
void Merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q;
    int arr1[n1 + 1], arr2[n2 + 1];
    for (int i = 0; i < n1; ++i) arr1[i] = arr[p + i];
    for (int j = 0; j < n2; ++j) arr2[j] = arr[q + j + 1];
    arr1[n1] = 10000;
    arr2[n2] = 10000;
    int i = 0, j = i;
    for (int k = p; k <= r; ++k) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            ++i;
        } else {
            arr[k] = arr2[j];
            ++j;
        }
    }
}

void merge(int arr[], int L, int M, int R) { // 归并左右两侧数组
    // int *a = (int *)malloc((R - L + 1) * sizeof(int)); // 新建一个空数组
    int a[R - L + 1];
    int i = 0;
    int p1 = L;
    int p2 = M + 1;
    while (p1 <= M && p2 <= R) { // 左右依次比较将小数放入新数组中
        a[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
    }
    // 如果左侧没全部放入则依次全部放入
    while (p1 <= M) a[i++] = arr[p1++];
    // 如果右侧没全部放入则依次全部放入
    while (p2 <= R) a[i++] = arr[p2++];
    // 将排序好后的数组复制到原数组
    for (i = 0; i < R - L + 1; i++) arr[L + i] = a[i];
}

void MergeSort(int arr[], int L, int R) {
    if (L < R) {
        int M = L + (R - L) / 2;
        MergeSort(arr, L, M);
        MergeSort(arr, M + 1, R);
        // Merge(arr, L, M, R);
        merge(arr, L, M, R);
    }
}

// 此函数用于打印输出数组
void printArray(int arr[], int len) {
    for (int i = 0; i < len; ++i) { cout << arr[i] << " "; }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    clock_t t0, t1;
    t0 = clock();
    const int SIZE = 8;
    int a[SIZE] = {19, 2, 5, 97, 9, 17, 1, 8};

    printArray(a, SIZE);
    // 进行排序
    MergeSort(a, 0, SIZE - 1);
    // 输出排序后的数组
    printArray(a, SIZE);
    t1 = clock();
    cout << "Time: " << double(t1 - t0) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
