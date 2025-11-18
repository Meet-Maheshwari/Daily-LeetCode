class Solution {
public:
    int lcss(vector<int>& nums, vector<int>& sis, int n, int m, vector<vector<int>>& dp) {
        if(n == 0 || m == 0) {
            return dp[n][m] = 0;
        }

        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        if(nums[n-1] == sis[m-1]) {
            dp[n][m] = 1 + lcss(nums, sis, n-1, m-1, dp);
        } else {
            int left = lcss(nums, sis, n-1, m, dp);
            int right = lcss(nums, sis, n, m-1, dp);
            dp[n][m] = max(left, right);
        }

        return dp[n][m];
    }

    int lengthOfLIS(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> sis(s.begin(), s.end());
        sort(sis.begin(), sis.end());

        int n = nums.size(), m = sis.size();
        vector<vector<int>> dp (n+1, vector<int>(m+1, -1));

        lcss(nums, sis, n, m, dp);
        return dp[n][m];
    }
};