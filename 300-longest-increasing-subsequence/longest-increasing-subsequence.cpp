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
        vector<vector<int>> dp (n+1, vector<int>(m+1, 0));

        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < m+1; j++) {
                if(nums[i-1] == sis[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};