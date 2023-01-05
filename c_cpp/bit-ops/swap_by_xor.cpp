#include <iostream>
using namespace std;

void swap(int &a, int &b) { a ^= b ^= a ^= b; }
int main(int argc, char const *argv[]) {
    int a = 1, b = 2;
    cout << a << b << endl;
    swap(a, b);
    cout << a << b << endl;
    return 0;
}
