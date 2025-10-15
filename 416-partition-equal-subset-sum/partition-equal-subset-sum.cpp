class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) return false;
        int target = sum / 2;

        vector<vector<bool>> dp(n+1, vector<bool> (target+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < target+1; j++) {
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][target];
    }
};