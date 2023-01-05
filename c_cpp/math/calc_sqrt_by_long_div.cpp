// C++ program to find the square root of a
// number by using long division method

#include <cstdint>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

ostream& operator<<(ostream& os, const vector<int> v) {
    for (int i : v) os << i << " ";
    return os << endl;
}
// Function to find the square root of
// a number by using long division method
int sqrtByLongDivision(int n) {
    int i = 0, udigit, j; // Loop counters
    int cur_divisor = 0;
    int quotient_units_digit = 0;
    int cur_quotient = 0;
    int cur_dividend = 0;
    int cur_remainder = 0;
    vector<int> a(20, 0);
    // Dividing the number into segments
    while (n > 0) {
        a[i] = n % 100;
        n /= 100;
        i++;
    }
    cout << a;
    // cout << i << endl;
    // a[17] = 3;
    // i = 18;
    // cout << a;
    // Last index of the array of segments
    i--;

    // Start long division from the last segment(j=i)
    for (j = i; j >= 0; j--) {
        // Initialising the remainder to the maximum value
        cur_remainder = INT32_MAX;
        // Including the next segment in new dividend
        cur_dividend = cur_dividend * 100 + a[j];

        // Loop to check for the perfect square
        // closest to each segment
        for (udigit = 0; udigit <= 9; udigit++) {
            // This condition is to find the
            // divisor after adding a digit
            // in the range 0 to 9
            if (cur_remainder >=
                    cur_dividend - ((cur_divisor * 10 + udigit) * udigit) &&
                cur_dividend >= ((cur_divisor * 10 + udigit) * udigit)) {
                // Calculating the remainder
                cur_remainder =
                    cur_dividend - ((cur_divisor * 10 + udigit) * udigit);
                // Updating the units digit of the quotient
                quotient_units_digit = udigit;
            }
        }
        // Adding units digit to the quotient
        cur_quotient = cur_quotient * 10 + quotient_units_digit;
        // cout << cur_quotient << endl;
        cout << fixed << setprecision(0) << cur_quotient << endl;
        // New divisor is two times quotient
        cur_divisor = cur_quotient * 2;
        // Including the remainder in new dividend
        cur_dividend = cur_remainder;
    }
    return cur_quotient;
}

// Driver code
int main() {
    int x = 300000000;
    cout << fixed << setprecision(100) << sqrt(3) << endl;
    cout << "sqrt of " << x << " is " << sqrtByLongDivision(x) << endl;
    return 0;
}
