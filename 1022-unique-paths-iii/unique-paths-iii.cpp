class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int count) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1 || grid[i][j] == 3) {
            return 0;
        }
        
        if(count == 0 && grid[i][j] == 2) {
            return 1;
        }
        if(count != 0 && grid[i][j] == 2) {
            return 0;
        }
        
        if(grid[i][j] == 0) {
            count--;
        }
        grid[i][j] = 3;

        int bottom = dfs(i+1, j, grid, count);
        int top = dfs(i-1, j, grid, count);
        int right = dfs(i, j+1, grid, count);
        int left = dfs(i, j-1, grid, count);

        count++;
        grid[i][j] = 0;

        return bottom+top+right+left;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int count = 0, row = 0, col = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    row = i; col = j;
                }
                if(grid[i][j] == 0) count++;
            }
        }

        return dfs(row, col, grid, count);      
    }
};