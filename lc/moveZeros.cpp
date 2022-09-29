#include <iostream>
#include <vector>
#include <string>
// #include <algorithm>

// #include <cmath>

using namespace std;

// int test(string s)
// {
//     // string<char> arr(10,1);
//     // cout<<arr[1];
//     // char a = 65;

//     // cout << a << endl;
//     // printf("%s\n", &a);
//     int n = 0, m = 0;
//     for (int i = s.size() - 1; i >= 0; i--)
//     {
//         m = (int)s[s.size()-1-i] - 64;
//         n += m * pow(26, i);
//     }
//     return n;
// }

// void moveZeroes(vector<int> &v) {
//     vector<int> nonzero;
//     int znum=0;
//     for (auto it=v.begin();it!=v.end();it++) {
//         if (*it)
//             nonzero.push_back(*it);
//         else
//             znum++;
//     }
//     while(znum--)
//         nonzero.push_back(0);
//     v=nonzero;
// }

// void moveZeroes(vector<int> &v) {
//     int n=v.size(),a=0,cur=0;
//     while (a<n) {
//         if (v[a]) {
//             // znum++;
//             v[cur++]=v[a];
//         }
//         a++;
//     }
//     for (;cur<n;cur++)
//         v[cur]=0;
// }

void moveZeroes(vector<int> &v) {
    int n=v.size(),a=0,b=0;
    while (b<n) {
        if (v[b]) {
            swap(v[a],v[b]);
            a++;
        }
        b++;
    }
}

int main(int argc, char const *argv[]) {
    // string s;
    // s = "AB";
    // // s = "ZY";
    // cout << test(s) << endl;
    // int arr[] = {1, 0, 0, 1, 9, 0};
    // int arr[] = {1, 0, 0, 1, 9, 0};
    // int arr[] = {1, 0, 0, 1, 9, 0};
    // int arr[] = {0,1,0,3,12};
    vector<int> a={0,1,0,3,12,0};
    moveZeroes(a);
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    return 0;
}
