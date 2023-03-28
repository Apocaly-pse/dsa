#include <iostream>
#include <vector>
#include <functional>
using namespace std;


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target, -1); // dp存记忆化结果
        cout << dp.size() << endl;
        dp[0] = 1;
        function<int(int)> f = [&](int t) {
            if (t < 0) return 0;
            // 遍历过了
            if (dp[t] != -1) return dp[t];
            int res{};
            for (int num : nums) {
                cout << t << " " << num << endl;
                res += f(t - num);
                // t += num;
            }
            return dp[t] = res;
        };
        return f(target);
    }
};

void t1() {
    vector<int> v{1, 2, 3};
    int target = 4;
    Solution s;
    cout << s.combinationSum4(v, target) << endl;
}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}
