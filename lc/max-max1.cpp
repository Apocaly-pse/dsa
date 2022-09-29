#include <iostream>
#include <vector>

using namespace std;

int test1(vector<int> &v)
{
    int m1 = -1, m2 = -1, idx = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] > m1)
        {
            m2 = m1;
            m1 = v[i];
            idx = i;
        } else if (v[i] > m2) {
            m2 = v[i];
        }
    }
    return m1>=m2*2?idx:-1;
}

int test2(vector<int> &v)
{
    int m1 = -1, m2 = -1, m3 = -1, idx = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] > m1)
        {
            m3 = m2;
            m2 = m1;
            m1 = v[i];
            idx = i;
        } else if (v[i] > m2) {
            m3 = m2;
            m2 = v[i];
        } else if (v[i] > m3) {
            m3 = v[i];
        }
    }
    cout<<m1<<m2<<m3;
    return m1>=m2+m3?idx:-1;
}

int test3(vector<int> &v)
{
    int m1 = INT_MAX, m2 = INT_MAX, idx = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] < m1)
        {
            m2 = m1;    
            m1 = v[i];
            idx = i;
        } else if (v[i] < m2) {
            m2 = v[i];
        } 
    }
    cout<<m1<<m2;
    return m1<=m2*2?idx:-1;
}


int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4,5,6,99};
    // cout<<test1(v)<<endl;
    // cout<<test2(v)<<endl;
    cout<<test3(v)<<endl;
    return 0;
}
