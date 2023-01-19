#include <iostream>
#include <cmath>

double long_division_sqrt(double x) {
    if (x < 0) { return NAN; }
    if (x == 0) { return 0; }

    double result = 0;
    double divisor = x;
    double dividend = 1;
    double precision = 1e-9;

    while (fabs(divisor - result) > precision) {
        result = divisor;
        divisor = (dividend + divisor) / 2;
        dividend = x / divisor;
    }

    return divisor;
}

int main() {
    std::cout << long_division_sqrt(2) << std::endl;
    std::cout << long_division_sqrt(4) << std::endl;
    std::cout << long_division_sqrt(9) << std::endl;
    std::cout << long_division_sqrt(16) << std::endl;
    std::cout << long_division_sqrt(50000) << std::endl;

    return 0;
}
