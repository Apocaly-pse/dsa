#include<iostream>

using namespace std;


int climbStairs(int n) {
    if (n <= 3) return n;
    int a = 2, b = 3;
    for (int i = 3; i < n; i++) {
        int tmp = a;
        a = b;
        b += tmp;
    }
    return b;
}

int main() {
    cout << climbStairs(5);
    return 0;
}
