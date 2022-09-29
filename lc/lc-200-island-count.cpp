#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int numIslands(vector<vector<char>>& grid) {
        return 0;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<vector<char>> grid1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    int ans = s.numIslands(grid1);
    cout << ans << endl;
    return 0;
}
