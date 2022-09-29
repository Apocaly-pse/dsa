#include<bits/stdc++.h>
using namespace std;

int minStartValue(vector<int>& nums) {
    int startVal = nums[0] >= 1 ? 1 : 1 - nums[0];
    int tmp = nums[0] + startVal;
    for (int i = 1; i < nums.size(); ++i) {
        tmp += nums[i];
        if (tmp < 1) {
            startVal += 1 - tmp;
            tmp += 1 - tmp;
        }
        // printf("%d,%d\n", tmp, startVal);
    }
    return startVal;
}
void t1() {

    vector<int> a{ -4, 2, -9, 4, 2}, b{2, 3, 5, -5, -1};
    cout << minStartValue(b) << endl;
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}


