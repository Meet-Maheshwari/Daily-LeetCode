class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> Q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    mat[i][j] = INT_MAX;
                } else {
                    Q.push({i, j});
                }
            }
        }

        vector<int> rows = {1, 0, -1, 0};
        vector<int> cols = {0, 1, 0, -1};

        while(!Q.empty()) {
            auto [i, j] = Q.front();
            Q.pop();

            for(int k = 0; k < 4; k++) {
                int nrow = i + rows[k];
                int ncol = j + cols[k];

                if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0) {
                    if(mat[nrow][ncol] > mat[i][j] + 1) {
                        mat[nrow][ncol] = mat[i][j] + 1;
                        Q.push({nrow, ncol});
                    }
                }
            }
        }

        return mat;
    }
};