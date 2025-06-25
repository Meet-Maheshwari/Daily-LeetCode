class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> Q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    Q.push(make_pair(make_pair(i, j), 0));
                }
            }
        }

        vector<int> nrow = {-1, 0, 1, 0};
        vector<int> ncol = {0, 1, 0, -1};

        int tm = 0;
        while(!Q.empty()) {
            pair<pair<int, int>, int> curr = Q.front();
            Q.pop();

            int row = curr.first.first;
            int col = curr.first.second;
            int t = curr.second;
            tm = max(tm, t);

            for(int i = 0; i < 4; i++) {
                int n_row = row + nrow[i];
                int n_col = col + ncol[i];

                if(n_row >= 0 && n_row < n && n_col >= 0 && n_col < m && grid[n_row][n_col] == 1) {
                    grid[n_row][n_col] = 2;
                    Q.push(make_pair(make_pair(n_row, n_col), t+1));
                }
            }
        }

        bool remaining = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    remaining = true;
                    break;
                }
            }
        }

        return remaining == true ? -1 : tm;
    }
};