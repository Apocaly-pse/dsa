#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <gmp.h>
#include "gmpxx.h"

using namespace std;
void t1() { // Declare two arbitrary-precision integers
    mpz_t x, y;

    // Initialize the integers
    mpz_init(x);
    mpz_init(y);

    // Set the value of x to 1234567890
    mpz_set_str(x, "1234567890", 10);

    // Set the value of y to 9876543210
    mpz_set_str(y, "9876543210", 10);

    // Declare a third arbitrary-precision integer to store the result
    mpz_t result;
    mpz_init(result);

    // Perform the multiplication
    mpz_mul(result, x, y);

    // Print the result
    std::cout << "Result: " << result << std::endl;

    // Clear the variables to free memory
    mpz_clear(x);
    mpz_clear(y);
    mpz_clear(result);
}

void t2() {
    mpz_class t1, t2;
    t1 = "1277777777777777777777";
    t2 = "9999999999999999999";
    cout << t1 * t2;
}
int main(int argc, char const *argv[]) {
    t1();
    /* t2(); */
    return 0;
}
