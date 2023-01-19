#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <cmath>
using namespace std;


class Solution {
public:
    double calc(int op, double lhs, double rhs) {
        switch (op) {
            case 0:
                return lhs + rhs;
            case 1:
                return lhs - rhs;
            case 2:
                return rhs - lhs;
            case 3:
                return lhs * rhs;
            case 4:
                return lhs / rhs;
            default:
                return rhs / lhs;
        }
    }
    bool dfs(vector<double>& nums) {
        //
        int n = nums.size();
        if (n == 1 && fabs(nums[0] - 24) < 1e-5) return true;
        // i,j:lhs,rhs
        for (int i{}; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // 存其他未被计算的索引
                vector<double> restmp{};
                for (int k{}; k < n; ++k) {
                    if (k == i || k == j) continue;
                    restmp.emplace_back(nums[k]);
                }
                // 开始计算
                for (int op{}; op < 6; ++op) {
                    restmp.emplace_back(calc(op, nums[i], nums[j]));
                    if (dfs(restmp)) return true;
                    restmp.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> dgs{};
        for (auto i : cards) dgs.emplace_back(i);
        return dfs(dgs);
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> v{4, 1, 8, 7};
    cout << s.judgePoint24(v) << endl;
    return 0;
}