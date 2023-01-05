#include <iostream>
#include <unordered_map>
#include <typeinfo>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> cnt;
        for (auto c : s) {
            cout << c << "  " << typeid(c).name() << endl;
            ++cnt[c - 'a'];
        }
        int tmp{cnt[s[0]]};
        /* for (auto [k, v] : cnt) { */
        for (auto itm : cnt) {
            cout << itm.first << " " << itm.second << endl;
            /* if (itm.second != tmp) return false; */
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    cout << s.areOccurrencesEqual("abcabc") << endl;
    return 0;
}
