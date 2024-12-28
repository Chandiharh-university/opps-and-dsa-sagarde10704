#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void solveNQueensUtil(vector<string>& board, int row, int n, int& count) {
    if (row == n) {
        count++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueensUtil(board, row + 1, n, count);
            board[row][col] = '.';
        }
    }
}

int totalNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    int count = 0;
    solveNQueensUtil(board, 0, n, count);
    return count;
}

int main() {
    int n = 4;
    cout << "Number of distinct solutions to the " << n << "-queens puzzle: " << totalNQueens(n) << endl;
    return 0;
}
