#include <iostream>
#include <vector>
using namespace std;

ostream &operator<<(ostream &os, vector<int> &v) {
    for (auto i : v) { os << i << " "; }
    return os << endl;
}

void Max_Heapify(vector<int> &arr, int len, int i) {
    // array index start with 0
    int l = 2 * i + 1, r = 2 * i + 2;
    int largest = i;
    if (l < len and arr[l] > arr[largest]) largest = l;
    if (r < len and arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        Max_Heapify(arr, len, largest);
    }
}

void Build_Max_Heap(vector<int> &arr) {
    int n = arr.size();
    for (int i = (n - 1) / 2; i >= 0; --i) Max_Heapify(arr, n, i);
}

void Heap_Sort(vector<int> &arr) {
    Build_Max_Heap(arr);
    // cout << arr;
    int n = arr.size();
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        Max_Heapify(arr, i, 0);
    }
}

void t1() {
    // vector<int> arr{16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    vector<int> arr{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    // vector<int> arr{3, 3, 4};
    cout << arr;
    Heap_Sort(arr);
    cout << arr;
}
int main(int argc, char *argv[]) {
    t1();
    return 0;
}
