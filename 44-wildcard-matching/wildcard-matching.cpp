class Solution {
public:
    bool solve(string& t, string& p, int n, int m, vector<vector<int>>& dp) {
        if(n == 0 && m == 0) return dp[n][m] = 1;
        if(m == 0) return dp[n][m] = 0;
        if(n == 0) {    
            for(int i = 0; i < m; i++) {
                if(p[i] != '*') return dp[n][m] = 0; 
            }
            return dp[n][m] = 1;
        } 

        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        if(p[m-1] == '*') {
            bool match = solve(t, p, n, m-1, dp);
            bool nomatch = solve(t, p, n-1, m, dp);
            dp[n][m] = match || nomatch;

        } else if(p[m-1] == '?') {
            dp[n][m] = solve(t, p, n-1, m-1, dp);
        } else if(p[m-1] == t[n-1]) {
            dp[n][m] = solve(t, p, n-1, m-1, dp);
        } else {
            dp[n][m] = 0;
        }

        return dp[n][m];
    }

    bool isMatch(string t, string p) {
        int n = t.size();
        int m = p.size();
        vector<vector<int>> dp (n+1, vector<int>(m+1, -1));

        dp[0][0] = 1;

        for(int j = 1; j < m+1; j++) {
            if(p[j-1] == '*' && dp[0][j-1] == 1) {
                dp[0][j] = 1;
            } else {
                dp[0][j] = 0;
            }
        }

        for(int i = 1; i < n+1; i++) {
            dp[i][0] = 0;
        }


        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < m+1; j++) {
                if(p[j-1] == t[i-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                } else if(p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[n][m];
    }
};