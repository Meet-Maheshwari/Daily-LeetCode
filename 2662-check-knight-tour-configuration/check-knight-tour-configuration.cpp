class Solution {
public:
    bool travel(int step, int col, int row, vector<vector<int>>& grid) {
        int n = grid.size();

        if(row < 0 || row  >= n || col < 0 || col >= n || step != grid[row][col]) {
            return false;
        }

        if(step == n*n-1 && grid[row][col] == n*n-1) {
            return true;
        }

        if(step == grid[row][col]) {
            int ans1 = travel(step+1, col+1, row-2, grid);
            int ans2 = travel(step+1, col+2, row-1, grid);
            int ans3 = travel(step+1, col+2, row+1, grid);
            int ans4 = travel(step+1, col+1, row+2, grid);
            int ans5 = travel(step+1, col-1, row+2, grid);
            int ans6 = travel(step+1, col-2, row+1, grid);
            int ans7 = travel(step+1, col-2, row-1, grid);
            int ans8 = travel(step+1, col-1, row-2, grid);

            return ans1 || ans2 ||ans3 ||ans4 ||ans5 ||ans6 ||ans7 ||ans8;
        }
        return false;
    }
 
    bool checkValidGrid(vector<vector<int>>& grid) {    
        return travel(0, 0, 0, grid);
    }
};