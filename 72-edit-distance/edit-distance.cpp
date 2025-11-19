class Solution {
public:
    //top-bottom memoization
    int calculate(string& word1, string& word2, int n, int m, vector<vector<int>>& dp) {
        if(m == 0) return dp[n][m] = n;
        if(n == 0) return dp[n][m] = m;

        if(dp[n][m] != -1) return dp[n][m];

        if(word1[n-1] == word2[m-1]) {
            dp[n][m] = 0 + calculate(word1, word2, n-1, m-1, dp);
        } else {
            int first = 1 + calculate(word1, word2, n, m-1, dp);
            int second = 1 + calculate(word1, word2, n-1, m, dp);
            int third = 1 + calculate(word1, word2, n-1, m-1, dp);

            dp[n][m] = min(first, min(second, third));
        }

        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
        // calculate(word1, word2, n, m, dp);

        for(int i = 1; i < n + 1; i++) {
            dp[i][0] = i;
        }
        for(int j = 1; j < m + 1; j++) {
            dp[0][j] = j;
        }

        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < m+1; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = 0 + dp[i-1][j-1];
                } else {
                    long long first = 1 + dp[i-1][j];
                    long long second = 1 + dp[i][j-1];
                    long long third = 1 + dp[i-1][j-1];
                    dp[i][j] = min(first, min(second, third));
                }
            }
        }

        for(int i = 0; i < n+1; i++) {
            for(int j = 0; j < m+1; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        
        return dp[n][m];
    }
};