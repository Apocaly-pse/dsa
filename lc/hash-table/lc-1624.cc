#include <iostream>
// #include <string>
#include <unordered_map>
// #include <vector>
using namespace std;


int maxLengthBetweenEqualCharacters(string s) {
    int ans = -1;
    unordered_map<char, int> dic;
    for (int i = 0; i < s.size(); i++) {
        // if (dic.contains(s[i])) {//c++20
        if (dic.find(s[i]) != dic.end()) {
            ans = max(ans, i - dic[s[i]] - 1);
        } else {
            dic[s[i]] = i;
        }
    }
    return ans;
}
int main(int argc, char const *argv[]) {
    string s = "aa";
    cout << maxLengthBetweenEqualCharacters(s) << endl;
    return 0;
}