#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto& i : v) os << i << " ";
    os << endl;
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    for (auto& ll : v) {
        os << ll;
        os << "\n";
    }
    os << endl;
    return os;
}

class Solution {
    vector<vector<string>> res{};
    bool isvaild(int row, int col, vector<string>& board, int n) {
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q') return false;
        for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;
        for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++)
            if (board[i][j] == 'Q') return false;
        return true;
    }
    void bt(int n, int row, vector<string> board) {
        if (row == n) {
            res.emplace_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isvaild(row, col, board, n)) {
                board[row][col] = 'Q';
                bt(n, row + 1, board);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        bt(n, 0, board);
        return res;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
    cout << s.solveNQueens(4);
    cout << s.solveNQueens(5);

    return 0;
}
