#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int find_max(vector<int> &v) {
    int ans = INT_MIN;
    for (int i : v)
        if (ans < i) ans = i;
    return ans;
}

int find_2max(vector<int> &v) {
    int mx = INT_MIN, mmx = mx;
    for (int i : v)
        if (i > mx)
            mmx = mx, mx = i;
        else if (i > mmx)
            mmx = i;
    return mmx;
}

int find_3max(vector<int> &v) {
    int mx = INT_MIN, mmx = mx, mmmx = mx;
    for (int i : v)
        if (i > mx)
            mmmx = mmx, mmx = mx, mx = i;
        else if (i > mmx)
            mmmx = mmx, mmx = i;
        else if (i > mmmx)
            mmmx = i;
    return mmmx;
}
void t1() {
    vector<int> v = {3, 2, 5, 4, 1, 6, 9};
    cout << find_max(v) << endl;
    cout << find_2max(v) << endl;
    cout << find_3max(v) << endl;
}
void t2() {
    int a = 10, b = 11;
    cout << my_max(a, b) << endl;
    cout << my_min(a, b) << endl;
}

int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}
