#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        unordered_map<int, int> cnt; // 记录下标首次出现位置
        int n = array.size(), beg{}, end{}, presum[n + 1];
        presum[0] = 0;
        for (int i{}; i < n; ++i) {
            presum[i + 1] =
                presum[i] + 1 - 2 * (array[i][0] > '9' || array[i][0] < '0');
            cout << presum[i + 1] << " ";
        }
        for (int i{}; i <= n; ++i) {
            auto it = cnt.find(presum[i]);
            if (it == cnt.end())
                cnt[presum[i]] = i;
            else if (i - it->second > end - beg)
                beg = it->second, end = i;
        }
        return {array.begin() + beg, array.begin() + end};
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<string> aa = {"A", "1", "B", "C", "D", "2", "3", "4", "E", "5",
                         "F", "G", "6", "7", "H", "I", "J", "K", "L", "M"};
    vector<string> bb = {"a", "a"};
    auto ans = s.findLongestSubarray(aa);
    return 0;
}