#include <iostream>
#include <vector>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v1) {
    for (T i : v1) os << i << " ";
    return os << endl;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>> v2) {
    for (auto i : v2) os << i;
    return os << endl;
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), SIZE = m * n;
        vector<int> ans(SIZE);
        int left{}, top{}, bot = m - 1, right = n - 1;
        int k{};
        while (k < SIZE) {
            for (int i = left; i <= right && k < SIZE; ++i)
                ans[k++] = matrix[top][i];
            top++;
            for (int i = top; i <= bot && k < SIZE; ++i)
                ans[k++] = matrix[i][right];
            right--;
            for (int i = right; i >= left && k < SIZE; --i)
                ans[k++] = matrix[bot][i];
            bot--;
            for (int i = bot; i >= top && k < SIZE; --i)
                ans[k++] = matrix[i][left];
            left++;
        }
        return ans;
    }
};


void t1() {
    Solution s;
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << mat;
    cout << s.spiralOrder(mat);
}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}