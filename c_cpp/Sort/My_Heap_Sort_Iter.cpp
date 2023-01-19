#include <iostream>
#include <vector>
using namespace std;

ostream &operator<<(ostream &os, vector<int> &v) {
    for (auto i : v) { os << i << " "; }
    return os << endl;
}

void Max_Heapify(vector<int> &arr, int len, int i) {
    for (int largest{}, tmp = arr[i]; i * 2 < len; i = largest) {
        largest = i * 2;
        if (largest + 1 < len && arr[largest + 1] > arr[largest]) largest++;
        if (arr[i] < arr[largest])
            swap(arr[largest], arr[i]);
        else
            break;
    }
}

void Max_Heapify_iter1(vector<int> &arr, int len, int i) {
    bool done = false;
    while (!done) {
        int largest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < len && arr[l] > arr[largest]) largest = l;
        if (r < len && arr[r] > arr[largest]) largest = r;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            i = largest;
        } else
            done = true;
    }
}

void Max_Heapify_recur(vector<int> &arr, int len, int i) {
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

void Heap_Sort(vector<int> &arr) {
    int n = arr.size();
    for (int i = (n - 1) / 2; i >= 0; --i) Max_Heapify(arr, n, i);
    // cout << arr;
    for (int i = n - 1; i >= 1; --i) {
        swap(arr[0], arr[i]);
        // Max_Heapify(arr, --n, 0);
        Max_Heapify(arr, i, 0);
    }
}

void t1() {
    vector<int> arr{16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    // vector<int> arr{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    // vector<int> arr{3, 3, 4};
    cout << arr;
    Heap_Sort(arr);
    cout << arr;
}
int main(int argc, char *argv[]) {
    t1();
    return 0;
}
