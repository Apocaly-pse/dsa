#include<iostream>
#include<cmath>

using namespace std;
double map[8][8], sum = 0, msum = 0;

int Queenes[8] = {0}, Counts = 0;

void print() {
    sum = 0;
    for (int i = 0; i < 8; i++) {
        sum += map[i][Queenes[i]];
    }
    if (sum > msum)msum = sum;
}

int Check(int line, int list) {
    for (int i = 0; i < line; i++) { //遍历该行之前的所有行
        int data = Queenes[i];//挨个取出前面行中皇后所在位置的列坐标
        if (list == data)//如果在同一列，该位置不能放
            return 0;
        if ((i + data) == (line + list))//如果当前位置的斜上方有皇后，在一条斜线上，也不行
            return 0;
        if ((i - data) == (line - list))//如果当前位置的斜下方有皇后，在一条斜线上，也不行
            return 0;
    }
    return 1;//如果以上情况都不是，当前位置就可以放皇后
}

void eight_queen(int line) {
    for (int list = 0; list < 8; list++) { //在数组中为0-7列
        if (Check(line, list)) { //对于固定的行列，检查是否和之前的皇后位置冲突
            Queenes[line] = list;//不冲突，以行为下标的数组位置记录列数
            if (line == 7) { //如果最后一样也不冲突，证明为一个正确的摆法
                print();//输出这个摆法
                Queenes[line] = 0;//每次成功，都要将数组重归为0
                return;
            }
            eight_queen(line + 1);//继续判断下一样皇后的摆法，递归
            Queenes[line] = 0;//不管成功失败，该位置都要重新归0，以便重复使用
        }
    }
}

int main() {
    int k;//k个棋盘
    cin >> k;
    while (k--) {
        msum = 0, sum = 0;
        for (int i = 0; i < 8; i++) { //每个棋盘有64个数字，分成8行8列输入
            for (int j = 0; j < 8; j++)
                cin >> map[i][j];
        }
        eight_queen(0);
        cout << msum << endl;
    }
    return 0;
}
