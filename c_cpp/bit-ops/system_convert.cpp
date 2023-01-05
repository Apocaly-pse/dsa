#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string dec2x(int x, int k) {
    string ans{};
    while (x) {
        ans = to_string(x % k) + ans;
        x /= k;
    }
    return ans;
}

int x2dec(string x, int k) {
    int ans{}, n = x.size();
    for (int i{}; i < n; ++i)
        ans += (static_cast<int>(x[n - 1 - i]) - 48) * pow(k, i);
    return ans;
}


int main(int argc, char const *argv[]) {
    cout << dec2x(21, 3) << endl;
    cout << x2dec("210", 3) << endl;
    return 0;
}