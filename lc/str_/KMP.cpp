#include <iostream>
#include <vector>
#include <string>


using namespace std;

void getNextArray(vector<int> & next,
                  const string s) {
    int j = 0;
    //j:前缀末尾&包括i之前的子串的最长公共前后缀的长度
    next[0] = 0;
    //i:后缀末尾
    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }// 不同, 回退, 相当于从后缀中找前缀
        if (s[i] == s[j])
            j++;//相等,记录
        next[i] = j;//更新
    }
}

int findstr(const string & s1,
            const string & s2) {
    if (s1.size() == 0)
        return 0;
    vector<int> next(s1.size());
    getNextArray(next, s1);
    // for (auto i: next)
    //     cout<<i<<" ";
    int j = 0;
    for (int i = 0; i < s2.size(); i++) {
        while (j > 0 && s2[i] != s1[j]) j = next[j - 1];
        if (s2[i] == s1[j]) j++;
        if (j == s1.size())
            return (i - j + 1);
    }
    return -1;
}

int main(int argc, char
         const * argv[]) {
    string s1 = "aabaaf";
    string s2 = "aabaabaaf";
    vector<int> next(s1.size());
    getNextArray(next, s1);
    for (auto &it : next)
        cout << it << ", ";
    putchar('\n');
    cout << findstr(s1, s2) << endl;

    return 0;
}