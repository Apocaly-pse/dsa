#include <iostream>
using namespace std;

int mul(int a, int b) {
    int ans{};
    bool sgn = (a > 0) ^ (b > 0);
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) {
        if (b & 1) ans += a;
        a += a;
        b >>= 1;
    }
    return sgn ? -ans : ans;
}


int main(int argc, char *argv[]) {
    cout << mul(12, 23) << " " << 12 * 23 << endl;
    cout << mul(-12, -23) << " " << -12 * -23 << endl;
    cout << mul(12, -23) << " " << 12 * -23 << endl;
    cout << mul(-12, 23) << " " << -12 * 23 << endl;
    cout << mul(-12, 0) << " " << -12 * 0 << endl;
    return 0;
}
