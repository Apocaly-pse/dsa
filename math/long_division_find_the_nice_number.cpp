#include <iostream>
using namespace std;

int find_nice(int R, int b = 0) {
    int l{}, r{9};
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if ((20 * b + mid) * mid > R)
            r = mid - 1;
        else
            l = mid + 1;
        // cout << l << " " << r << endl;
    }
    return l - 1;
}
int find_isqrt(int x) {
    /* 0<=x<=99 */
    int l{}, r{9};
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (mid * mid > x)
            r = mid - 1;
        else
            l = mid + 1;
        // cout << l << " " << r << endl;
    }
    return l - 1;
}

void t1() { //
    cout << find_nice(2, 83) << endl;
    cout << find_nice(2, 100) << endl;
}

void t2() {
    cout << find_nice(4) << endl;
    cout << find_nice(39) << endl;
    cout << find_nice(99) << endl;
    cout << find_nice(89) << endl;
}
int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}