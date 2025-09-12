class Solution {
public:
    bool isSafe(char num, int row, int col, vector<vector<char>>& board) {
        //safe logic
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == num) {
                return false;
            }
        }

        for(int j = 0; j < 9; j++) {
            if(board[row][j] == num) {
                return false;
            }
        }

        int sr = (row/3)*3;
        int sc = (col/3)*3;

        for(int i = sr; i < sr+3; i++) {
            for(int j = sc; j < sc+3; j++) {
                if(board[i][j] == num) {
                    return false;
                }
            }
        }        

        return true;
    }

    bool sudokoSolver(int row, int col, vector<vector<char>>& board) {
        if(row == 9) {
            return true;
        }

        int nextRow = row;
        int nextCol = col+1;
        if(nextCol == 9) {
            nextCol = 0;
            nextRow = row+1;
        }

        if(board[row][col] != '.') {
            //call next
            return sudokoSolver(nextRow, nextCol, board);
        }

        for(int num = '1'; num <= '9'; num++) {
            if(isSafe(num, row, col, board)) {
                board[row][col] = num;
                if(sudokoSolver(nextRow, nextCol, board)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        sudokoSolver(0, 0, board);
    }
};