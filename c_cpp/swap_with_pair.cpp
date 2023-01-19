#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int a = 10, b = 20;
    cout << a << " " << b << endl;
    tie(a, b) = pair(b, a);
    cout << a << " " << b << endl;
    /*10 20
    20 10*/
    return 0;
}