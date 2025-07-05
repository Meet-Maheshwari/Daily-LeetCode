class Solution {
public:
    int minOperations(int n, int m, string w1, string w2, vector<vector<int>>& dp) {
        if(n == 0) return m;
        if(m == 0) return n;

        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        if(w1[n-1] == w2[m-1]) {
            dp[n][m] = 0 + minOperations(n-1, m-1, w1, w2, dp);
        } else {
            dp[n][m] = 1 + min(minOperations(n-1, m-1, w1, w2, dp), min(minOperations(n-1, m, w1, w2, dp), minOperations(n, m-1, w1, w2, dp)));
        }

        return dp[n][m];
    };

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return minOperations(n, m, word1, word2, dp);
    }
};