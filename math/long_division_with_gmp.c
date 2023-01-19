#include <cstring>
#include <iostream>
#include <vector>
#include <iomanip>
#include <typeinfo>
#include <cstdio>
#include <cstdlib>
#include <gmp.h>
#include <gmpxx.h>
using namespace std;

ostream& operator<<(ostream& os, const vector<int> v) {
    for (auto i : v) os << i << " ";
    return os << endl;
}

int find_nice(mpz_t R, mpz_t b) {
    int l{}, r{9}, mid{};
    mpz_t tmp;
    mpz_init(tmp);
    while (l <= r) {
        mid = (l + r) >> 2;
        mpz_mul_ui(tmp, b, 20);
        mpz_add_ui(tmp, tmp, mid);
        mpz_mul_ui(tmp, tmp, mid);
        if (mpz_cmp(tmp, R) > 0)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l - 1;
}
void t0() {
    mpz_t m1, m2;
    mpz_init_set_str(m1, "100", 10);
    mpz_init_set_str(m2, "2", 10);
    /* cout << mpz_cmp(m1, m2) << endl; */
    cout << find_nice(m1, m2);
}


char* mySqrt(char* s) {
    mpz_t n, mod;
    mpz_init(mod);
    mpz_init_set_str(n, s, 10);
    int i{};
    int a[100];
    memset(a, 0, 100);
    // Dividing the number into segments
    while (mpz_cmp_ui(n, 0)) {
        mpz_mod_ui(mod, n, 100);
        a[i++] = mpz_get_ui(mod);
        mpz_div_ui(n, n, 100);
    }
    // i = 10;
    // a[i - 1] = 5;
    /* cout << a; */

    mpz_t quotient, dividend, reminder, tmp;
    mpz_inits(quotient, dividend, reminder, tmp, NULL);
    for (int j = i - 1; j >= 0; --j) {
        mpz_mul_ui(tmp, reminder, 100);
        mpz_add_ui(dividend, tmp, a[j]);
        int nice = find_nice(dividend, quotient);
        /* quot.emplace_back(nice); */
        mpz_mul_ui(tmp, quotient, 20);
        mpz_add_ui(tmp, tmp, nice);
        mpz_mul_ui(tmp, tmp, nice);
        mpz_sub(reminder, dividend, tmp);
        // update quotient
        mpz_mul_ui(tmp, quotient, 10);
        mpz_add_ui(quotient, tmp, nice);
    }
    /* cout << quot; */
    char* ans{};
    mpz_get_str(ans, 10, quotient);
    printf(ans);
    return ans;
}

void t1() {
    mpz_t m1, m2;
    mpz_inits(m1, m2, NULL);
    mpz_init_set_str(m1, "100", 10);
    cout << m2 << endl;
}
void t2() {
    printf("%s\n", mySqrt("500"));
    /* cout << mySqrt("500") << endl; // 22 */
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
