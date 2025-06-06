class Solution {
public:
    int robHelper(vector<int> nums, int n, vector<int>& dp) {
        if(n <= 0) {
            return 0;
        }
        
        if(dp[n] != -1) {
            return dp[n];
        }
        //rob   
        int ans1 = nums[n-1] + robHelper(nums, n-2, dp);

        //don't rob
        int ans2 = robHelper(nums, n-1, dp);

        dp[n] = max(ans1, ans2);
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1, -1);
        // robHelper(nums, n, dp); By memoization

        //Tabulation + Constant space
       int neg = 0, prev1 = nums[0], prev2 = 0;

        for(int i = 1; i < n; i++) {
            //pick
            int rob = nums[i] + prev2;

            //Don't pick
            int noRob = 0 + prev1;

            prev2 = prev1;
            prev1 = max(rob, noRob);

        }
        return prev1;
    }
};













