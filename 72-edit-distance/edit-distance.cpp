class Solution {
public:
    // int minOperations(int n, int m, string w1, string w2, vector<vector<int>>& dp) {
    //     if(n == 0) return m;
    //     if(m == 0) return n;

    //     if(dp[n][m] != -1) {
    //         return dp[n][m];
    //     }

    //     if(w1[n-1] == w2[m-1]) {
    //         dp[n][m] = 0 + minOperations(n-1, m-1, w1, w2, dp);
    //     } else {
    //         dp[n][m] = 1 + min(minOperations(n-1, m-1, w1, w2, dp), min(minOperations(n-1, m, w1, w2, dp), minOperations(n, m-1, w1, w2, dp)));
    //     }

    //     return dp[n][m];
    // };

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m+1, 0);

        for(int j = 1; j < m+1; j++) {
            prev[j] = j;
        }

        for(int i = 1; i < n+1; i++) {
            vector<int> dp(m+1, 0);
            dp[0] = i;
            for(int j = 1; j < m+1; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[j] = 0 + prev[j-1];
                } else {
                    dp[j] = 1 + min(prev[j-1], min(prev[j], dp[j-1]));
                }
            }
            prev = dp;
        }

        return prev[m];
    }
};