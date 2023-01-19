#include <iostream>
using namespace std;

string dec2bin(int x) {
    string ans{};
    int tmp{};
    for (int j = 31; j >= 0; --j)
        if ((tmp = x & (1 << j)) || !ans.empty()) ans += tmp ? "1" : "0";
    return ans;
}

string dec2hex(int x) {
    string ans{};
    int tmp{};
    for (int j = 7; j >= 0; j--) {
        tmp = 0xf & (x >> (4 * j));
        if (!ans.empty() || tmp) ans += tmp > 9 ? tmp + 87 : tmp + 48;
    }
    return ans.empty() ? "0" : ans;
}

void t1() {
    cout << dec2hex(-1) << endl;
    cout << dec2hex(26) << endl;
    cout << dec2hex(16) << endl;
    cout << dec2hex(0) << endl;
}

int main(int argc, char const *argv[]) {
    cout << dec2bin(-1) << endl;
    cout << dec2bin(11) << endl;
    cout << dec2bin(16) << endl;
    cout << dec2bin(18) << endl;
    return 0;
}
