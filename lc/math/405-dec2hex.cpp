#include <iostream>
#include <climits>
#include <cmath>
#include <unistd.h>
using namespace std;
string dec2hex1(long x) {
    string ans{};
    if (x < 0) x = (long)x + 4294967296l;
    // x += (1l << 32);
    while (x) {
        auto res = x % 16;
        res += res > 9 ? 87 : 48;
        ans = static_cast<char>(res) + ans, x /= 16;
    }
    return ans.empty() ? "0" : ans;
}

string dec2hex(int x) {
    string ans{};
    for (int i = 7; i >= 0; i--) {
        int val = (x >> (4 * i)) & 0xf;
        if (ans.size() > 0 || val > 0)
            val += val > 9 ? 87 : 48, ans += static_cast<char>(val);
    }
    return ans.empty() ? "0" : ans;
}

int main(int argc, char const* argv[]) {
    cout << dec2hex(26) << endl;
    // cout << dec2hex(-1) << endl;
    // cout << dec2hex(0) << endl;
    // cout << (unsigned)-1 << endl;
    // cout << (1l << 32) << endl;
    return 0;
}
