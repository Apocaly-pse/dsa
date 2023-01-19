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
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        int SIZE{rows * cols};
        vector<vector<int>> ans(SIZE);
        ans[0] = {rStart, cStart};
        int i{1}, c{cStart}, r{rStart};
        whiel(i < SIZE) {}
    }

    vector<vector<int>> spiralMatrixIII1(int rows, int cols, int rStart,
                                         int cStart) {
        int SIZE{rows * cols};
        vector<vector<int>> ans(SIZE);
        ans[0] = {rStart, cStart};
        int r = rStart, c = cStart, i{1}, steps{}, direction{};
        vector<vector<int>> v = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // 1,1,2,2,3,3,4,4,...
        while (i < SIZE) {
            steps++;
            for (int p = 0; p < 2; p++) {
                for (int j = 0; j < steps; j++) {
                    r += v[direction][0];
                    c += v[direction][1];
                    if (r >= 0 && r < rows && c >= 0 && c < cols)
                        ans[i++] = {r, c};
                }
                direction = (direction + 1) % 4;
            }
        }
        return ans;
    }
};

void t1() {
    Solution s;
    // vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // cout << mat;
    // cout << s.spiralMatrixIII(5, 6, 1, 4);
    cout << s.spiralMatrixIII1(1, 4, 0, 0);
    /*
    0 0
    0 1
    0 2
    0 3
    */
}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}