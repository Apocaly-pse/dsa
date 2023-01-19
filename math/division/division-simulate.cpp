#include <iostream>
using namespace std;

int find_nice(int R, int b) {
    int l{}, r{9};
    while (l <= r) {
        int mid = (r + l) >> 1;
        if (b * mid > R)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l - 1;
}
void t1() {
    cout << find_nice(12, 9) << endl;
    cout << find_nice(12, 90) << endl;
}

int division(int dividend, int divisor) {
    //
    int reminder{dividend};
    while (reminder) { while }
    return divisor;
}


void t2() {
    cout << division(231, 12) << endl;
    cout << division(231, 14) << endl;
}
int main(int argc, char const *argv[]) {
    // t1();
    t2();
    return 0;
}
