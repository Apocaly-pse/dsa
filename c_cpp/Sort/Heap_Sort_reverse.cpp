#include <iostream>
#include <vector>
using namespace std;

ostream &operator<<(ostream &os, vector<int> &v) {
    for (auto i : v) { os << i << " "; }
    return os << endl;
}

void Min_Heapify(vector<int> &arr, int len, int i) {
    // array index start with 0
    int l = 2 * i + 1, r = 2 * i + 2;
    int smallest = i;
    if (l < len and arr[l] < arr[smallest]) smallest = l;
    if (r < len and arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        Min_Heapify(arr, len, smallest);
    }
}

void Build_Min_Heap(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2; i >= 0; --i) Min_Heapify(arr, n, i);
}

void Heap_Sort(vector<int> &arr) {
    Build_Min_Heap(arr);
    int n = arr.size();
    for (int i = n - 1; i >= 1; --i) {
        swap(arr[0], arr[i]);
        Min_Heapify(arr, i, 0);
    }
}

void t1() {
    // vector<int> arr{16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    vector<int> arr{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    cout << arr;
    Heap_Sort(arr);
    cout << arr;
}
int main(int argc, char *argv[]) {
    t1();
    return 0;
}
