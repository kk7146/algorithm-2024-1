#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> solutions;

bool isSafe(int row, int col, vector<string>& board, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

void solveNQueens(vector<string>& board, int row, int n) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solveNQueens(board, row + 1, n);
            board[row][col] = 'X';
        }
    }
}

bool compareSolutions(const vector<string>& a, const vector<string>& b) {
    for (int i = 0; i < a.size(); ++i) {
        int posA = a[i].find('Q');
        int posB = b[i].find('Q');
        if (posA != posB) {
            return posA < posB;
        }
    }
    return false;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<string> board(N, string(N, 'X'));
        solutions.clear();
        solveNQueens(board, 0, N);
        sort(solutions.begin(), solutions.end(), compareSolutions);
        if (!solutions.empty()) {
            for (auto &solution : solutions) {
                for (auto &row : solution) {
                    cout << row << endl;
                }
            }
			cout << endl;
        }
    }
    return 0;
}
