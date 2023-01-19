#include <iostream>
#include <vector>
using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}

ostream& operator<<(ostream& os, const vector<vector<int>>& v) {
    for (auto i : v) os << i;
    return os;
}

class Solution {
public:
    int BagMaxVAlue(vector<int>& value, vector<int>& weight, int maxWeight) {
        // 滚动数组优化
        int n = value.size();
        vector<int> dp(maxWeight + 1);
        for (int j{weight[0]}; j <= maxWeight; ++j)
            if (weight[0] <= j) dp[j] = value[0];
        cout << dp;
        for (int i{1}; i < n; ++i) {                    // object
            for (int j{maxWeight}; j >= weight[i]; --j) // bag-weight
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            cout << dp;
        }
        return dp[maxWeight];
    }
    int BagMaxVAlue1(vector<int>& value, vector<int>& weight, int maxWeight) {
        // 二维DP
        int n = value.size();
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1));
        for (int j{weight[0]}; j <= maxWeight; ++j)
            if (weight[0] <= j) dp[0][j] = value[0];
        cout << dp;
        // for换序也可
        for (int j{}; j <= maxWeight; ++j) // bag-weight
            for (int i{1}; i < n; ++i)     // object
                if (j < weight[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] =
                        max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        cout << dp;
        return dp[n - 1][maxWeight];
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> v{15, 20, 30}, w{1, 3, 4};
    int mw = 4;
    cout << s.BagMaxVAlue(v, w, mw) << endl;
    return 0;
}
