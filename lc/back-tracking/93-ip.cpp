#include <functional>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans{};

        auto isValid = [&](int start, int end) {
            if (start > end) return false;
            if (s[start] == '0' && start != end) return false;
            int num{};
            for (int i{start}; i <= end; ++i) {
                if (s[i] > '9' || s[i] < '0') return false;
                num = num * 10 + (s[i] - '0');
                if (num > 255) return false;
            }
            return true;
        };

        int pointNum{};
        function<void(int)> f = [&](int start) {
            if (pointNum == 3) {
                if (isValid(start, s.size() - 1)) ans.emplace_back(s);
                return;
            }
            for (int i{start}; i < s.size(); ++i) {
                if (isValid(start, i)) {
                    s.insert(s.begin() + i + 1, '.');
                    ++pointNum;
                    f(i + 2);
                    --pointNum;
                    s.erase(s.begin() + i + 1);
                } else
                    break;
            }
        };
        if (s.size() > 12) return ans;
        f(0);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    string s = "25525511135";
    Solution s1;
    auto ans = s1.restoreIpAddresses(s);
    for (auto c : ans) cout << c << endl;
    return 0;
}