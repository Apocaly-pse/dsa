#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> alertNames(vector<string> &keyName,
                              vector<string> &keyTime) {
        vector<string> ans{};
        unordered_map<string, vector<int>> dict{};
        for (int i{}; i < keyName.size(); ++i) {
            string s{keyTime[i]};
            int h = (s[0] - '0') * 10 + (s[1] - '0');
            int m = (s[3] - '0') * 10 + (s[4] - '0');
            dict[keyName[i]].emplace_back(h * 60 + m);
        }

        for (auto &[k, v] : dict) {
            int n = v.size();
            // cout << k << " " << n << endl;
            if (n < 3) continue;
            sort(v.begin(), v.end());
            int cnt{1};
            for (int i{}; i < n - 2; ++i) {
                // cout << s << endl;
                if (v[i + 2] - v[i] <= 60) {
                    ans.emplace_back(k);
                    break;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

void t1() {
    Solution s;
    // vector<string> keyName = {"daniel", "daniel", "daniel", "luis",
    //                           "luis",   "luis",   "luis"},
    //                keyTime = {"10:00", "10:40", "11:00", "09:00",
    //                           "11:00", "13:00", "15:00"};
    // vector<string> keyName = {"a", "a", "a", "a", "a", "a",
    //                           "b", "b", "b", "b", "b"},
    //                keyTime = {"23:27", "03:14", "12:57", "13:35",
    //                           "13:18", "21:58", "22:39", "10:49",
    //                           "19:37", "14:14", "10:41"};
    vector<string> keyName = {"a", "a", "a", "a", "b", "b", "b",
                              "b", "b", "b", "c", "c", "c", "c"},
                   keyTime = {"01:35", "08:43", "20:49", "00:01", "17:44",
                              "02:50", "18:48", "22:27", "14:12", "18:00",
                              "12:38", "20:40", "03:59", "22:24"};

    for (auto i : s.alertNames(keyName, keyTime)) cout << i << " ";
    cout << endl;
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}