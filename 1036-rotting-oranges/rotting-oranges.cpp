class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, pair<int, int>>> Q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    Q.push({0, {i, j}});
                }
            } 
        }

        vector<int> nrow = {0, 1, 0, -1};
        vector<int> ncol = {1, 0, -1, 0};//right, down, left, top

        int minTime = 0;
        while(!Q.empty()) {
            pair<int, pair<int, int>> curr = Q.front();
            Q.pop();

            int tm = curr.first;
            minTime = max(minTime, tm);
            int crow = curr.second.first;
            int ccol = curr.second.second;

            for(int i = 0; i < 4; i++) {
                int row = crow + nrow[i];
                int col = ccol + ncol[i];

                if(row < n && row >= 0 && col < m && col >= 0 && grid[row][col] == 1) {
                    grid[row][col] = 2;
                    Q.push({tm+1, {row, col}});
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    minTime = -1;
                    break;
                } 
            } 
        }

        return minTime;   
    }
};