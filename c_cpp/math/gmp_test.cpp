#include <iostream>
#include "gmp.h"

int main() {
    mpz_t x, y, z;
    mpz_init(x);
    mpz_init(y);
    mpz_init(z);

    // Assign values to x and y
    mpz_set_str(x, "12345678901234567890", 10);
    mpz_set_str(y, "98765432109876543210", 10);

    // Perform arithmetic operations
    mpz_add(z, x, y);
    std::cout << "x + y = " << z << std::endl;
    mpz_sub(z, x, y);
    std::cout << "x - y = " << z << std::endl;
    mpz_mul(z, x, y);
    std::cout << "x * y = " << z << std::endl;
    mpz_cdiv_q(z, x, y);
    std::cout << "x / y = " << z << std::endl;
    mpz_mod(z, x, y);
    std::cout << "x % y = " << z << std::endl;

    // Clear variables
    mpz_clear(x);
    mpz_clear(y);
    mpz_clear(z);

    return 0;
}
