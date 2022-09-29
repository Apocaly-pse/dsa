#include<bits/stdc++.h>

using namespace std;
const int maxn = 10;
int map_q[maxn][maxn];
int x1[maxn], x2[maxn], ans, n;

bool check1(int xx, int yy) {
    if (!map_q[xx][yy])//表格中数据为0不可输入
        return false;
    for (int i = 0; i < xx; i++)//遍历行
    {
        if (yy == x1[i]) return false;//同一列
        if (abs(xx - i) == abs(yy - x1[i])) return false; //斜对角,4个斜对角的行列值都分别与该点的行列值差1
    }
    return true;
}

bool check2(int xx, int yy) {
    if (!map_q[xx][yy]) return false;
    for (int i = 0; i < xx; i++) {
        if (yy == x2[i]) return false;
        if (abs(xx - i) == abs(yy - x2[i])) return false; //斜对角
    }
    return true;
}

void queen(int l) {
    if (l == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (check1(l, i)) {
            x1[l] = i;
            map_q[l][i] = 0;
            for (int j = 0; j < n; j++) {
                if (check2(l, j)) {
                    x2[l] = j;
                    queen(l + 1);
                    x2[l] = -1;
                }
            }
            map_q[l][i] = 1;
            x1[l] = -1;
        }
    }
}

int main() {
    cin >> n;//n棋盘的大小
    //n行n列表格
    //如果整数为1，对应的位置可以放皇后，如果整数为 0，对应的位置不可以放皇后 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map_q[i][j];
    ans = 0;
    queen(0);
    cout << ans << endl;
    return 0;
}



