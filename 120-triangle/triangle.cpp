class Solution {
public:
    int findMinSum(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(i == n-1) return triangle[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int down = findMinSum(i+1, j, n, triangle, dp);
        int diag = findMinSum(i+1, j+1,n, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return findMinSum(0, 0, n, triangle, dp);
    }
};