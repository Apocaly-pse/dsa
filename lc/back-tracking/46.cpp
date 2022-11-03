#include <iostream>
#include <vector>
#include <cstring>
#include <functional>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v) {
    for (auto& i : v) os << i << " ";
    os << endl;
    return os;
}

ostream& operator<<(ostream& os, const vector<vector<int>>& v) {
    for (auto& ll : v) {
        for (auto& i : ll) os << i << " ";
        os << "\n";
    }
    os << endl;
    return os;
}


// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         int ns = nums.size(), i{};
//         vector<int> path{};
//         vector<bool> used(ns, false);
//         // bool used[ns];
//         // memset(used, false, ns);

//         vector<vector<int>> ans{};
//         function<void(void)> f = [&](void) {
//             cout << path;
//             cout << ans;
//             if (path.size() == ns) {
//                 ans.emplace_back(path);
//                 return;
//             }
//             for (i = 0; i < ns; i++) {
//                 if (used[i]) continue;
//                 path.push_back(nums[i]);
//                 cout << path;
//                 used[i] = true;
//                 f();
//                 path.pop_back();
//                 used[i] = false;
//             }
//         };
//         f();
//         return ans;
//     }
// };


class Solution {
public:
    // void f(void) {}
    vector<vector<int>> permute(vector<int>& nums) {
        int ns = nums.size(), i = 0;
        cout << "func()  i=" << i << endl;
        vector<int> path{};
        vector<vector<int>> ans{};
        vector<bool> used(ns, false);
        function<void(void)> f = [&]() {
            cout << "lambda() first i=" << i << endl;
            if (path.size() == ns) {
                ans.emplace_back(path);
                return;
            }
            for (i = 0; i < ns; i++) {
                cout << "loop first i=" << i << endl;
                if (used[i]) continue;
                path.emplace_back(nums[i]);
                used[i] = true;
                f();
                cout << "after recur, path=" << path;
                path.pop_back();
                used[i] = false;
                cout << "loop last i=" << i << endl;
            }
            cout << "lambda() last i=" << i << endl;
        };
        f();
        cout << "last func() i=" << i << endl;
        return ans;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> v1 = {1, 2, 3};
    cout << s.permute(v1) << endl;
    return 0;
}