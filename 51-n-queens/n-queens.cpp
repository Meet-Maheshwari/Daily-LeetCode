class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board) {
        int n = board.size();

        //check row
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        //check col
        for(int j = 0; j < col; j++) {
            if(board[row][j] == 'Q') {
                return false;
            }
        }

        //check left diagonal
        for(int i = row - 1, j = col-1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        //check right diagonal
        for(int i = row - 1, j = col+1; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void arrangeQueens(int row, vector<string>& board, vector<vector<string>>& ans) {
        int n = board.size();
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(isSafe(row, i, board)) {
                board[row][i] = 'Q';
                arrangeQueens(row+1, board, ans);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        arrangeQueens(0, board, ans);
        return ans;
    }
};