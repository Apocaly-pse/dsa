#include <iostream>
#include <vector>
#include <typeinfo>
#include <gmp.h>
#include <gmpxx.h>
using namespace std;

ostream& operator<<(ostream& os, const vector<mpz_class> v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}

int find_nice(mpz_class R, mpz_class b) {
    int l{}, r{9}, mid{};
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if ((20 * b + mid) * mid > R)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l - 1;
}


mpz_class mySqrt(mpz_class n) {
    int i{};
    vector<mpz_class> a(105, 0), quot{};
    // Dividing the number into segments
    /* while (n) { */
    /*     a[i++] = n % 100; */
    /*     n /= 100; */
    /* } */
    i = 101;
    a[i - 1] = 5;
    /* cout << a; */

    mpz_class quotient, dividend, reminder, tmp;
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
    mpz_class m1, m2;
    cout << m2 << endl;
}
void t2() {
    mpz_class n;
    n = "500000000000000";
    cout << mySqrt(n) << endl; // 22
    /* cout << mySqrt("839") << endl;  // 28 */
    /* cout << mySqrt("1009") << endl; // 31 */
    /* cout << mySqrt("500000000000000") << endl; */
    /* 2 2 3 6 0 6 7 9 */
    /* 22360679 */
}

int main(int argc, char const* argv[]) {
    /* t0(); */
    /* t1(); */
    t2();
    return 0;
}
