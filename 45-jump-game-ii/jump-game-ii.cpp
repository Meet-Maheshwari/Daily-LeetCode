class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;

        for (int idx = n - 2; idx >= 0; idx--) {
            int steps = nums[idx];
            for (int j = 1; j <= steps && idx + j < n; j++) {
                if (dp[idx + j] != INT_MAX) {
                    dp[idx] = min(dp[idx], 1 + dp[idx + j]);
                }
            }
        }

        return dp[0];
    }
};