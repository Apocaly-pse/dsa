#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

vector<int> lookup(100, -1);
// basic recur
int f1(int n) {
    if (n <= 1) return n;
    return f1(n - 1) + f1(n - 2);
}

// Memoization (Top Down)
int f2(int n) {
    if (lookup[n] == -1) {
        if (n <= 1)
            lookup[n] = n;
        else
            lookup[n] = f2(n - 1) + f2(n - 2);
    }
    return lookup[n];
}
// Tabulation (Bottom Up)
int f3(int n) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// rolling array
int f4(int n) {
    int a = 0, b = 1;
    // 需要同时更新
    /* for (int i = 2; i <= n; ++i) tie(a, b) = pair{b, a + b}; */
    for (int i = 2; i <= n; ++i) {
        int tmp = b;
        b += a;
        a = tmp;
    }
    return b;
}

void t1() {
    const int N = 20;
    cout << f1(N) << endl; // 34
    cout << f2(N) << endl;
    cout << f3(N) << endl;
    cout << f4(N) << endl;
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}
