#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> arr);
void BubbleSort(vector<int>& arr) {
    int len = arr.size();
    for (int i = 0; i < len; i++) {
        int flag = 0;
        // 每一轮都保证最大值被放在最后,
        // 所以不需要关心最大值, 往前计算即可
        for (int j = 0; j < len - i - 1; j++) {
            // 前一个比后一个大就交换
            if (arr[j] > arr[j + 1]) {
                flag = 1;
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
        /* printArray(arr); */
        // 若此轮没进行过交换,说明已排好序
        if (flag == 0) break;
    }
}

// 此函数用于打印输出数组
void printArray(vector<int> arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> a{9, 1, 990, 12, 23, 2};
    printArray(a);
    BubbleSort(a);
    printArray(a);
    return 0;
}
