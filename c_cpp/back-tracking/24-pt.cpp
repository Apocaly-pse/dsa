#include <iostream>
#include <vector>
#include <functional>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <numeric>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <string>
#include <list>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> digits;
        for (int num : nums) digits.emplace_back(num);
        return bt(digits);
    }

    bool bt(vector<double>& digits) {
        int n = digits.size();
        if (n == 1) { return abs(digits[0] - 24) < 0.001; }

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<double> restmp;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;
                    restmp.emplace_back(digits[k]);
                }

                for (int op = 0; op < 6; ++op) {
                    restmp.emplace_back(calc(op, digits[i], digits[j]));
                    if (bt(restmp)) return true;
                    restmp.pop_back();
                }
            }
        }
        return false;
    }

    double calc(int op, double a, double b) {
        switch (op) {
            case 0:
                return a + b;
            case 1:
                return a - b;
            case 2:
                return b - a;
            case 3:
                return a * b;
            case 4:
                return a / b;
            default:
                return b / a;
        }
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> v1{1, 2, 1, 2};
    cout << s.judgePoint24(v1) << endl;
    return 0;
}