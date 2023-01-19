#include <iostream>
#include <vector>
#include <iomanip>
#include <typeinfo>
using namespace std;

ostream& operator<<(ostream& os, const vector<int> v) {
    for (int i : v) os << i << " ";
    return os << endl;
}

int find_nice(long long R, long long b = 0) {
    int l{}, r{9};
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if ((20 * b + mid) * mid > R)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l - 1;
}


long long mySqrt(long long n) {
    long long dividend{}, quotient{}, reminder{};
    int i{};
    vector<int> a(15, 0), quot{};
    // Dividing the number into segments
    while (n) {
        a[i++] = n % 100;
        n /= 100;
    }
    // i = 10;
    // a[i - 1] = 5;
    cout << a;
    for (int j = i - 1; j >= 0; --j) {
        dividend = reminder * 100 + a[j]; // update dividend
        int tmp = find_nice(dividend, quotient);
        quot.emplace_back(tmp);
        reminder = dividend - (20 * quotient + tmp) * tmp;
        quotient = quotient * 10 + tmp;
        // cout << quotient << typeid(tmp).name() << endl;
    }
    cout << quot;
    return quotient;
}

void t1() {
    cout << mySqrt(500) << endl;  // 22
    cout << mySqrt(839) << endl;  // 28
    cout << mySqrt(1009) << endl; // 31
}
void t2() {
    cout << mySqrt(5000000000000000000LL) << endl;
/*    2 2 3 6 0 6 7 9
    22360679
*/}

int main(int argc, char const* argv[]) {
    // t1();
    t2();
    return 0;
}
