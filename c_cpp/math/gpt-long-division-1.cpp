#include <iostream>

int main() {
    int number;
    std::cin >> number;

    int divisor = 1;
    int quotient = number;
    int remainder = 0;
    int digit = 0;

    while (quotient > 0) {
        // Calculate the next digit of the root
        digit = quotient / divisor;

        // Update the remainder and quotient
        remainder = quotient % divisor;
        quotient = (remainder * 100) / divisor;

        // Update the divisor
        divisor = (divisor * 100) + remainder;

        // Output the digit
        std::cout << digit;
    }

    return 0;
}
