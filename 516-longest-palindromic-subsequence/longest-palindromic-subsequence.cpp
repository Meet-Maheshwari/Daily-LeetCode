class Solution {
public:
    int findLen(string& text1, string& text2, int n, int m, vector<vector<int>> &dp) {
        if(n == 0 || m == 0) return 0;

        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        if(text1[n-1] == text2[m-1]) {
            dp[n][m] = 1 + findLen(text1, text2, n-1, m-1, dp); 
        } else {
            int left = findLen(text1, text2, n-1, m, dp);
            int right = findLen(text1, text2, n, m-1, dp);
            dp[n][m] = max(left, right);
        }

        return dp[n][m];
    }

    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        int n = s.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return findLen(s, r, n, n, dp);
    }
};