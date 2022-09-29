#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    for (int &i: asteroids) {
        if (i<0 || st.empty())
            st.push(i);// 向右移动,入栈
        else {//向左移动,判断
            int top1 = st.top();
            // if (top1<-i){
            //     st.pop();
            //     st.push(i);
            // } else if (top1>-i) {
            //     continue;
            // } else {
            //     st.pop();
            // }
            if (st.empty() || top1 <0)
            {
                st.push(i);
            } else {
                if (top1>i) {
                    continue;
                }
                while (!st.empty() && st.top()<=-i) {
                    st.pop();
                }
            }
        }
    }
    vector<int> ans;
    while (!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> v1={8,-8,2},v2={5,10,-5},v3={50,1,3,-5,9},v4={10,2,-5},v5={-2,-2,1,-2};
    auto ans = asteroidCollision(v5);
    for (auto &i:ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}



