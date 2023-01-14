#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;
#define NUMBER 8
const int TARGET = 1000;
const double EPS = 1e-6;
const int N = 8;
struct item {
    double num; // 数字
    string cal; // 数字对应的字符形式
    bool flag;  // 表示是否用过该数字
};

item a[N];
// 交换结构体中两数
void swap(int i, int j) {
    item t;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> &mp) {
    os << "{";
    for (auto &p : mp) os << "<" << p.first << ": " << p.second << ">, ";
    return os << "}" << endl;
}

map<string, bool> mhash;
set<string> ans{};

bool push_map_check(int dep) {
    // 用于检查"某组数"是否使用过, 若用过就返回false,
    // 默认为false, 需要先初始化为true string s{};
    string s{};
    vector<int> tmp(dep);
    for (int i = 0; i < dep; i++) tmp[i] = a[i].num;
    // sort(tmp.begin(), tmp.end());
    for (int itm : tmp) s += to_string(itm) + ',';
    // cout << s << endl;
    if (!mhash[s]) {
        // 如果未使用过(或者未初始化, default=false), 标记为true
        mhash[s] = true;
        // cout << s << endl;
        return true;
    } else // 使用过就标记为false
        return false;
}

void search_ans(int dep) {
    if (dep == 1 && fabs(a[0].num - TARGET) < EPS) {
        // cout << a[0].cal << endl;
        ans.insert(a[0].cal);
        return;
    }
    // if (!push_map_check(dep)) return;
    // 用字典存左右操作数, 用于判断是否使用过
    map<int, int> hash;
    hash.clear(); // 每次都需要清空, 从这一组新的数开始计算
    for (int i = 0; i < dep; i++)
        for (int j = i + 1; j < dep; j++) {
            // 如果使用过就跳过
            if (hash[a[i].num] == a[j].num) continue;
            hash[a[i].num] = a[j].num;

            swap(j, dep - 1);
            item temp = a[i];

            //+
            a[i].num = a[i].num + a[dep - 1].num;
            a[i].flag = false; // 表示用过该数字
            a[i].cal = '(' + temp.cal + '+' + a[dep - 1].cal + ')';
            search_ans(dep - 1);
            a[i] = temp;

            //-1
            a[i].num = a[i].num - a[dep - 1].num;
            a[i].flag = false;
            a[i].cal = '(' + temp.cal + '-' + a[dep - 1].cal + ')';
            search_ans(dep - 1);
            a[i] = temp;
            //-2
            a[i].num = a[dep - 1].num - a[i].num;
            a[i].flag = false;
            a[i].cal = '(' + a[dep - 1].cal + '-' + temp.cal + ')';
            search_ans(dep - 1);
            a[i] = temp;

            //*
            a[i].num = a[i].num * a[dep - 1].num;
            a[i].flag = false;
            a[i].cal = '(' + temp.cal + '*' + a[dep - 1].cal + ')';
            search_ans(dep - 1);
            a[i] = temp;

            // /1
            if (a[dep - 1].num != 0) { //&& a[i].num % a[dep - 1].num == 0
                a[i].num = a[i].num / a[dep - 1].num;
                a[i].flag = false;
                a[i].cal = '(' + temp.cal + '/' + a[dep - 1].cal + ')';
                search_ans(dep - 1);
                a[i] = temp;
            }
            // /2
            if (a[i].num != 0) { //&& a[dep - 1].num % a[i].num == 0
                a[i].num = a[dep - 1].num / a[i].num;
                a[i].flag = false;
                a[i].cal = '(' + a[dep - 1].cal + '/' + temp.cal + ')';
                search_ans(dep - 1);
                a[i] = temp;
            }

            // 合并两个数:8 8->88
            // 由于每次操作(赋值)的是a[i],
            // 所以a[i].flag就蕴含了a[i].num==NUMBER
            // if (a[i].flag && a[dep - 1].flag && a[dep - 1].num == NUMBER) {
            if (a[i].flag && a[dep - 1].flag && a[dep - 1].num == NUMBER) {
                a[i].num = a[i].num * 10 + a[dep - 1].num;
                a[i].cal = temp.cal + a[dep - 1].cal;
                search_ans(dep - 1);
                a[i] = temp;
            }
            swap(dep - 1, j);
        }
}

int main() {
    // freopen("out.txt", "w", stdout);
    mhash.clear();
    for (int i = 0; i < N; i++) {
        a[i].num = NUMBER;
        a[i].cal = to_string(NUMBER);
        a[i].flag = true;
    }
    // a[0].num=8;
    // a[1].num=888;
    // a[2].num=8888;
    // a[0].cal=to_string(a[0].num);
    // a[1].cal=to_string(a[1].num);
    // a[2].cal=to_string(a[2].num);
    // a[0].flag=true;
    // a[1].flag=true;
    // a[2].flag=true;
    search_ans(N);
    // cout<<mhash;
    cout<<ans.size()<<endl;
    // for (auto s:ans)cout<<s<<endl;
    return 0;
}