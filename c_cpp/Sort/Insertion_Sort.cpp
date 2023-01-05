#include <iostream>
#include <vector>

using namespace std;


void InsertionSort(vector<int> &arr) {
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
    InsertionSort(a);
    // 输出排序后的数组
    printArray(a);
    return 0;
}
