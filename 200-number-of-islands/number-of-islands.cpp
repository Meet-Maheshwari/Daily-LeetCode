class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); //rows
        int m = grid[0].size(); // cols
        
        vector<int>rows = {1, 0, -1, 0};
        vector<int>cols = {0, 1, 0, -1};
        
        queue<pair<int, int>> Q;
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    grid[i][j] == '0';
                    Q.push({i, j});

                    while(!Q.empty()) {
                        int crow = Q.front().first, ccol = Q.front().second;
                        Q.pop();

                        for(int k = 0; k < 4; k++) {
                            int row = crow + rows[k];
                            int col = ccol + cols[k];

                            if(row < n && row >= 0 && col < m && col >= 0) {
                                if(grid[row][col] == '1') {
                                    grid[row][col] = '0';
                                    Q.push({row, col});
                                }
                            }
                        }
                    }
                    count++;
                }
            }
        }

        return count;
    }
};