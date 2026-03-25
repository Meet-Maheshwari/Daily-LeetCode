class Solution {
public:
    bool checkRowCols(int row, int col, int n, int m, vector<vector<int>>& mat) {
        for(int i = 0; i < n; i++) {
            if(i == row) continue;
            if(mat[i][col] == 1) return false;
        }

        for(int j = 0; j < m; j++) {
            if(j == col) continue;
            if(mat[row][j] == 1) return false;
        }

        return true;
    } 

    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1 && checkRowCols(i, j, n, m, mat)) cnt++;
            }
        }

        return cnt;
    }
};