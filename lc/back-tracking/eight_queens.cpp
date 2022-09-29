#include <iostream>

using namespace std;

// 规定棋盘的大小（几皇后问题）
// const int N=8
#define N 8
int chessboard[N][N] = {};
// 定义解的数目
int solve_num = 0;


// 判断放置位置是否满足条件
bool check(int row, int col) {
    if (row == 0)
        return true;
    for (int i = 0; i != row; ++i) {
        if (chessboard[i][col] == 1)
            return false;   //每列(col)只能有一个棋子
    }
    for (int j = 0; j != col; ++j) {
        if (chessboard[row][j] == 1)
            return false;  //每行(row)只能有一个棋子
    }

    /*
    把i和j的值分别置为比当前棋子位置的值少一，即为左上角一格，
    i >= 0 && j >= 0;控制i和j在棋盘范围内，
    --i, --j表示向左上角移动
    */

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if (chessboard[i][j] == 1)
            return false;  //判断左上角是否有棋子
    }

    /*
    i的值为当前棋子的行值减一，j的值为当前棋子的列值加一，即为右上角一格，
    i >= 0 && j != N; 控制i和j在棋盘范围内，
    --i, ++j；向右上角移动
    */
    for (int i = row - 1, j = col + 1; i >= 0 && j != N; --i, ++j) {
        if (chessboard[i][j] == 1)
            return false; //判断右上角是否有棋子
    }
    //如果行、列和对角线都没有其他棋子，则返回true
    return true;
}

// 输出部分
void output() {
    int row, col;         //行，列
    ++solve_num;    //每次执行该输出函数，全局变量solve_num就会加一，代表解的数目加一
    cout << "Solution " << solve_num << ":" << endl;
    for (row = 0; row != N; ++row) {
        for (col = 0; col != N; ++col) {
            cout << chessboard[row][col] << " ";
        }
        cout << endl;
    }
}

// 递归实现 回溯法
void solve(int row) {
    for (int col = 0; col != N; ++col) {
        chessboard[row][col] = 1; //在第row行的其中一列放置皇后
        if (check(row, col) == true) { //检查放置皇后位置是否合法
            if (row == N - 1) {  //检查合法后，如该行已经是棋盘最后一行
                output();        //打印出该解法
            } else {                //如果不是最后一行
                solve(row + 1);//就继续判断下一行的皇后要放在哪个位置
            }
        }
        chessboard[row][col] = 0;//如检查不合法，就把放置的皇后撤走(即1变0)
    }
}

int main(int argc, char const *argv[]) {
    solve(0);
    return 0;
}